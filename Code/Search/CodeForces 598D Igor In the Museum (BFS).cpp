/*
CodeForces 598D Igor In the Museum (BFS)
关键：让BFS到的每个点都对应到总得能看到的画总数
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, m, k;
char map[N][N];
int num[N][N];
bool vis[N][N], vis2[N][N];

struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y): x(x), y(y) {}
};
typedef Point Vector;
Point operator+(Point p, Vector v)
{
	return Point(p.x + v.x, p.y + v.y);
}
Vector dir[4];
void set_dir()
{
	dir[0] = Point(-1, 0);
	dir[1] = Point(1, 0);
	dir[2] = Point(0, -1);
	dir[3] = Point(0, 1);
}

bool in_range(Point p)
{
	return p.x >= 1 && p.x <= n && p.y >= 1 && p.y <= m;
}

queue<Point> q;
int bfs(Point start)
{
	set_dir();
	while (!q.empty()) q.pop();
	q.push(start); vis[start.x][start.y] = true;
	int ans = num[start.x][start.y];
	while (!q.empty())
	{
		Point from = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point to = from + dir[i];
			if (!in_range(to) || map[to.x][to.y] == '*' || vis[to.x][to.y]) continue;
			q.push(to); vis[to.x][to.y] = true;
			ans += num[to.x][to.y];
		}
	}
	return ans;
}

void bfs2(Point start, int s)
{
	set_dir();
	while (!q.empty()) q.pop();
	q.push(start); vis2[start.x][start.y] = true;
	num[start.x][start.y] = s;
	while (!q.empty())
	{
		Point from = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point to = from + dir[i];
			if (!in_range(to) || map[to.x][to.y] == '*' || vis2[to.x][to.y]) continue;
			q.push(to); vis2[to.x][to.y] = true;
			num[to.x][to.y] = s;
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%s", map[i] + 1);

	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] == '.')
			{
				num[i][j] += (map[i - 1][j] == '*') + (map[i + 1][j] == '*')
				+ (map[i][j - 1] == '*') + (map[i][j + 1] == '*');
			}

	memset(vis, false, sizeof(vis));
	memset(vis2, false, sizeof(vis2));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (map[i][j] == '.' && !vis[i][j])
			{
				int s = bfs(Point(i, j));
				bfs2(Point(i, j), s);
			}
	
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) printf("%d ", num[i][j]);
		printf("\n");
	}*/

	while (k--)
	{
		int i, j;
		scanf("%d%d", &i, &j);
		printf("%d\n", num[i][j]);
	}
	return 0;
}
