/*
Codeforces 165D Beard Graph (树链剖分+线段树)
1.边权转点权，黑边为0，白边为1
2.单点更新，区间查询
3.查询边权和，若为0，则说明全为黑边，然后利用LCA计算路径上边的数量
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
int top[N], idx[N], pos[N], dfsOrder;
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
	idx[u] = ++dfsOrder;
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
	int l, r, sum;
} tree[4 * N];
void pushup(int i)
{
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
}
void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	if (left == right)
	{
		tree[i].sum = val[pos[left]];
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
		tree[i].sum = val;
		return;
	}
	if (x <= tree[L(i)].r) update(L(i), x, val);
	else update(R(i), x, val);
	pushup(i);
}

int query(int i, int left, int right)
{
	if (tree[i].l == left && tree[i].r == right) return tree[i].sum;
	if (right <= tree[L(i)].r) return query(L(i), left, right);
	if (left >= tree[R(i)].l) return query(R(i), left, right);
	return query(L(i), left, tree[L(i)].r) + query(R(i), tree[R(i)].l, right);
}
int sum(int u, int v)
{
	int ans = 0;
	int topu = top[u], topv = top[v];
	while (topu != topv)
	{
		if (deep[topu] < deep[topv]) swap(topu, topv), swap(u, v);
		ans += query(1, idx[topu], idx[u]);
		u = fa[topu];
		topu = top[u];
	}
	if (u == v) return ans;
	if (deep[u] > deep[v]) swap(u, v);
	ans += query(1, idx[son[u]], idx[v]);
	return ans;
}

int lca(int u, int v)
{
	int topu = top[u], topv = top[v];
	while (topu != topv)
	{
		if (deep[topu] < deep[topv]) swap(topu, topv), swap(u, v);
		u = fa[topu];
		topu = top[u];
	}
	return deep[u] < deep[v] ? u : v;
}

struct
{
	int u, v, w;
} e[N];

int main()
{
	int n;
	scanf("%d", &n);
	init();
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &e[i].u, &e[i].v);
		e[i].w = 0;
		add(e[i].u, e[i].v);
		add(e[i].v, e[i].u);
	}

	dfs1(1);
	dfs2(1, 1);
	for (int i = 1; i < n; i++)
	{
		if (deep[e[i].u] > deep[e[i].v]) swap(e[i].u, e[i].v);
		val[e[i].v] = e[i].w;
	}
	build(1, 1, n);

	int m;
	scanf("%d", &m);
	while (m--)
	{
		int type;
		scanf("%d", &type);
		if (type == 3)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (sum(a, b)) printf("-1\n");
			else printf("%d\n", deep[a] + deep[b] - 2 * deep[lca(a, b)]);
		}
		else
		{
			int id;
			scanf("%d", &id);
			update(1, idx[e[id].v], type - 1);
		}
	}
	return 0;
}