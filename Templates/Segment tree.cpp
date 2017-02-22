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
    int maxi;
    int lazy;
} tree[4 * N];
int n, a[N];

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].lazy = 0;
	
	if (left == right)
	{
		tree[i].maxi = a[left] >= a[right] ? left : right;
		return;
	}
	
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);

	int lmaxi = tree[L(i)].maxi;
	int rmaxi = tree[R(i)].maxi;
	tree[i].maxi = a[lmaxi] >= a[rmaxi] ? lmaxi : rmaxi;
}

void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}

void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].lazy += key;
		return;
	}
	
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	
	int lmaxi = tree[L(i)].maxi;
	int rmaxi = tree[R(i)].maxi;
	tree[i].maxi = a[lmaxi] >= a[rmaxi] ? lmaxi : rmaxi;
}

int query_maxi(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].maxi;
	pushdown(i);
	int maxi = -1;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid)
	{
		int lmaxi = query_maxi(L(i), left, right);
		if (maxi == -1 || a[lmaxi] > a[maxi]) maxi = lmaxi;
	}
	if (right > mid)
	{
		int rmaxi = query_maxi(R(i), left, right);
		if (maxi == -1 || a[rmaxi] > a[maxi]) maxi = rmaxi;
	}
	return maxi;
}
