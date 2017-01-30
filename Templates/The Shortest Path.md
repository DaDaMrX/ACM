# 最短路

[TOC]

## 一、全局最短路

### 1. Floyd-Warshall

#### 算法描述

用$$M_k[i][j](0\le k\le n)$$表示只使用前$k$个节点的情况下节点$i$到节点$j$的最短路径的长度，显然，$M_0[i][j]$就是邻接矩阵，$M_n[i][j]$即为所求。

那么在已经得到$M_{k-1}$的情况下如何求得$M_k$呢？$i$到$j$经过前k个点的最短路只有两种情况，一种是不经过$k$点，此时$M_k=M_{k-1}$，另一种是经过$k$点，此时$M_k[i][j]=M_{k-1}[i][k]+M_{k-1}[k][j]$，合起来就得到了$M_k[i][j]=min\{M_k[i][j], M_{k-1}[i][k]+M_{k-1}[k][j]\}$，改为只使用一个二维数组实现，就得到了$M[i][j]=min\{M[i][j], M[i][k]+M[k][j]\}$。

#### 代码实现

```c++
int n, map[N][N];
void floyd()
{
	for (int i = 1; i <= n; i++) map[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}
```

#### 时间复杂度

因为进行了三重循环，所以Floyd算法的时间复杂度为$O(V^3)$。

#### 应用条件

适用于任意图，允许负边和负圈存在。要判断图中是否存在负圈，只需检查是否存在$map[i][i]<0$的顶点就可以了。

## 二、单源最短路

### 2. Dijkstra

#### 算法描述

* `dis[i]`表示从起点`s`到节点`i`的最短路径的长度。初始化起点的值为$0$，其余点的值均为无穷大。
* 将节点集合$V$划分为两个集合$S$和$Q$，其中$S$为已经找到最短路径的点的集合，$Q$为还未找到最短路径的点的集合。初始化集合$S$为空集，所有节点均在集合$Q$中。
* 每次从集合$Q$中找出距起点最近（`dis[u]`值最小）的节点`u`，将其加入集合$S$中，用`u`更新$Q$中其余节点的距离值。 

#### 伪代码

```c++
初始化数组dis[]
初始化集合S和Q
while Q非空
  从Q中选出dis[]值最小的节点u
  将u加入S中
  用u更新Q中的其他节点
```

#### 一般的Dijkstra算法

时间复杂度$O(V^2)$

```c++
int n, m, adj[N][N]; //存储图：n个点，m条边，邻接矩阵adj[][]
int dis[N]; //每个点到起点的最短距离
bool vis[N]; //标记每个点是否访问过，访问过的点构成S集合，未访问过的点构成Q集合
void dijkstra(int start)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[start] = 0; //初始化dis[]数组
	memset(vis, false, sizeof(vis)); //初始化vis[]数组，对应S和Q两个集合
	for (int i = 1; i <= n; i++) //每个点处理一次，共循环n次
	{
		int u = -1;
		for (int v = 1; v <= n; v++) //节点编号1到n
			if (!vis[v] && (u == -1 || dis[v] < dis[u])) 
				u = v; //从未访问过的点中即S集合中选出距离最近的点u
		vis[u] = true; //标记访问，即将节点u加入S集合
		for (int v = 1; v <= n; v++) //用u更新所有未访问过的点，即集合Q中的点
			if (!vis[v])
				dis[v] = min(dis[v], dis[u] + adj[u][v]);
	}
}
```

#### 堆优化的Dijkstra算法

时间复杂度$O(ElogV)$

