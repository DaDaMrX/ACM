/*
POJ 2649 Factovisors (数论+素因子分解)
对数值小的分母m素因子分解，然后在n!中检查每个m的素因子，
若n!的幂指数小于m的幂指数，则不能整除
1.分母m==0特判！
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, m;
map<int, int> factor;
map<int, int>::iterator iter;

void get_factor(int n)
{
	factor.clear();
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				factor[i]++;
				n /= i;
			}
			s = sqrt(n);
		}
	}
	if (n > 1) factor[n]++;
}

int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		if (m == 0)
		{
			printf("%d does not divide %d!\n", m, n);
			continue;
		}

		get_factor(m);

		bool flag = true;
		for (iter = factor.begin(); iter != factor.end(); iter++)
		{
			int cnt = 0;
			for (int i = iter->first; i <= n; i *= iter->first)
			{
				cnt += n / i;
			}
			if (cnt < iter->second)
			{
				flag = false;
				break;
			}
		}

		if (flag) printf("%d divides %d!\n", m, n);
		else printf("%d does not divide %d!\n", m, n);
	}
	return 0;
}