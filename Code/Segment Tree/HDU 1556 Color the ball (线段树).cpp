#include <cstdio>
#include <cstring>
#define N 100010
struct node
{
	int l, r, s, lazy;
} tree[4 * N];
int fa[N];
int n, a, b;
inline int L(int x){ return x << 1; }
inline int R(int x){ return (x << 1) + 1; }
inline int P(int x){ return x >> 1; }
void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].s = 0; tree[i].lazy = 0;
	if (left == right)
	{
		fa[left] = i;
		return;
	}
	int mid = left + (right - left) / 2;
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
}
void push(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].s += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].s += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}
void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].s += (tree[i].r - tree[i].l + 1) * key;
		tree[i].lazy += key;
		return;
	}
	push(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l) / 2;
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	tree[i].s = tree[L(i)].s + tree[R(i)].s;
}
int query(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].s;
	push(i);
	int sum = 0;
	int mid = tree[i].l + (tree[i].r - tree[i].l) / 2;
	if (left <= mid) sum += query(L(i), left, right);
	if (right > mid) sum += query(R(i), left, right);
	return sum;
}
int main()
{
	while (scanf("%d", &n), n)
	{
		build(1, 1, n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a, &b);
			update(1, a, b, 1);
		}
		for (int i = 1; i < n; i++) 
			printf("%d ", query(1, i, i));
		printf("%d\n", query(1, n, n));
	}
	return 0;
}