```c++
struct Edge
{
	int to, w, next;
	Edge() {};
	Edge(int to, int w, int next): to(to), w(w), next(next) {};
} edge[M];
int adj[N], no; //邻接表存储图

void init() //邻接表初始化
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v, int w) //加边操作
{
	edge[no] = Edge(v, w, adj[u]);
	adj[u] = no++;
}

int dis[N];
typedef pair<int, int> pii; //pair对中第一个元素存储dis[u]的值，第二个元素存储下标u
priority_queue<pii, vector<pii>, greater<pii> > pq; //优先队列，小根堆
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0; //初始化dis[]数组
	while (!pq.empty()) pq.pop(); //清空优先队列
	pq.push(pii(0, start)); //起点入队
	while (!pq.empty())
	{
		pii p = pq.top(); pq.pop(); //取出最小元素
		int u = p.second;
		if (dis[u] < p.first) continue; //忽略队列中的无效元素
		for (int i = adj[u]; i != -1; i = edge[i].next) //松弛与u相邻的每一个节点
		{
			Edge &e = edge[i];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to]) //需要更新
			{
				dis[e.to] = sum;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}
```

#### 应用条件

允许负边存在，但不允许有负圈。

### 3. Bellman-Ford

#### 算法描述

* 循环$n-1$次，每次循环对每条边进行一次松弛操作。
* 最后再次检查每一条边，如果存在还能够松弛的边，则说明存在权值和为负的圈，不存在最短路。

#### 代码实现

```c++
struct Edge
{
	int u, v, w;
} e[M];
int n, m; //用数组e[]存储每一条边

int dis[N];
bool bellman(int start)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[start] = 0; //初始化dis[]数组
	for (int i = 1; i < n; i++) //松弛n-1遍
		for (int j = 1; j <= m; j++) //对每条边进行一次松弛操作
			dis[e[j].v] = min(dis[e[j].v], dis[e[j].u] + e[j].w);
	for (int j = 1; j <= m; j++) //判负圈
		if (dis[e[j].u] + e[j].w < dis[e[j].v])
			return false;
	return true;
}
```

#### 时间复杂度

时间复杂度为$O(VE)$，复杂度很高，一般很少采用，但如果需要判负圈的话，就必须使用此算法。

#### 应用条件

适用于任意图，允许负边和负圈存在。此算法主要用来判断负圈是否存在。

### 4. SPFA (Shortest Path Faster Algorithm)

#### 算法描述

用数组`dis[]`保存每个节点最短路径长度的估计值。建立一个队列来保存更新过的节点，每次操作取出队首节点`u`，用`u`对每一个由`u`点出发所指向的节点`v`进行松弛操作，如果节点`v`的`dis[]`值被更新，且点`v`不在队列中，就将`v`入队。这样不断从队列中取出结点进行松弛操作，直至队列空为止。

#### 代码实现

```c++
struct Edge
{
	int to, w, next;
	Edge() {}
	Edge(int to, int w, int next): to(to), w(w), next(next) {}
} edge[M];
int adj[N], no;
int n, m; //邻接表存储图

void init() //邻接表初始化
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}

void add(int u, int v, int w) //加边操作
{
	edge[no] = Edge(v, w, adj[u]);
	adj[u] = no++;
}

int dis[N];
queue<int> q;
bool vis[N];
void spfa(int start)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[start] = 0; //初始化dis[]数组
	while (!q.empty()) q.pop(); //清空队列
	q.push(start); //起点入队
	memset(vis, false, sizeof(vis));
	vis[start] = true; //初始化vis[]数组
	while (!q.empty())
	{
		int u = q.front(); q.pop(); //取出队首元素赋值给u
		for (int i = adj[u]; i != -1; i = edge[i].next)
		{  //对从u出发到达的每一个节点进行松弛操作
			Edge &e = edge[i];
			int sum = dis[u] + e.w;
			if (sum < dis[e.to]) //如果dis[e.to]被更新
			{
				dis[e.to] = sum;
				if (!vis[e.to]) q.push(e.to);
			}
		}
	}
}
```

#### 时间复杂度

SPFA算法的时间复杂度可以降低到$O(kE)$，$k$是个比较小的系数，并且在绝大多数的图中$k<=2$，然而在一些精心构造的图中可能会上升到很高。

#### 应用条件

SPFA算法允许负边存在，一般来说不允许有负圈，但可以将算法修改为可以判断负圈。

## 三、应用

### 最长路

### 路径还原

### 次短路

### 权值积最小