//Problem F Travelling Salesman (MST)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

struct Edge
{
	int a, b, w;
} e[M];
int n, m;

int fa[N], deep[N];
void init(int n)
{
	for (int i = 1; i <= n; i++) fa[i] = i, deep[i] = 0;
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
	return e1.w < e2.w;
}
int kruskal()
{
	sort(e, e + m, cmp);
	init(n);
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (!same(e[i].a, e[i].b))
		{
			unite(e[i].a, e[i].b);
			ans = max(ans, e[i].w);
		}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
		printf("%d\n", kruskal());
	}
	return 0;
}
