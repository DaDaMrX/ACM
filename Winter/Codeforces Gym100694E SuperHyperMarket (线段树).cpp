// Codeforces Gym100694E SuperHyperMarket (Ïß¶ÎÊ÷)
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
    int mini;
    int lazy;
} tree[4 * N];
int n, fa[N];
struct Desk
{
	int c, p1, p2;
	double p, x;
} a[N];
int q[N];

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].lazy = 0;
	
	if (left == right)
	{
		tree[i].mini = a[left].x <= a[right].x ? left : right;
		fa[left] = i;
		return;
	}
	
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);

	int lmini = tree[L(i)].mini;
	int rmini = tree[R(i)].mini;
	tree[i].mini = a[lmini].x <= a[rmini].x ? lmini : rmini;
}

void pushdown(int i)
{
	if (!tree[i].lazy) return;
	tree[L(i)].lazy += tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;
	tree[i].lazy = 0;
}

void update(int i)
{
	if (i == 1) return;
	i /= 2;
	int lmini = tree[L(i)].mini;
	int rmini = tree[R(i)].mini;
	tree[i].mini = a[lmini].x <= a[rmini].x ? lmini : rmini;
	update(i);
}

void update(int i, int left, int right, int key)
// Problem!!!
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
	
	int lmini = tree[L(i)].mini;
	int rmini = tree[R(i)].mini;
	tree[i].mini = a[lmini].x >= a[rmini].x ? lmini : rmini;
}

int query_mini(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].mini;
	pushdown(i);
	int mini = -1;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid)
	{
		int lmini = query_mini(L(i), left, right);
		if (mini == -1 || a[lmini].x < a[mini].x) mini = lmini;
	}
	if (right > mid)
	{
		int rmini = query_mini(R(i), left, right);
		if (mini == -1 || a[rmini].x < a[mini].x) mini = rmini;
	}
	return mini;
}

int main()
{
	int k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", q + i);
	memset(a, 0, sizeof(a));
	build(1, 1, k);
	for (int i = 1; i <= n; i++)
	{
		int id = query_mini(1, 1, k);
		printf("%d%c", id, i < n ? ' ' : '\n');
		a[id].p2 = a[id].p1;
		a[id].p1 = q[i];
		a[id].c++;
		if (a[id].c == 0) a[id].p = 0.0;
		else if (a[id].c == 1) a[id].p = a[id].p1;
		else a[id].p = (a[id].p1 + a[id].p2) / 2.0;
		a[id].x = a[id].c * a[id].p;
		update(fa[id]);
	}
    return 0;
}
