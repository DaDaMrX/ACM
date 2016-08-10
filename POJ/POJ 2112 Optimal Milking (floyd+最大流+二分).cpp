/*
POJ 2112 Optimal Milking (floyd+最大流+二分)
首先用Floyd跑出k+c个点之间的最短路，然后二分挤奶机与奶牛之间的最大距离mid，
取map[i][j]<=mid的边建图，容量为1，添加源点，与每台挤奶机之间边的容量为m，
添加汇点，每头奶牛与汇点之间边的容量为1，跑dinic最大流，
若满流，则减小最大距离，反之，增加最大距离
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 250;
const int M = 15000;

int k, c, m, n;
int map[N][N];

void floyd(int n)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

int head[N], cur[N], d[N], st[M], s, e, no;

struct point {
	int u, v, flow, next;
	point() {};
	point(int x, int y, int z, int w) :u(x), v(y), next(z), flow(w) {};
}p[M];

void add(int x, int y, int z) {
	p[no] = point(x, y, head[x], z);	head[x] = no++;
	p[no] = point(y, x, head[y], 0);	head[y] = no++;
}
void init() {
	memset(head, -1, sizeof(head));
	no = 0;
}

bool bfs() {
	int i, x, y;
	queue<int>q;
	memset(d, -1, sizeof(d));
	d[s] = 0;	q.push(s);
	while (!q.empty()) {
		x = q.front();	q.pop();
		for (i = head[x]; i != -1; i = p[i].next) {
			if (p[i].flow && d[y = p[i].v] < 0) {
				d[y] = d[x] + 1;
				if (y == e)	return true;
				q.push(y);
			}
		}
	}
	return false;
}

int dinic() {
	int i, loc, top, x = s, nowflow, maxflow = 0;
	while (bfs()) {
		for (i = s; i <= e; i++)	cur[i] = head[i];
		top = 0;
		while (true) {
			if (x == e) {
				nowflow = INF;
				for (i = 0; i < top; i++) {
					if (nowflow > p[st[i]].flow) {
						nowflow = p[st[i]].flow;
						loc = i;
					}
				}
				for (i = 0; i < top; i++) {
					p[st[i]].flow -= nowflow;
					p[st[i] ^ 1].flow += nowflow;
				}
				maxflow += nowflow;
				top = loc;	x = p[st[top]].u;
			}
			for (i = cur[x]; i != -1; i = p[i].next)
				if (p[i].flow && d[p[i].v] == d[x] + 1) break;
			cur[x] = i;
			if (i != -1) {
				st[top++] = i;
				x = p[i].v;
			}
			else {
				if (!top)	break;
				d[x] = -1;
				x = p[st[--top]].u;
			}
		}
	}
	return maxflow;
}

void build(int d)
{
	init();
	for (int i = 1; i <= k; i++)
		for (int j = k + 1; j <= n; j++)
			if (map[i][j] <= d) add(i, j, 1);
	s = 0; e = n + 1;
	for (int i = 1; i <= k; i++) add(0, i, m);
	for (int j = k + 1; j <= n; j++) add(j, n + 1, 1);
}

int main()
{
	scanf("%d%d%d", &k, &c, &m);
	n = k + c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
			if (i != j && !map[i][j]) map[i][j] = INF;
		}

	floyd(n);

	int left = 0, right = 0;
	for (int i = 1; i <= k; i++)
		for (int j = k + 1; j <= n; j++)
			right = max(right, map[i][j]);

	while (left < right - 1)
	{
		int mid = left + (right - left >> 1);
		build(mid);
		if (dinic() == c) right = mid;
		else left = mid;
	}

	printf("%d\n", right);

	return 0;
}