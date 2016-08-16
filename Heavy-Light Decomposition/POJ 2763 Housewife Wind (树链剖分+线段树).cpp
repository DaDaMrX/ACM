/*
POJ 2763 Housewife Wind (树链剖分+线段树)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

struct Edge
{
	int to, next;
} edge[2 * N];
int head[N], no;
int siz[N], deep[N], fa[N], son[N];
int top[N], id[N], pos[N], dfsOrder;
int n, val[N];
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
	dfsOrder = 0;
	deep[1] = fa[1] = siz[0] = 0;
}
void add(int u, int v)
{
	edge[no].to = v; edge[no].next = head[u]; head[u] = no++;
	edge[no].to = u; edge[no].next = head[v]; head[v] = no++;
}

void dfs1(int x)
{
	siz[x] = 1;
	son[x] = 0;
	for (int i = head[x]; i != -1; i = edge[i].next)
	{
		int &u = edge[i].to;
		if (u != fa[x])
		{
			fa[u] = x;
			deep[u] = deep[x] + 1;
			dfs1(u);
			siz[x] += siz[u];
			if (siz[son[x]] < siz[u]) son[x] = u;
		}
	}
}
void dfs2(int u, int t)
{
	top[u] = t;
	id[u] = ++dfsOrder;
	pos[dfsOrder] = u;
	if (son[u]) dfs2(son[u], t);
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int &v = edge[i].to;
		if (v != fa[u] && v != son[u]) dfs2(v, v);
	}
}

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }
struct Node
{
	int l, r, sum, max;
} tree[N << 2];
void pushup(int i)
{
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
}
void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].max = INF; tree[i].sum = 0;
	if (left == right)
	{
		tree[i].max = tree[i].sum = val[pos[left]];
		return;
	}
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
	pushup(i);
}

void update(int i, int x, int val)
{
	if (tree[i].l == x && tree[i].r == x)
	{
		tree[i].max = tree[i].sum = val;
		return;
	}
	if (x <= tree[L(i)].r) update(L(i), x, val);
	else update(R(i), x, val);
	pushup(i);
}

int qqsum(int i, int left, int right)
{
	if (tree[i].l == left && tree[i].r == right) return tree[i].sum;
	if (right <= tree[L(i)].r) return qqsum(L(i), left, right);
	if (left >= tree[R(i)].l) return qqsum(R(i), left, right);
	return qqsum(L(i), left, tree[L(i)].r) + qqsum(R(i), tree[R(i)].l, right);
}
int sum(int x, int y)
{
	int ans = 0, u = top[x], v = top[y];
	while (u != v)
	{
		if (deep[u] < deep[v]) swap(u, v), swap(x, y);
		ans += qqsum(1, id[u], id[x]);
		x = fa[u];
		u = top[x];
	}
	if (x == y) return ans;
	if (deep[x] > deep[y]) swap(x, y);
	ans += qqsum(1, id[son[x]], id[y]);
	return ans;
}

struct
{
	int u, v, w;
} e[N];

int main()
{
	int n, q, s;
	scanf("%d%d%d", &n, &q, &s);
	init();
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		add(e[i].u, e[i].v);
	}

	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i < n; i++)
	{
		if (deep[e[i].u] > deep[e[i].v]) swap(e[i].u, e[i].v);
		val[e[i].v] = e[i].w;
	}
	build(1, 1, n);

	while (q--)
	{
		int t;
		scanf("%d", &t);
		if (!t)
		{
			int u;
			scanf("%d", &u);
			printf("%d\n", sum(s, u));
			s = u;
		}
		else
		{
			int i, w;
			scanf("%d%d", &i, &w);
			update(1, id[e[i].v], w);
		}
	}
	return 0;
}