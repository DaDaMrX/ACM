#include <cstdio>
#include <cstring>
#define N 100010
struct node
{
	int l, r, sum, lazy;
} tree[4 * N];
int n, q;
inline int L(int x) { return x << 1; }
inline int R(int x) { return (x << 1) + 1; }
void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right; tree[i].lazy = 0;
	if (left == right)
	{
		tree[i].sum = 1;
		return;
	}
	int mid = tree[i].l + (tree[i].r - tree[i].l) / 2;
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
}
void push(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].sum = (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy = tree[i].lazy;
	tree[R(i)].sum = (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy = tree[i].lazy;
	tree[i].lazy = 0;
}
void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].sum = (tree[i].r - tree[i].l + 1) * key;
		tree[i].lazy = key;
		return;
	}
	push(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l) / 2;
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
}
int query(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].sum;
	push(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l) / 2;
	int ans = 0;
	if (left <= mid) ans += query(L(i), left, right);
	if (right > mid) ans += query(R(i), left, right);
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int iT = 1; iT <= T; iT++)
	{
		scanf("%d%d", &n, &q);
		build(1, 1, n);
		for (int i = 1; i <= n; i++) 
			update(1, i, i, 1);
		int x, y, z;
		for (int i = 1; i <= q; i++)
		{
			scanf("%d%d%d", &x, &y, &z);
			update(1, x, y, z);
		}
		printf("Case %d: The total value of the hook is %d.\n", iT, query(1, 1, n));
	}
	return 0;
}