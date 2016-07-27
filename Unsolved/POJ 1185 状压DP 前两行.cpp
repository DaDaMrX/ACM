#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 105;
const int M = 11;

int n, m;
int map[N], dp[N][1 << M][1 << M], num[1 << M];

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

inline bool inmap(int S, int i) { return map[i] & S == S; }

bool check(int S)
{
	if (S & S << 1 || S & S << 2) return false;
	return true;
}

inline bool updown(int S, int T) { return !(S & T); }

int main()
{
	scanf("%d%d%*c", &n, &m);
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n; i++)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			char c = getchar();
			if (c == 'P') map[i] += (1 << j);
		}
		getchar();
	}

	for (int S = 0; S < (1 << m); S++) num[S] = count(S);

	memset(dp, 0, sizeof(dp));
	for (int T = 0; T < (1 << m); T++) if (inmap(T, 0) && check(T))
		dp[0][0][T] = num[T];

	for (int i = 1; i < n; i++)
		for (int S = 0; S < (1 << m); S++) if (inmap(S, i - 1) && check(S))
			for (int T = 0; T < (1 << m); T++) if (inmap(T, i) && check(T) && updown(S, T))
				for (int R = 0; R < (1 << m); R++) if (inmap(R, i - 2) && check(R) && updown(R, S) && updown(R, T))
					dp[i][S][T] = max(dp[i][S][T], dp[i - 1][R][S] + num[T]);

	int ans = 0;
	for (int S = 0; S < (1 << m); S++) if (inmap(S, n - 2) && check(S))
		for (int T = 0; T < (1 << m); T++) if (inmap(T, n - 1) && check(T) && updown(S, T))
			ans = max(ans, dp[n - 1][S][T]);
	printf("%d\n", ans);
	return 0;
}