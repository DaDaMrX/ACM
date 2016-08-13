#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 8
bool map[N][N];
struct point
{
	int x, y;
} pre[N][N];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<point> q;
const int n = 5;
void bfs(int x, int y)
{
	while (!q.empty()) q.pop();
	point start; 
	start.x = x; start.y = y;
	q.push(start);
	pre[x][y].x = x; pre[x][y].y = y;
	while (q.front().x != 4 || q.front().y != 4)
	{
		point from = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			point to;
			to.x = from.x + dx[i]; to.y = from.y + dy[i];
			if (to.x < 0 || to.x >= n || to.y < 0 || to.y >= n) continue;
			if (!map[to.x][to.y] || pre[to.x][to.y].x != -1) continue;
			q.push(to);
			pre[to.x][to.y].x = from.x; pre[to.x][to.y].y = from.y;
		}
	}
}
void print(int x, int y)
{
	if (pre[x][y].x != x || pre[x][y].y != y)
		print(pre[x][y].x, pre[x][y].y);
	printf("(%d, %d)\n", x, y);
}
int main()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			map[i][j] = !map[i][j];
		}
	memset(pre, -1, sizeof(pre));
	bfs(0, 0);
	print(4, 4);
	return 0;
}
