// CodeForces Gym101086J Smooth Developer (DFS)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e6 + 10;

struct Edge
{
	int to, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge[M];
int adj[N], no;

string name[N];
map<string, int> mp;
bool vis[N];

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v)
{
	edge[no] = Edge(v, adj[u]);
	adj[u] = no++;
}

void dfs(int u)
{
	if (vis[u]) return;
	vis[u] = true;
	for (int i = adj[u]; i != -1; i = edge[i].next)
		if (!vis[edge[i].to]) 
			dfs(edge[i].to);
}

char s[20];
string str;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		init();
		mp.clear();
		string str;
		for (int i = 1; i <= n; i++)
		{
			int c;
			scanf("%s%d", s, &c);
			name[i] = string(s);
			mp[name[i]] = i;
			for (int j = 1; j <= c; j++)
			{
				scanf("%s", s);
				str = string(s);
				if (str == name[i]) continue;
				add(i, mp[str]);
			}
		}

		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= k; i++)
		{
			scanf("%s", s);
			dfs(mp[string(s)]);
		}

		for (int i = 1; i <= n; i++)
			if (vis[i]) cout << name[i] << endl;
	}
	return 0;
}
