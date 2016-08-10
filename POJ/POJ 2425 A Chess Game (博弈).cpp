/*
POJ 2425 A Chess Game (博弈)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n;
bool map[N][N];
int sg[N];

int dfs(int u)
{
	if (~sg[u]) return sg[u];
	bool vis[N];
	memset(vis, false, sizeof(vis));
	for (int v = 0; v < n; v++)
		if (map[u][v])
			vis[dfs(v)] = true;
	int i = 0;
	while (vis[i]) i++;
	return sg[u] = i;
}

int main()
{
	while (~scanf("%d", &n))
	{
		memset(map, false, sizeof(map));
		for (int i = 0; i < n; i++)
		{
			int sum;
			scanf("%d", &sum);
			for (int j = 1; j <= sum; j++)
			{
				int to;
				scanf("%d", &to);
				map[i][to] = true;
			}
		}

		memset(sg, -1, sizeof(sg));
		for (int i = 0; i < n; i++)
			if (sg[i] == -1) dfs(i);

		int m;
		while (scanf("%d", &m), m)
		{
			int nim = 0;
			while (m--)
			{
				int t;
				scanf("%d", &t);
				nim ^= sg[t];
			}
			if (nim) printf("WIN\n");
			else printf("LOSE\n");
		}
	}
	return 0;
}