#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 6e3 + 10;
int n;
int v[N];
vector<int> vec[N];
int dp[N][2];
set<int> s;
void dfs(int i)
{
	dp[i][1] = v[i];
	dp[i][0] = 0;
	for (auto j : vec[i])
	{
		dfs(j);
		dp[i][1] += dp[j][0];
		dp[i][0] += max(dp[j][0], dp[j][1]);
	}
}
int main()
{
	while (scanf("%d", &n), n)
	{
		s.clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &v[i]);
			vec[i].clear();
			s.insert(i);
		}
		for (int i = 1; i <= n; i++) vec[i].clear();
		for (int i = 1; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			vec[b].push_back(a);
			s.erase(a);
		}
		int root = *s.begin();
		dfs(root);
		int ans = max(dp[root][1], dp[root][0]);
		printf("%d\n", ans);
	}
	return 0;
}