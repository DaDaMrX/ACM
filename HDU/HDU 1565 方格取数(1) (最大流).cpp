/*
HDU 1565 方格取数(1) (最大流)
1.不能从相邻的格子中取数，联想国际象棋的棋盘，划分黑白格，两坐标和为偶数记为白格，反之黑格
2.将二维坐标转化为一维坐标，index=(i-1)*n+j，每个白格与相邻的黑格建容量为INF的边
源点0与每个白格，每个黑个与汇点n*n+1建容量为其数值的边。
3.求此网络的最小割，使其不能联通，而又取不到黑白格之间容量为INF的边，故最小割即为
要取走的最小值，剩余的值即为最大值
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 410;
const int M = 4 * N;

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

struct Node
{
	int x, y;
	Node() {};
	Node(int x, int y) : x(x), y(y) {};
};
typedef Node Vector;
Node operator+(Node A, Vector V)
{
	return Node(A.x + V.x, A.y + V.y);
}
Vector dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int n;

bool valid(Node P)
{
	return P.x >= 1 && P.x <= n && P.y >= 1 && P.y <= n;
}
void deal(int i, int j, int a)
{
	int index = (i - 1) * n + j;
	if ((i + j) & 1)
	{
		add(index, e, a);
	}
	else
	{
		add(s, index, a);
		Node from(i, j);
		for (int k = 0; k < 4; k++)
		{
			Node to = from + dir[k];
			if (!valid(to)) continue;
			int index2 = (to.x - 1) * n + to.y;
			add(index, index2, INF);
		}
	}
}

int main()
{
	while (~scanf("%d", &n))
	{
		init();
		s = 0; e = n * n + 1;
		int sum = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				int a;
				scanf("%d", &a);
				sum += a;
				deal(i, j, a);
			}
		printf("%d\n", sum - dinic());
	}
	return 0;
}