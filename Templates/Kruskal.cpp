/*
Kruskal algorithm
Input: e[M];
Use: disjoint-set
Output: ans

e[M]存储无向边，按边权从小到大排序，依次检查，若不构成环就加入最小生成树
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 20
#define M 50
struct edge
{
    int a, b, w;
} e[M];
int fa[N], rank[N];
int n, m;
void init(int n)
{
    for (int i = 1; i <= n; i++) fa[i] = i, rank[i] = 0;
}
int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) fa[x] = y;
    else
    {
        fa[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}
bool same(int x, int y)
{
    return find(x) == find(y);
}
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
int kruskal()
{
    sort(e, e + m, cmp);
    init(n);
    int ans = 0;
    for (int i = 1; i <= m; i++)
        if (!same(e[i].a, e[i].b))
        {
            unite(e[i].a, e[i].b);
            ans += e[i].w;
        }
    return ans;
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
        printf("%d", kruskal());
    }
    return 0;
}

/*
Sample Input
7 9
1 3 1
2 3 2
3 4 3
2 5 10
3 6 7
4 7 5
4 6 1
5 6 5
6 7 8

Sample Output
17
*/