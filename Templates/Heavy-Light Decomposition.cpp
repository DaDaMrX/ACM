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
	int l, r, lazy, sum, max;
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

//单点更新
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

//区间查询-求和
void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}
int query(int i, int left, int right)
{
	if (tree[i].l == left && tree[i].r == right) return tree[i].sum;
	pushdown(i);
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

//区间更新-增加
void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].max += tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].max += tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}
void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].sum += (tree[i].r - tree[i].l + 1) * key;
		tree[i].max += key;
		tree[i].lazy += key;
		return;
	}
	pushdown(i);
	if (left <= tree[L(i)].r) update(L(i), left, right, key);
	if (right >= tree[R(i)].l) update(R(i), left, right, key);
	pushup(i);
}
void change(int u, int v, int z)
{
	int top1 = top[u], top2 = top[v];
	while (top1 != top2)
	{
		if (deep[top1] < deep[top2])
		{
			swap(top1, top2);
			swap(u, v);
		}
		update(1, id[top1], id[u], z);
		u = fa[top1];
		top1 = top[u];
	}
	if (deep[u] > deep[v]) swap(u, v);
	update(1, id[u], id[v], z);
}


//单点查询
int query(int i, int x)
{
	if (tree[i].l == x && tree[i].r == x) return tree[i].sum;
	pushdown(i);
	if (x <= tree[L(i)].r) return query(L(i), x);
	else return query(R(i), x);
}

//区间查询-找最大值
void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].max += tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].max += tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}
int query(int i, int left, int right)
{
	if (left == tree[i].l && right == tree[i].r) return tree[i].max;
	pushdown(i);
	if (right <= tree[L(i)].r) return query(L(i), left, right);
	if (left >= tree[R(i)].l) return query(R(i), left, right);
	return max(query(L(i), left, tree[L(i)]), query(R(i), tree[R(i)].l, right));
}
int qmax(int u, int v)
{
	int ans = 0;
	int topu = top[u], topv = top[v];
	while (topu != topv)
	{
		if (deep[topu] < deep[topv]) swap(topu, topv), swap(u, v);
		ans = max(ans, query(1, idx[topu], idx[u]);
		u = fa[topu];
		topu = top[u];
	}
	if (deep[u] > deep[v]) swap(u, v);
	ans = max(ans, query(1, idx[u], idx[v]));
	return ans;
}

//边权转点权
struct
{
	int u, v, w;
} e[N];

for (int i = 1; i < n; i++)
{
	if (deep[e[i].u] > deep[e[i].v]) swap(e[i].u, e[i].v);
	val[e[i].v] = e[i].w;
}

//区间查询-边权转点权后求和
void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}
int query(int i, int left, int right)
{
	if (tree[i].l == left && tree[i].r == right) return tree[i].sum;
	pushdown(i);
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

//区间查询-边权转点权后找最大值
void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].max += tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].max += tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}
int query(int i, int left, int right)
{
	if (left == tree[i].l && right == tree[i].r) return tree[i].max;
	pushdown(i);
	if (right <= tree[L(i)].r) return query(L(i), left, right);
	if (left >= tree[R(i)].l) return query(R(i), left, right);
	return max(query(L(i), left, tree[L(i)]), query(R(i), tree[R(i)].l, right));
}
int qmax(int u, int v)
{
	int ans = 0;
	int topu = top[u], topv = top[v];
	while (topu != topv)
	{
		if (deep[topu] < deep[topv]) swap(topu, topv), swap(u, v);
		ans = max(ans, query(1, idx[topu], idx[u]);
		u = fa[topu];
		topu = top[u];
	}
	if (u == v) return ans;
	if (deep[u] > deep[v]) swap(u, v);
	ans = max(ans, query(1, idx[son[u]], idx[v]));
	return ans;
}

//LCA
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