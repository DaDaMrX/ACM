/*
POJ 1284 Primitive Roots (数论+原根)
一个数n的原根个数为phi[phi[n]]
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

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
	int p;
	while (~scanf("%d", &p)) printf("%d\n", phi[phi[p]]);
	return 0;
}