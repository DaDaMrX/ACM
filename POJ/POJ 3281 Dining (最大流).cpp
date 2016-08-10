/*
POJ 3281 Dining (最大流)
1.因为是牛选择食物和饮料，故将牛放在中间，食物和饮料放两边
2.每头牛只能选则一种食物和饮料，即点有容量限制，故拆点，容量为1
3.每中食物和饮料只能选一次，故在牛和食物之间，牛和饮料之间，
以及源点和食物之间，饮料和汇点之间，建立容量为1的边
3.这样此网络的最大流即为最多能满足的牛的数量
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 500;
const int M = 21000;

int n, fd, dk, sum;

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

void build()
{
	s = 0; e = sum + 1;
	for (int i = 1; i <= fd; i++) add(s, i, 1);
	for (int i = fd + 1; i <= fd + n; i++) add(i, i + n, 1);
	for (int i = fd + 2 * n + 1; i <= sum; i++) add(i, e, 1);
	for (int i = 1; i <= n; i++)
	{
		int food, drink;
		scanf("%d%d", &food, &drink);
		while (food--)
		{
			int ff;
			scanf("%d", &ff);
			add(ff, fd + i, 1);
		}
		while (drink--)
		{
			int dd;
			scanf("%d", &dd);
			add(fd + n + i, fd + 2 * n + dd, 1);
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &fd, &dk);
	sum = fd + 2 * n + dk;
	init();
	build();
	printf("%d\n", dinic());
	return 0;
}