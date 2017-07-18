//Problem I Salary Inequity (DFS序+线段树)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

struct Edge
{
	int to, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge[N];
int adj[N], no;

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

struct Node
{
	int l, r;
    int max, min;
    int lazy;
} tree[4 * N];
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].max = 0; tree[i].min = 0; 
    tree[i].lazy = 0;
	if (left == right) return;
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
}

void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].max += tree[i].lazy;
	tree[L(i)].min += tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].max += tree[i].lazy;
	tree[R(i)].min += tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}

void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].max += key;
		tree[i].min += key;
		tree[i].lazy += key;
		return;
	}
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
}

int query_max(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].max;
	pushdown(i);
	int maxx = -INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) maxx = max(maxx, query_max(L(i), left, right));
	if (right > mid) maxx = max(maxx, query_max(R(i), left, right));
	return maxx;
}

int query_min(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].min;
	pushdown(i);
	int minx = INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) minx = min(minx, query_min(L(i), left, right));
	if (right > mid) minx = min(minx, query_min(R(i), left, right));
	return minx;
}

int l[N], r[N], cnt;
void dfs(int u)
{
    cnt++;
    l[u] = cnt;
    for (int i = adj[u]; i != -1; i = edge[i].next)
    {
        Edge& e = edge[i];
        dfs(e.to);
    }
    r[u] = cnt;
}

int a[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        init();
        for (int i = 2; i <= n; i++) 
        {
            int u;
            scanf("%d", &u);
            add(u, i);
        }

        cnt = 0;
        dfs(1);

        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        build(1, 1, n);
        for (int i = 1; i <= n; i++) update(1, l[i], l[i], a[i]);

        int q;
        scanf("%d", &q);
        while (q--)
        {
            char s[5];
            scanf("%s", s);
            if (s[0] == 'Q')
            {
                int id;
                scanf("%d", &id);
                int ans = query_max(1, l[id], r[id]) - query_min(1, l[id], r[id]);
                printf("%d\n", ans);
            }
            else
            {
                int id, sum;
                scanf("%d%d", &id, &sum);
                update(1, l[id], r[id], sum);
            }
        }
    }
    return 0;
}
