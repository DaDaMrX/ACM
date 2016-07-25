/*
Kruskal algorithm
O(ElogE)

1. e[M]存储无向边，按边权从小到大排序，依次检查，若不构成环就加入最小生成树
2. 加入的边数记在cnt中，一可以在找到n-1条边时跳出，二可以判断连通性
*/
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
	int ans = 0, cnt = 0;
	for (int i = 0; i < m; i++)
		if (!same(e[i].a, e[i].b))
		{
			unite(e[i].a, e[i].b);
			ans += e[i].w;
			cnt++;
			if (cnt == n - 1) break;
		}
	if (cnt < n - 1) return -1;
	return ans;
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 0; i < m; i++) 
			scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w);
		printf("%d\n", kruskal());
	}
	return 0;
}
/*
Sample Input
7 9
1 3 1
2 3 2
3 4 3
2 5 10
3 6 7
4 7 5
4 6 1
5 6 5
6 7 8

Sample Output
17
*/