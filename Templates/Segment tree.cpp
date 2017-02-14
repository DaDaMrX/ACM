struct Node
{
	int l, r;
    int max, min, sum;
    int lazy;
} tree[4 * N];
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].max = 0;
    tree[i].min = 0; 
    tree[i].sum = 0; 
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
	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;

	tree[R(i)].max += tree[i].lazy;
	tree[R(i)].min += tree[i].lazy;
	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;

	tree[i].lazy = 0;
}

void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].max += key;
		tree[i].min += key;
		tree[i].sum += (tree[i].r - tree[i].l + 1) * key;
		tree[i].lazy += key;
		return;
	}
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
    tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
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

int query_sum(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].sum;
	pushdown(i);
	int sum = 0;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) sum += query_sum(L(i), left, right);
	if (right > mid) sum += query_sum(R(i), left, right);
	return sum;
}


/**************************************************************
查询最大值出现的第一个下标
 ***************************************************************/
struct Node
{
	int l, r;
    int max;
	int id;
    int lazy;
} tree[4 * N];
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].max = 0;
	tree[i].id = left;
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
	tree[L(i)].lazy += tree[i].lazy;

	tree[R(i)].max += tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;

	tree[i].lazy = 0;
}

void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].max += key;
		tree[i].lazy += key;
		return;
	}
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	int lmax = tree[L(i)].max, rmax = tree[R(i)].max;
	if (lmax >= rmax)
	{
		tree[i].max = lmax;
		tree[i].id = tree[L(i)].id;
	}
	else
	{
		tree[i].max = rmax;
		tree[i].id = tree[R(i)].id;
	}
}

int query_max(int i, int left, int right, int& id)
{
	if (left <= tree[i].l && right >= tree[i].r) 
	{
		id = tree[i].id;
		return tree[i].max;
	}
	pushdown(i);
	int maxx = -INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid)
	{
		int lid;
		int lmax = query_max(L(i), left, right, lid);
		if (lmax > maxx) maxx = lmax, id = lid;
	}
	if (right > mid)
	{
		int rid;
		int rmax = query_max(R(i), left, right, rid);
		if (rmax > maxx) maxx = rmax, id = rid;
	}
	return maxx;
}
