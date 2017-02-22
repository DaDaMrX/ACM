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
    int maxi;
    int lazy;
} tree[4 * N];
int fa[N];
int a[N];

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }
inline int P(int i) { return i >> 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].lazy = 0;
	
	if (left == right)
	{
		tree[i].maxi = left;
		fa[left] = i;
		return;
	}
	
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);

	int lmaxi = tree[L(i)].maxi;
	int rmaxi = tree[R(i)].maxi;
	tree[i].maxi = a[lmaxi] >= a[rmaxi] ? lmaxi : rmaxi;
}

void update(int i)
{
	if (i == 1) return;
	i = P(i);
	int lmaxi = tree[L(i)].maxi;
	int rmaxi = tree[R(i)].maxi;
	tree[i].maxi = a[lmaxi] >= a[rmaxi] ? lmaxi : rmaxi;
	update(i);
}

// Problem!!!
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
	tree[i].maxi = a[lmaxi].x >= a[rmaxi].x ? lmaxi : rmaxi;
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

int main()
{
    return 0;
}
