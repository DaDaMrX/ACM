/*
Segment tree

build(i, left, right)
qudate(i, left, right, key)
query(i, left, right)

全部自顶向下，递归
*/
#include <cstdio>
#include <cstring>
#define N 20
struct node
{
	int l, r, sum, lazy;
} tree[4 * N];
int fa[N];
int n, m;
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }
inline int P(int i) { return i >> 1; }
void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].sum = 0; tree[i].lazy = 0;
	if (left == right)
	{
		fa[left] = i;
		return;
	}
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
}
void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
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
int query(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].sum;
	pushdown(i);
	int sum = 0;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) sum += query(L(i), left, right);
	if (right > mid) sum += query(R(i), left, right);
	return sum;
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		build(1, 1, n);
		for (int i = 1; i <= n; i++)
		{
			int t;
			scanf("%d", &t);
			update(1, i, i, t);
		}
		for (int i = 1; i <= n; i++)
			printf("%d: %d\n", i, query(1, i, i));
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d~%d: %d\n", a, b, query(1, a, b));
		}
	}
	return 0;
}

/*
Samele Input
5 3
3
4
1
7
5
1 5
3 4
1 3

Sample Output
1: 3
2: 4
3: 1
4: 7
5: 5
1~5: 20
3~4: 8
1~3: 8
*/