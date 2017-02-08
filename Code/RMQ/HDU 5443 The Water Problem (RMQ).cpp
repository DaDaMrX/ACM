/*
HDU 5443 The Water Problem (RMQ)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int a[N], n, q;

int dp[N][20], mm[N];
void ST(int n)
{
	mm[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		mm[i] = ((i & (i - 1))) == 0 ? mm[i - 1] + 1 : mm[i - 1];
		dp[i][0] = a[i];
	}
	for (int j = 1; j <= mm[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
int rmq(int left, int right)
{
	int k = mm[right - left + 1];
	return max(dp[left][k], dp[right - (1 << k) + 1][k]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		ST(n);
		scanf("%d", &q);
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", rmq(l, r));
		}
	}
	return 0;
}