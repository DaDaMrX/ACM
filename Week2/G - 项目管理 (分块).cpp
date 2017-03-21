#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 20;

struct E
{
    int u, v;
} e[M];

struct Edge
{
    int to, next;
    Edge() {};
    Edge(int to, int next): to(to), next(next) {};
} edge[M];
int adj[N], no;
int n, m, num[N], sum[N];

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

int deg[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i <= m; i++) 
        {
            scanf("%d%d", &e[i].u, &e[i].v);
            deg[e[i].u]++; deg[e[i].v]++;
        }
        int s = sqrt(m);
        init();
        for (int i = 1; i <= m; i++)
        {
            int &u = e[i].u, &v = e[i].v;
            if (deg[u] < s) add(u, v);
            if (deg[v] < s) add(v, u);
            if (deg[u] >= s && deg[v] >= s) add(u, v), add(v, u);
        }
        memset(num, 0, sizeof(num));
        memset(sum, 0, sizeof(sum));
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int c;
            scanf("%d", &c);
            if (c == 0)
            {
                int u, x;
                scanf("%d%d", &u, &x);
                num[u] += x;
                for (int i = adj[u]; i != -1; i = edge[i].next)
                    sum[edge[i].to] += x;
            }
            else
            {
                int u;
                scanf("%d", &u);
                if (deg[u] >= s)
                {
                    printf("%d\n", sum[u]);
                    continue;
                }
                int ans = 0;
                for (int i = adj[u]; i != -1; i = edge[i].next)
                    ans += num[edge[i].to];
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
