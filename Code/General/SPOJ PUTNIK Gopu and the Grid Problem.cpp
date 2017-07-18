// Week1 J - Gopu and the Grid Problem
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

struct SegTree
{
	struct Node
	{
		int l, r;
		int sum;
		int lazy;
	} tree[4 * N];
	int fa[N], a[N];

	inline int L(int i) { return i << 1; }
	inline int R(int i) { return (i << 1) + 1; }
	inline int P(int i) { return i >> 1; }

	void build(int i, int left, int right)
	{
		tree[i].l = left; tree[i].r = right;
		tree[i].lazy = 0;
		if (left == right)
		{
			tree[i].sum = a[left];
			fa[left] = i;
			return;
		}
		int mid = left + (right - left >> 1);
		build(L(i), left, mid);
		build(R(i), mid + 1, right);
		tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
	}

	void pushdown(int i)
	{
		if (!tree[i].lazy) return;

		tree[L(i)].sum = (tree[L(i)].r - tree[L(i)].l + 1) - tree[L(i)].sum;
		tree[L(i)].lazy ^= 1;

		tree[R(i)].sum = (tree[R(i)].r - tree[R(i)].l + 1) - tree[R(i)].sum;
		tree[R(i)].lazy ^= 1;

		tree[i].lazy = 0;
	}

	void update(int i, int left, int right)
	{
		if (left <= tree[i].l && right >= tree[i].r)
		{
			tree[i].sum = (tree[i].r - tree[i].l + 1) - tree[i].sum;
			tree[i].lazy ^= 1;
			return;
		}
		pushdown(i);
		int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
		if (left <= mid) update(L(i), left, right);
		if (right > mid) update(R(i), left, right);
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
} t1, t2;

int main()
{
	int n = 1e5 + 1;
	memset(t1.a, 0, sizeof(t1.a));
	memset(t2.a, 0, sizeof(t2.a));
	t1.build(1, 1, n);
	t2.build(1, 1, n);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		char s[3];
		scanf("%s", s);
		if (s[0] == 'x')
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l++; r++;
			t1.update(1, l, r);
		}
		else if (s[0] == 'y')
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l++; r++;
			t2.update(1, l, r);
		}
		else
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1++; y1++; x2++; y2++;
			ll xnum1 = t1.query(1, x1, x2);
			ll xnum0 = x2 - x1 + 1 - xnum1;
			ll ynum1 = t2.query(1, y1, y2);
			ll ynum0 = y2 - y1 + 1 - ynum1;
			ll ans = xnum1 * ynum0 + ynum1 * xnum0;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
