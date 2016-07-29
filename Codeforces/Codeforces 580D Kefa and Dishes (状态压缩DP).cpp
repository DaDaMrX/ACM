/*
Codeforces 580D Kefa and Dishes (状态压缩DP)
旅行商问题TSP变式
1.加入点权
2.遍历m个点，不返回起点
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 20;

int n, m, k;
int map[N][N], val[N];
ll dp[1 << N][N];
int num[1 << N];

inline int lowbit(int x) { return x & -x; }
int count(int S)
{
	int ans = 0;
	while (S)
	{
		S -= lowbit(S);
		ans++;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	val[0] = 0;
	for (int i = 0; i < n; i++) scanf("%d", &val[i]);
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= k; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		a--; b--;
		map[a][b] = w;
	}
	int sum = 1 << n;
	for (int S = 0; S < sum; S++) num[S] = count(S);

	for (int S = 1; S < sum; S++)
		for (int i = 0; i < n; i++)
		{
			if (!(S & 1 << i)) continue;
			if (num[S] > m) continue;
			if (S == (1 << i))
			{
				dp[S][i] = val[i];
				continue;
			}
			dp[S][i] = 0;
			for (int j = 0; j < n; j++)
				if (S & 1 << j && j != i)
					dp[S][i] = max(dp[S][i], dp[S & ~(1 << i)][j] + map[j][i] + val[i]);
		}
	ll ans = 0;
	for (int S = (1 << m) - 1; S < sum; S++)
		for (int i = 0; i < n; i++)
		{
			if (num[S] == m && (S & 1 << i))
				ans = max(ans, dp[S][i]);
		}
	printf("%I64d\n", ans);
	return 0;
}