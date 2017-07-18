/*
FZU 2150 Fire Game
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 12;

int n, m;
char map[N][N];

struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y): x(x), y(y) {}
};
typedef Point Vector;
Vector dir[4];
Point operator+(Point &p, Vector &v)
{
	return Point(p.x + v.x, p.y + v.y);
}
void init_dir()
{
	dir[0] = Vector(1, 0);
	dir[1] = Vector(0, 1);
	dir[2] = Vector(-1, 0);
	dir[3] = Vector(0, -1);
}

Point p[N * N];
int num;

bool in_range(Point &p)
{
	return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m;
}

queue<Point> q;
bool vis[N][N];
int step[N][N];
int bfs(Point start1, Point start2)
{
	while (!q.empty()) q.pop();
	memset(vis, false, sizeof(vis));
	memset(step, -1, sizeof(step));
	vis[start1.x][start1.y] = vis[start2.x][start2.y] = true;
	step[start1.x][start1.y] = step[start2.x][start2.y] = 0;
	q.push(start1);
	q.push(start2);

	int time;
	while (!q.empty())
	{
		Point from = q.front(); q.pop();
		time = step[from.x][from.y];
		for (int i = 0; i < 4; i++)
		{
			Point to = from + dir[i];
			if (!in_range(to) || map[to.x][to.y] == '.' || vis[to.x][to.y]) continue;
			vis[to.x][to.y] = true;
			step[to.x][to.y] = step[from.x][from.y] + 1;
			q.push(to);
		}
	}
	return time;
}

int count()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (vis[i][j]) ans++;
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", map[i]);

		num = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == '#')
					p[num++] = Point(i, j);

		init_dir();
		int ans = INF;
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++)
				{
					int time = bfs(p[i], p[j]);
					if (count() == num)
						ans = min(ans, time);
				}
		
		printf("Case %d: %d\n", cas, ans < INF ? ans : -1);
	}
	return 0;
}
