/*
HDU 3966 Aragorn's Story (树链剖分+线段树)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 5e4 + 10;

struct Edge
{
	int to, next;
} edge[2 * N];
int head[N], no;
int siz[N], deep[N], fa[N], son[N];
int top[N], id[N], pos[N], dfsOrder;
int val[N], n, m, q;
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
	int l, r, lazy, sum, max;
} tree[N << 2];
void pushup(int i)
{
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
}
void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right; tree[i].lazy = 0;
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
void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}
void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].sum += (tree[i].r - tree[i].l + 1) * key;
		tree[i].lazy += key;
		return;
	}
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
}
void change(int u, int v, int z)
{
	int top1 = top[u], top2 = top[v];
	while (top1 != top2)
	{
		if (deep[top1]<deep[top2])
		{
			swap(top1, top2);
			swap(u, v);
		}
		update(1, id[top1], id[u], z);
		u = fa[top1];
		top1 = top[u];
	}
	if (deep[u]>deep[v]) swap(u, v);
	update(1, id[u], id[v], z);
}
int query(int i, int x)
{
	if (tree[i].l == x && tree[i].r == x) return tree[i].sum;
	pushdown(i);
	if (x <= tree[L(i)].r) return query(L(i), x);
	else return query(R(i), x);
}

int main()
{
	int n, m, q;
	while (~scanf("%d%d%d", &n, &m, &q))
	{
		for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
		init();
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
		}

		dfs1(1);
		dfs2(1, 1);
		build(1, 1, n);

		while (q--)
		{
			char s[5];
			scanf("%s", s);
			if (s[0] == 'Q')
			{
				int x;
				scanf("%d", &x);
				printf("%d\n", query(1, id[x]));
			}
			else 
			{
				int c1, c2, k;
				scanf("%d%d%d", &c1, &c2, &k);
				if (s[0] == 'I') change(c1, c2, k);
				else change(c1, c2, -k);
			}
		}
	}
	return 0;
}