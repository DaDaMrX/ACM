/*
HDU 1532 Drainage Ditches (最大流)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 210;
const int M = 210;

int head[N], cur[N], d[N], st[M], s, e, no;

struct point {
	int u, v, flow, next;
	point() {};
	point(int x, int y, int z, int w) :u(x), v(y), next(z), flow(w) {};
}p[2 * M];

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

int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		s = 1; e = m;
		init();
		while (n--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c);
		}
		printf("%d\n", dinic());
	}
	return 0;
}