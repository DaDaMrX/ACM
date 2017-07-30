/**************************************************************************
 线段树
 1. 下标从1到n
 2. 可查询区间和、最大值、最大值出现的第一个下标，最小值同理
 3. 先把数据存入数组a[]中，然后建树build(1,1,n)
 4. 可单点更新，区间更新，区间查询，更新操作为累加操作，可根据需要改为覆盖
 5. 如果是单点更新，则不需要pushdown()，可把pushdown()的定义和调用删除
**************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

struct Node
{
	int l, r;
    int sum, max, maxi;
    int lazy;
} tree[4 * N];
int fa[N], a[N];

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }
inline int P(int i) { return i >> 1; }

void pushup(int i)
{
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].maxi = 
		tree[L(i)].max >= tree[R(i)].max ? tree[L(i)].maxi : tree[R(i)].maxi;
}

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
    tree[i].lazy = 0;
	if (left == right)
	{
		tree[i].sum = a[left];
		tree[i].max = a[left];
		tree[i].maxi = left;
		fa[left] = i;
		return;
	}
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
	pushup(i);
}

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

void update(int i)
{
	if (i == 1) return;
	i = P(i);
	pushup(i);
	update(i);
}

void update(int i, int left, int right, int val)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].sum += (tree[i].r - tree[i].l + 1) * val;
		tree[i].max += val;
		tree[i].lazy += val;
		if (tree[i].l == tree[i].r) a[tree[i].l] += val;
		return;
	}
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, val);
	if (right > mid) update(R(i), left, right, val);
	pushup(i);
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

int query_max(int i, int left, int right, int &maxi)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		maxi = tree[i].maxi;
		return tree[i].max;
	}
	pushdown(i);
	int maxx = -INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid)
	{
		int lmaxi;
		int lmax = query_max(L(i), left, right, lmaxi);
		if (lmax > maxx) maxx = lmax, maxi = lmaxi;
	} 
	if (right > mid)
	{
		int rmaxi;
		int rmax = query_max(R(i), left, right, rmaxi);
		if (rmax > maxx) maxx = rmax, maxi = rmaxi;
	}
	return maxx;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    int m;
    scanf("%d", &m);
    while (m--)
    {
        char s[5];
        scanf("%s", s);
        if (s[0] == 'Q')
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int ans = query_sum(1, l, r);
            printf("%d\n", ans);
        }
        else if (s[0] == 'U')
        {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            update(1, l, r, val);
        }
        else if (s[0] == 'u')
        {
            int i, val;
            scanf("%d%d", &i, &val);
            a[i] += val;
            tree[fa[i]].sum += val;
            update(fa[i]);
        }
    }
    return 0;
}

/**************
INPUT
5
2 3 1 5 4
5
Q 2 4
U 1 3 2
Q 2 5
u 4 3
Q 3 5

OUTPUT
9
17
15

**************/