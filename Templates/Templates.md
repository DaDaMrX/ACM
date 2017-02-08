# ACM Templates

> By DaDa
>
> 2017.1.2

## 1. Search - BFS

### Introduction

1. 地图为n行m列的字符矩阵，下标从0开始，可在`in_range()`函数中修改。
2. `#`为墙，`F`为终点，可在`bfs()`函数中修改。
3. `step[]`数组，初始化为-1，既标记是否走过，又标记走过的步数。
4. 新扩展的点的合法性的判断是bfs的核心，此模板中包含了最基本的判断。
   1. 检查是否越界
   2. 检查是否为墙
   3. 检查是否已经走过
   4. 检查是否为终点
   5. 普通合法点，入队

### Code

```c++
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

typedef struct Point
{
	int x, y;
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
} Vector;
Point operator+(Point P, Vector V)
{
	return Point(P.x + V.x, P.y + V.y);
}
Vector dir[4] = { Vector(0, 1), Vector(1, 0), Vector(0, -1), Vector(-1, 0) };

int n, m;
char map[N][N];
int step[N][N];
```

```C++
bool in_range(Point P)
{
	return P.x >= 0 && P.x < n && P.y >= 0 && P.y < m;
}

queue<Point> q;
int bfs(Point start)
{
	while (!q.empty()) q.pop();
	memset(step, -1, sizeof(step));

	q.push(start); step[start.x][start.y] = 0;
	while (!q.empty())
	{
		Point from = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point to = from + dir[i];
			if (!in_range(to) || map[to.x][to.y] == '#' || step[to.x][to.y] != -1) continue;
			step[to.x][to.y] = step[from.x][from.y] + 1;
			if (map[to.x][to.y] == 'F') return step[to.x][to.y];
			q.push(to);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", map + i);
	for (int i = 0; i < n; i++) printf("%s\n", map + i);
	return 0;
}
```

## 2. Shortest Path - Dijkstra

### Introduction

1. 用邻接表`adj[]`存储图。
2. 存储结构中不需要节点数n和边数m变量，在main函数中临时定义即可。
3. 调用时只需给出起点`start`，因为采用邻接表，编号从1到n或者从0到n-1均可。
4. 输出`start`到每个点的最短距离，放在`dis[]`数组中。

### Code

```c++
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
```

```C++
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int M = 1e3 + 10;

struct Edge
{
	int to, w, next;
	Edge() {};
	Edge(int to, int w, int next): to(to), w(w), next(next) {};
} edge[M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v, int w)
{
	edge[no] = Edge(v, w, adj[u]);
	adj[u] = no++;
}
int dis[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	while (!pq.empty()) pq.pop();
	pq.push(pii(0, start));
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop();
		int u = p.second;
		if (dis[u] < p.first) continue;
		for (int i = adj[u]; i != -1; i = edge[i].next)
		{
			Edge &e = edge[i];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to])
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}
```

```C++
int main()
{
	//1.建图：输入节点数n，边数m
	int n, m;
	scanf("%d%d", &n, &m);
	init(); //初始化图
	while (m--)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}

	//2.调用
	dijkstra(1);

	//3.输出dis[]
	for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
	return 0;
}
```

### Sample Input

```
5 10
1 2 10
1 4 5
2 3 1
2 4 2
3 5 4
4 2 3
4 3 9
4 5 2
5 1 7
5 3 6
```

### Sample Output

```
0 8 9 5 7
```



## 3. MST - Kruskal

 ### code

```c++
struct Edge
{
	int a, b, w;
} e[M];
```

```C++
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



```

## 4. Disjoint Set

### Code

```c++
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
```

## 5. Fast Power

### Code

```c++
ll power(ll a, ll n, ll m)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return ans;
}



```

## 6. ST

### Introduction

1. O(nlogn)预处理，静态查询区间最小值（下标）/最大值（下标）/最大最小值之差。
2. 数组`a[]`存储输入的数据，下标从1到n。

### Code

```c++
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int a[N];
int dp[N][20], lg[N];
void ST(int n)
{
	lg[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		lg[i] = (i & (i - 1)) == 0 ? lg[i - 1] + 1 : lg[i - 1];
		dp[i][0] = a[i];
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
int rmq(int left, int right)
{
	int k = lg[right - left + 1];
	return max(dp[left][k], dp[right - (1 << k) + 1][k]);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	ST(n);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
```

```C++
		printf("%d\n", rmq(a, b));
	}
	return 0;
}
```

### Sample Input

```
5
2 3 0 1 4
5
1 5
2 4
1 3
1 1
4 4
```

### Sample Output

```
4
3
3
2
1
```

## 7. Segment Tree

### Introduction

维护区间和

### Code

```c++
struct Node
{
	int l, r, sum, lazy;
} tree[4 * N];
inline int L(int i) { return i << 1; }
inline int R(int i) { return (i << 1) + 1; }

void build(int i, int left, int right)
{
	tree[i].l = left; tree[i].r = right;
	tree[i].sum = 0; tree[i].lazy = 0;
	if (left == right) return;
	int mid = left + (right - left >> 1);
	build(L(i), left, mid);
	build(R(i), mid + 1, right);
}
```

```C++
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
```

## 8. Number Theory - Prime

### Code

```c++
bool prime(int n)
{
	if (n == 0 || n == 1) return false;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0) return false;
	return true; 
}
```
