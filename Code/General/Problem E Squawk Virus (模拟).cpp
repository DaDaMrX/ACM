//Problem E Squawk Virus (模拟)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;
const int M = N * N;

struct Edge
{
	int to, next;
	Edge() {}
	Edge(int to, int next): to(to), next(next) {}
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
	edge[no] = Edge(v, adj[u]);
	adj[u] = no++;
}

ll hav[N], rei[N];
int s, t;

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    init();
    while (m--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }

    memset(hav, 0, sizeof(hav));
    memset(rei, 0, sizeof(rei));
    hav[s] = 1;
    while (t--)
    {
        for (int u = 0; u < n; u++)
            if (hav[u])
            {
                for (int i = adj[u]; i != -1; i = edge[i].next)
                {
                    Edge& e = edge[i];
                    rei[e.to] += hav[u];
                }
            }

        for (int u = 0; u < n; u++) hav[u] = rei[u], rei[u] = 0;
    }

    ll ans = 0;
    for (int u = 0; u < n; u++) ans += hav[u];
    printf("%I64d\n", ans);
    return 0;
}
