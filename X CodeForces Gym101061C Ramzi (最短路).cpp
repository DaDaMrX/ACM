// X CodeForces Gym101061C Ramzi (最短路)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;
const int M = N * N;

struct Edge
{
	int to, w, k, next;
	Edge() {}
	Edge(int to, int w, int k, int next): to(to), w(w), k(k), next(next) {}
} edge[2 * M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v, int w, int k)
{
	edge[no] = Edge(v, w, k, adj[u]);
	adj[u] = no++;
}

int n, m, x, y;
int ans_walk, ans_total;
int walk, total;

bool vis[N];
void dfs(int u)
{
    if (u == y)
    {
        if (walk < ans_walk)
        {
            ans_walk = walk;
            ans_total = total;
        }
        else if (walk == ans_walk && total < ans_total)
        {
             ans_total = total;
        }
        return;
    }
    vis[u] = true;
    for (int i = adj[u]; i != -1; i = edge[i].next)
    {
        Edge &e = edge[i];
        if (vis[e.to]) continue;
        if (e.k == 1 && walk + e.w > ans_walk) continue;
        if (e.k == 2 && walk == ans_walk && total + e.w > ans_total) continue;
        total += e.w;
        if (e.k == 1) walk += e.w;
        dfs(e.to);
        total -= e.w;
        if (e.k == 1) walk -= e.w;
    }
    vis[u] = false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= m; i++)
        {
            int u, v, w, k;
            scanf("%d%d%d%d", &u, &v, &w, &k);
            add(u, v, w, k);
            add(v, u, w, k);
        }

        scanf("%d%d", &x, &y);
        ans_walk = ans_total = INF;
        walk = total = 0;
        memset(vis, false, sizeof(vis));
        dfs(x);

        if (ans_walk == INF) printf("-1\n");
        else printf("%d %d\n", ans_walk, ans_total);
    }
    return 0;
}
