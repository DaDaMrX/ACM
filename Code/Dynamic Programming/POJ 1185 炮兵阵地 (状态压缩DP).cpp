/*
POJ 1185 炮兵阵地 (状态压缩DP)
矩阵按行判断，当前行与前两行有关，三维状态
dp[i][S][T] = max{ dp[i-1][R][S] + num[T] | R,S,T合法 }

合法条件：
1.每行自身不互相攻击：!((S & S << 1) || (S & S << 2))
2.每行与map匹配：(T & S) == S
3.相邻行不能攻击：!(S & T)

约束条件较多，可行状态较少，故每行先单独考虑条件1，把合法的状态存在state[]中
初始化从dp[1][][]开始，只有1行的时候单独考虑
终点ans = max{ dp[n-1][S][T] | S,T合法 }
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 102;
const int M = 10;

int n, m;
int map[N];
int state[1 << M], dp[N][1 << M][1 << M];
int num[1 << M];

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

inline bool inmap(int S, int T) { return (T & S) == S; }
inline bool match(int S, int T) { return !(S & T); }
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		char s[M];
		scanf("%s", s);
		map[i] = 0;
		for (int j = 0; j < m; j++)
			if (s[j] == 'P')
				map[i] += 1 << j;
	}
	int allstates = 1 << m, sum = 0;
	for (int S = 0; S < allstates; S++)
		if (!((S & S << 1) || (S & S << 2)))
		{
			state[sum] = S;
			num[sum++] = count(S);
		}

	if (n == 1)
	{
		int ans = 0;
		for (int s = 0; s < sum; s++)
			if (inmap(state[s], map[0]))
				ans = max(ans, num[s]);
		printf("%d\n", ans);
		return 0;
	}

	for (int s = 0; s < sum; s++)
		if (inmap(state[s], map[0]))
			for (int t = 0; t < sum; t++)
				if (inmap(state[t], map[1]) && match(state[s], state[t]))
					dp[1][s][t] = num[s] + num[t];

	for (int i = 2; i < n; i++)
		for (int s = 0; s < sum; s++)
			if (inmap(state[s], map[i - 1]))
				for (int t = 0; t < sum; t++)
					if (inmap(state[t], map[i]) && match(state[s], state[t]))
					{
						dp[i][s][t] = 0;
						for (int r = 0; r < sum; r++)
							if (inmap(state[r], map[i - 2]) && match(state[r], state[s]) && match(state[r], state[t]))
								dp[i][s][t] = max(dp[i][s][t], dp[i - 1][r][s] + num[t]);
					}

	int ans = 0;
	for (int s = 0; s < sum; s++)
		if (inmap(state[s], map[n - 2]))
			for (int t = 0; t < sum; t++)
				if (inmap(state[t], map[n - 1]) && match(state[s], state[t]))
					ans = max(ans, dp[n - 1][s][t]);
	printf("%d\n", ans);
	return 0;
}