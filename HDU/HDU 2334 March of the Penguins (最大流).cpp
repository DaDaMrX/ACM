/*
HDU 2334 March of the Penguins (最大流)
1.预处理枚举任意两点间距离，若小于等于D则说明能直接相连，标记在map[][]中
2.点有容量限制，拆点，容量为m；边没有容量限制，记为INF
3.枚举每一个点作为终点建图，若点i与点j能直接相连，则i到n+j建边，j到n+i建边，容量为INF
4.源点到每个点建边，容量为当前点的企鹅数，因汇点必须为最大下标，故建立终点与汇点2n+1容量为INF的边
5.因源点必须为最小下标，故调整浮冰下标从1开始，源点下标为0
6.若对于当前终点，最大流等于总企鹅数，则说明企鹅可以在当前点汇合
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const double eps = 1e-10;
const int N = 210;
const int M = N * N;

struct Floe
{
	int x, y;
	int n, m;
} f[N];
bool map[N][N];

int n;
double dis;

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

double dist(Floe A, Floe B)
{
	int dx = A.x - B.x, dy = A.y - B.y;
	return sqrt(dx * dx + dy * dy);
}
void set_map()
{
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			map[i][j] = dist(f[i], f[j]) <= dis + eps ? true : false;
}

void build(int t)
{
	init();
	s = 0; e = 2 * n + 1;
	for (int i = 1; i <= n; i++) add(i, i + n, f[i].m);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			if (map[i][j])
			{
				add(n + i, j, INF);
				add(n + j, i, INF);
			}
	for (int i = 1; i <= n; i++) add(s, i, f[i].n);
	add(t, e, INF);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%lf", &n, &dis);
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d%d", &f[i].x, &f[i].y, &f[i].n, &f[i].m);
			sum += f[i].n;
		}
		set_map();

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			build(i);
			if (dinic() == sum)
			{
				cnt++;
				if (cnt == 1) printf("%d", i - 1);
				else printf(" %d", i - 1);
			}
		}
		if (!cnt) printf("-1");
		printf("\n");
	}
	return 0;
}