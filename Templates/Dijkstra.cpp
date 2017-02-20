/*
1.堆优化的Dijkstra O(nlogn)

1.用邻接表adj[]存储图
2.存储结构中不需要节点数n和边数m变量，在main函数中临时定义即可
3.调用时只需给出起点start，因为采用邻接表，编号从1到n或者从0到n-1均可
4.输出start到每个点的最短距离，放在dis[]数组中
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const int M = 1e3 + 10;

//********************Copy Begin********************
struct Edge
{
	int to, w, next;
	Edge() {}
	Edge(int to, int w, int next): to(to), w(w), next(next) {}
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
//********************Copy End********************

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

/*
Sample Input
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

Sample Output
0 8 9 5 7 

*/

/*****************************************************************/

/*
2.输出路径

多加一个pre[]数组 
多加一个path()函数
*/

int dis[N], pre[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	memset(pre, -1, sizeof(pre));
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
				pre[e.to] = u;
				pq.push(pii(dis[e.to], e.to));
			}
		}
	}
}

void path(int u, int v)
{
    if (u == v)
    {
        printf("%d", u);
        return;
    }
    path(u, pre[v]);
    printf(" %d", v);
}

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

	//3.查询路径
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int v;
		scanf("%d", &v);
		path(1, v);
		printf("\n");
	}
	return 0;
}

/*
Sample Input
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
5
1 2 3 4 5

Sample Output
0 8 9 5 7 
-1 4 2 1 4 
1
1 4 2
1 4 2 3
1 4
1 4 5
*/