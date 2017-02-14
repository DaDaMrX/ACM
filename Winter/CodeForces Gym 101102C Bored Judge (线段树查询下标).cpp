//CodeForces Gym101102C Bored Judge (线段树查询下标)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

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

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		build(1, 1, n);
		int id = 1, ans = 0;
		for (int i = 1; i <= q; i++)
		{
			int index, add;
			scanf("%d%d", &index, &add);
			update(1, index, index, add);
			int tid;
			query_max(1, 1, n, tid);
			if (tid != id) id = tid, ans = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
