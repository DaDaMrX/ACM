/********************************************************************************
Round 6 Problem D. Toy Soldiers (线段树)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

struct Node
{
	int l, r, max, min, lazy;
} tree[4 * N];

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].max = 0; tree[i].lazy = 0;
	tree[i].min = 0;
	if (left == right) return;
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
}

void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].max = tree[i].lazy;
	tree[L(i)].min = tree[i].lazy;
	tree[L(i)].lazy = tree[i].lazy;
	tree[R(i)].max = tree[i].lazy;
	tree[R(i)].min = tree[i].lazy;
	tree[R(i)].lazy = tree[i].lazy;
	tree[i].lazy = 0;
}

void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].max = key;
		tree[i].min = key;
		tree[i].lazy = key;
		return;
	}
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
}

int query_max(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].max;
	pushdown(i);
	int ans = -INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) ans = max(ans, query_max(L(i), left, right));
	if (right > mid) ans = max(ans, query_max(R(i), left, right));
	return ans;
}

int query_min(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].min;
	pushdown(i);
	int ans = INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) ans = min(ans, query_min(L(i), left, right));
	if (right > mid) ans = min(ans, query_min(R(i), left, right));
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	build(1, 1, n);
	int x;
	for (int i = 1; i <= n; i++) scanf("%d", &x), update(1, i, i, x);
	int m;
	scanf("%d", &m);
	if (query_max(1, 1, n) == query_min(1, 1, n))
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int k, x;
		scanf("%d%d", &k, &x);
		update(1, k, k, x);
		if (query_max(1, 1, n) == query_min(1, 1, n))
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
