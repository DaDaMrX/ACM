/*
Codeforces 550B Preparing Olympiad (状态压缩枚举)
一系列物品的取或者不取的组合用状态压缩快速遍历
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 17;

int n, l, r, x;
int d[N], dp[1 << N][N];

inline int lowbit(int x) { return x & -x; }
int num(int S)
{
	int ans = 0;
	while (S)
	{
		S -= lowbit(S);
		ans++;
	}
	return ans;
}

int sum(int S)
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (S & 1 << i) ans += d[i];
	return ans;
}

int range(int S)
{
	int mini = -1, maxi = -1;
	for (int i = 0; i < n; i++)
		if (S & 1 << i)
		{
			if (mini == -1 || d[i] < d[mini]) mini = i;
			if (maxi == -1 || d[i] > d[maxi]) maxi = i;
		}
	return d[maxi] - d[mini];
}

int main()
{
	scanf("%d%d%d%d", &n, &l, &r, &x);
	for (int i = 0; i < n; i++) scanf("%d", &d[i]);

	int states = 1 << n, ans = 0;
	for (int S = (1 << 2) - 1; S < states; S++)
	{
		int thesum = sum(S);
		if (num(S) >= 2 && thesum >= l && thesum <= r && range(S) >= x)
			ans++;
	}

	printf("%d\n", ans);
	return 0;
}