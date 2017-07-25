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
    int sum, max, min;
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
		tree[i].max = a[left];
		tree[i].min = a[left];
		fa[left] = i;
		return;
	}
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
}


void pushdown(int i)
{
	if (!tree[i].lazy) return;

	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].max += tree[i].lazy;
	tree[L(i)].min += tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;

	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].max += tree[i].lazy;
	tree[R(i)].min += tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;

	tree[i].lazy = 0;
}

void update(int i)
{
	if (i == 1) return;
	i = P(i);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
	update(i);
}

void update(int i, int left, int right, int val)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].sum += (tree[i].r - tree[i].l + 1) * val;
		tree[i].min += val;
		tree[i].max += val;
		tree[i].lazy += val;
		return;
	}
    if (tree[i].l == tree[i].r) a[tree[i].l] += val;
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, val);
	if (right > mid) update(R(i), left, right, val);
    tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
    tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
    tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
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

int query_min(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].min;
	pushdown(i);
	int minx = INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) minx = min(minx, query_min(L(i), left, right));
	if (right > mid) minx = min(minx, query_min(R(i), left, right));
	return minx;
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


/***************************************/
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

	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;

	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;

	tree[i].lazy = 0;
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

void update(int i)
{
	if (i == 1) return;
	i = P(i);
	tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
	update(i);
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
	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	build(1, 1, n);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		char s[3];
		scanf("%s", s);
		if (s[0] == 'u')
		{
			int l, r, a;
			scanf("%d%d%d", &l, &r, &a);
			update(1, l, r, a);
		}
		else if (s[0] == 'q')
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int ans = query(1, l, r);
			printf("%d\n", ans);
		}
		else if (s[0] == 'i')
		{
			int id, key;
			scanf("%d%d", &id, &key);
			a[id] += key;
			tree[fa[id]].sum += key;
			update(fa[id]);
			printf("tree 3: %d\n", tree[3].sum);
		}
	}
	return 0;
}

/*******************************************************/

struct Node
{
	int l, r;
    int max, min, sum;
    int lazy;
} tree[4 * N];
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].max = 0;
    tree[i].min = 0; 
    tree[i].sum = 0; 
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
	tree[L(i)].min += tree[i].lazy;
	tree[L(i)].sum += (tree[L(i)].r - tree[L(i)].l + 1) * tree[i].lazy;
	tree[L(i)].lazy += tree[i].lazy;

	tree[R(i)].max += tree[i].lazy;
	tree[R(i)].min += tree[i].lazy;
	tree[R(i)].sum += (tree[R(i)].r - tree[R(i)].l + 1) * tree[i].lazy;
	tree[R(i)].lazy += tree[i].lazy;

	tree[i].lazy = 0;
}

void update(int i, int left, int right, int key)
{
	if (left <= tree[i].l && right >= tree[i].r)
	{
		tree[i].max += key;
		tree[i].min += key;
		tree[i].sum += (tree[i].r - tree[i].l + 1) * key;
		tree[i].lazy += key;
		return;
	}
	pushdown(i);
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) update(L(i), left, right, key);
	if (right > mid) update(R(i), left, right, key);
	tree[i].max = max(tree[L(i)].max, tree[R(i)].max);
	tree[i].min = min(tree[L(i)].min, tree[R(i)].min);
    tree[i].sum = tree[L(i)].sum + tree[R(i)].sum;
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

int query_min(int i, int left, int right)
{
	if (left <= tree[i].l && right >= tree[i].r) return tree[i].min;
	pushdown(i);
	int minx = INF;
	int mid = tree[i].l + (tree[i].r - tree[i].l >> 1);
	if (left <= mid) minx = min(minx, query_min(L(i), left, right));
	if (right > mid) minx = min(minx, query_min(R(i), left, right));
	return minx;
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


/**************************************************************
查询最大值出现的第一个下标
 ***************************************************************/
struct Node
{
	int l, r;
    int maxi;
    int lazy;
} tree[4 * N];
int n, a[N];

inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].lazy = 0;
	
	if (left == right)
	{
		tree[i].maxi = a[left] >= a[right] ? left : right;
		return;
	}
	
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);

	int lmaxi = tree[L(i)].maxi;
	int rmaxi = tree[R(i)].maxi;
	tree[i].maxi = a[lmaxi] >= a[rmaxi] ? lmaxi : rmaxi;
}

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
	tree[i].maxi = a[lmaxi] >= a[rmaxi] ? lmaxi : rmaxi;
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
