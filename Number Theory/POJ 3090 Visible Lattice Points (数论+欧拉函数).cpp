/*
POJ 3090 Visible Lattice Points (数论+欧拉函数)
1.dp思想，考虑n的情况如何由n-1推出
2.由n-1到n，增加了外围一圈，又因为对称性，只考虑一半
3.从(0,0)能够看到的点是x，y坐标互素的点，因为若x，y不互素，那么将其约分后的点必然将其挡住
4.所以问题转化为：对于一个数n，求出小于等于n的数中互素的数的对数，即为求欧拉函数前n项和
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

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

int sum[N];

int main()
{
	get_euler(N - 1);
	sum[0] = 1;
	for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + phi[i] * 2;

	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int n;
		scanf("%d", &n);
		printf("%d %d %d\n", cas, n, sum[n]);
	}
	return 0;
}