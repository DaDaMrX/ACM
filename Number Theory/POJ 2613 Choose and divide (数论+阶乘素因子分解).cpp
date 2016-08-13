/*
POJ 2613 Choose and divide (数论+阶乘素因子分解)
ans = (p! * s! * (r-s)!) / (q! * r! * (p-q)!)
阶乘的素因子分解，分子上的累加，分母上的减去即可
PS：输出用%.5lf WA，用%.5f AC
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;

int mark[N], prime[N];
void get_prime(int n)
{
	memset(mark, 0, sizeof(mark));
	int res = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) mark[i] = prime[res++] = i;
		for (int j = 0; j < res && prime[j] * i <= n; j++)
		{
			mark[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
}

map<int, int> factor;
map<int, int>::iterator iter;
void add_factor(int n)
{
	for (int i = 0; prime[i] <= n; i++)
	{
		for (int j = prime[i]; j <= n; j *= prime[i])
			factor[prime[i]] += n / j;
	}
}
void reduce_factor(int n)
{
	for (int i = 0; prime[i] <= n; i++)
	{
		for (int j = prime[i]; j <= n; j *= prime[i])
			factor[prime[i]] -= n / j;
	}
}

int main()
{
	get_prime(N - 1);
	int p, q, r, s;
	while (~scanf("%d%d%d%d", &p, &q, &r, &s))
	{
		factor.clear();
		add_factor(p);
		add_factor(s);
		add_factor(r - s);
		reduce_factor(q);
		reduce_factor(r);
		reduce_factor(p - q);

		double ans = 1.0;
		for (iter = factor.begin(); iter != factor.end(); iter++)
			ans *= pow(iter->first, iter->second);
		printf("%.5f\n", ans);
	}
	return 0;
}