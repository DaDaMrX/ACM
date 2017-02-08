/*
LightOJ 1348 Aladdin and the Return Journey (树链剖分+线段树)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 3e4 + 10;

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
	int l, r, sum, max;
} tree[4 * N];
void pushup(int i)
{
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
}
void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
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
	if (deep[u] > deep[v]) swap(u, v);
	ans += query(1, idx[u], idx[v]);
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add(u + 1, v + 1);
			add(v + 1, u + 1);
		}

		dfs1(1);
		dfs2(1, 1);
		build(1, 1, n);

		int q;
		scanf("%d", &q);
		printf("Case %d:\n", cas);
		while (q--)
		{
			int type;
			scanf("%d", &type);
			if (type == 0)
			{
				int i, j;
				scanf("%d%d", &i, &j);
				printf("%d\n", sum(i + 1, j + 1));
				continue;
			}
			if (type == 1)
			{
				int i, v;
				scanf("%d%d", &i, &v);
				update(1, idx[i + 1], v);
				continue;
			}
		}
	}
	return 0;
}