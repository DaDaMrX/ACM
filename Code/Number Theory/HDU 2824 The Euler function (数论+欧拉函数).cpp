/*
HDU 2824 The Euler function (数论+欧拉函数)
欧拉函数线性打表
对每一组数据，直接从a到b累加即可，不会T
PS：加sum[]数组会MLE
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 3e6 + 10;

int phi[N], prime[N];
void get_euler(int n)
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	int res = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!phi[i]) phi[i] = i - 1, prime[res++] = i;
		for (int j = 0; j < res && prime[j] * i <= n; j++)
		{
			if (i % prime[j]) phi[prime[j] * i] = phi[i] * (prime[j] - 1);
			else
			{
				phi[prime[j] * i] = phi[i] * prime[j];
				break;
			}
		}
	}
}

int main()
{
	get_euler(N - 1);
	int a, b;
	while (~scanf("%d%d", &a, &b))
	{
		ll ans = 0;
		for (int i = a; i <= b; i++) ans += phi[i];
		printf("%I64d\n", ans);
	}
	return 0;
}