// Week1 I - Thor vs Frost Giants
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

struct Node
{
	int l, r;
    ll sum;
    int lazy;
} tree[4 * N];
int fa[N], a[N];
int n;

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }
inline int P(int i) { return i >> 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
    tree[i].lazy = 0;
	if (left == right)
	{
		tree[i].sum = a[left] % n;
		fa[left] = i;
		return;
	}
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
	tree[i].sum = tree[L(i)].sum * tree[R(i)].sum % n;
}

ll query(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].sum;
	ll sum = 1;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) sum = sum * query(L(i), left, right) % n;
	if (right > mid) sum = sum * query(R(i), left, right) % n;
	return sum;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	build(1, 1, n);
	int l = 1, r = 1, s = 1, ans = INF, ansl, ansr;
	while (true)
	{
		while (r <= n && s != 0) s = s * a[r++] % n;
		if (s != 0) break;
		if (r - l < ans)
		{
			ans = r - l;
			ansl = l;
			ansr = r - 1;
		}
		l++;
		s = query(1, l, r - 1);
	}
	if (ans == INF) printf("-1\n");
	else printf("%d %d\n", ansl - 1, ansr - 1);
	return 0;
}
