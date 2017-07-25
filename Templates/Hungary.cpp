#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10; 
const int M = 1e3 + 10; 
 
struct Edge 
{ 
    int to, next; 
} edge[M]; 
int adj[N], no; 
int n, m; 
 
void init() 
{
	memset(adj, -1, sizeof(adj));
	no = 0; 
} 
void add(int u, int v) 
{ 
	edge[no].to = v; 
	edge[no].next = adj[u]; 
	adj[u] = no++; 
} 

int left, right;
int match[N];
bool vis[N];
bool dfs(int u)
{
	for (int i = adj[u]; i != -1; i = edge[i].next)
	{
		Edge &e = edge[i];
		if (vis[e.to]) continue;
		vis[e.to] = true;
		if (match[e.to] == -1 || dfs(match[e.to]))
		{
			match[e.to] = u;
			return true;
		}
	}
	return false;
}

int hungary(int x, int y)
{
	left = x; right = y;
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int u = 1; u <= left; u++)
	{
		memset(vis, false, sizeof(vis));
		if (dfs(u)) ans++;
	}
	return ans;
}

int main()
{
	int n, m, e;
	scanf("%d%d%d", &n, &m, &e);
	init();
	while (e--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	int ans = hungary(n, m);
	printf("%d\n", ans);
	return 0;
}
