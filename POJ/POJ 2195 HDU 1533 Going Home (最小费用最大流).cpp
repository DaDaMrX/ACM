/*
POJ 2195 HDU 1533 Going Home (最小费用最大流)
1.把每个格点作为节点，如果格点相邻就建一条容量为INF费用为1的边
2.源点与每个小人之间，每座房子与汇点之间建一条容量为1费用为0的边
3.此网络的最小费用最大流即为最小花费
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;
const int M = 9 * N;

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

struct Point
{
	int x, y;
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};
typedef Point Vector;
Point operator+(Point A, Vector V)
{
	return Point(A.x + V.x, A.y + V.y);
}
Vector dir[4] = { { 0, 1 },{ 1, 0 },{ 0, -1 },{ -1, 0 } };

char map[110][110];
int n, m;

bool valid(Point P)
{
	return P.x >= 1 && P.x <= n && P.y >= 1 && P.y <= m;
}
int index(Point P)
{
	return (P.x - 1) * m + P.y;
}
void deal(int i, int j, char c)
{
	Point from(i, j);
	for (int k = 0; k < 4; k++)
	{
		Point to = from + dir[k];
		if (!valid(to)) continue;
		add(index(from), index(to), INF, 1);
	}
	if (c == 'm') add(s, index(from), 1, 0);
	else if (c == 'H') add(index(from), e, 1, 0);
}
int main()
{
	while (scanf("%d%d", &n, &m), n)
	{
		for (int i = 1; i <= n; i++) scanf("%s", &map[i][1]);
		init();
		s = 0; e = n * m + 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				deal(i, j, map[i][j]);
		printf("%d\n", mcmf());
	}
	return 0;
}