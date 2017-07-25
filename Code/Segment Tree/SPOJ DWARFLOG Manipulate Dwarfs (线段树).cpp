#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

struct Node
{
	int l, r;
    int max, min;
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
		tree[i].max = a[left];
		tree[i].min = a[left];
		fa[left] = i;
		return;
	}
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
}

void update(int i)
{
	if (i == 1) return;
	i = P(i);
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
	update(i);
}

int query_max(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].max;
	int maxx = 0;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) maxx = max(maxx, query_max(L(i), left, right));
	if (right > mid) maxx = max(maxx, query_max(R(i), left, right));
	return maxx;
}

int query_min(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].min;
	int minx = INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) minx = min(minx, query_min(L(i), left, right));
	if (right > mid) minx = min(minx, query_min(R(i), left, right));
	return minx;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) a[i] = i;
    build(1, 1, n);
    while (m--)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1)
        {
            int tmp = a[x];
            a[x] = a[y];
            tree[fa[x]].max = a[y];
            tree[fa[x]].min = a[y];
            update(fa[x]);
            a[y] = tmp;
            tree[fa[y]].max = tmp;
            tree[fa[y]].min = tmp;
            update(fa[y]);
        }
        else
        {
            int maxx = query_max(1, x, y);
            int minx = query_min(1, x, y);
            bool f = (y - x) == (maxx - minx);
            printf("%s\n", f ? "YES" : "NO");
        }
    }
    return 0;
}
