/*
POJ 2135 Farm Tour (最小费用最大流)
1.因为是无向边，所以从1到N再从N到1等价于从1到N两次
2.因为每一条边最多走一次，所以建容量为1，花费为路径长度的双向边
3.要限定走两次，所以增加源点0到1号点，容量为2，花费为0的边，终点为n
4.题目输入保证一定有解，即最大流一定为2，此时最小费用最大流即为所求
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const int M = 4e4 + 10;

int head[N], d[N], s, e, no, dis[N][N], vis[N], pre[N];
struct point {
	int u, v, flow, next, cost;
	point() {};
	point(int x, int y, int z, int w, int c) :u(x), v(y), next(z), flow(w), cost(c) {};
}p[M];
void add(int x, int y, int z, int c) {
	p[no] = point(x, y, head[x], z, c);	head[x] = no++;
	p[no] = point(y, x, head[y], 0, -c);	head[y] = no++;
}
void init() {
	memset(head, -1, sizeof(head));
	no = 0;
}
bool spfa() {
	int i, x, y;
	queue<int>q;
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	d[s] = 0;   vis[s] = true;  q.push(s);
	while (!q.empty()) {
		x = q.front();  q.pop();    vis[x] = false;
		for (i = head[x]; i != -1; i = p[i].next) {
			if (p[i].flow && d[y = p[i].v] > d[x] + p[i].cost) {
				d[y] = d[x] + p[i].cost;   pre[y] = i;
				if (vis[y])  continue;
				vis[y] = true;  q.push(y);
			}
		}
	}
	return d[e] != d[e + 1];
}
int mcmf() {
	int mincost = 0, maxflow = 0, minflow, i;
	while (spfa()) {
		minflow = INF;
		for (i = pre[e]; i != -1; i = pre[p[i].u])
			minflow = min(minflow, p[i].flow);
		for (i = pre[e]; i != -1; i = pre[p[i].u]) {
			p[i].flow -= minflow;
			p[i ^ 1].flow += minflow;
		}
		mincost += d[e] * minflow; maxflow += minflow;
	}
	return mincost;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	init();
	s = 0; e = n;
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, 1, c);
		add(b, a, 1, c);
	}
	add(s, 1, 2, 0);
	printf("%d\n", mcmf());
	return 0;
}