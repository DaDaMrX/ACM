#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e4 + 10;
const int M = 5e4 + 10;
struct Edge
{
	int a, b, w;
	Edge() {};
	Edge(int aa, int bb, int ww) : a(aa), b(bb), w(ww) {};
} e[M];
int fa[N], deep[N];
int n, m, r, sum;
void init(int n)
{
	for (int i = 0; i < sum; i++) fa[i] = i, deep[i] = 0;
}
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void unite(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return;
	if (deep[x] < deep[y]) fa[x] = y;
	else
	{
		fa[y] = x;
		if (deep[x] == deep[y]) deep[x]++;
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
bool cmp(Edge e1, Edge e2)
{
	return e1.w > e2.w;
}
int kruskal()
{
	sort(e, e + r, cmp);
	init(sum);
	int cnt = 0, ans = 0;
	for (int i = 0; i < r; i++)
		if (!same(e[i].a, e[i].b))
		{
			unite(e[i].a, e[i].b);
			ans += e[i].w;
			cnt++;
			if (cnt == sum - 1) break;
		}
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &r);
		sum = n + m;
		for (int i = 0; i < r; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			b += n;
			e[i] = Edge(a, b, w);
		}
		printf("%d\n", 10000 * sum - kruskal());
	}
	return 0;
}