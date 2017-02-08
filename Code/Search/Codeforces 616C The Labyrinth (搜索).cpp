#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define N 1010
struct Point
{
	int x, y;
	Point() {};
	Point(int i, int j) :x(i), y(j) {};
};
typedef Point Vector;
Point operator+(Point A, Vector n)
{
	return Point(A.x + n.x, A.y + n.y);
}
Vector dir[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, {-1, 0 } };
char map[N][N];
int num[N][N], block[N][N];
bool vis[N][N];
int n, m;
queue<Point> q;
stack<Point> s;
bool wall(Point p)
{
	if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) return true;
	return false;
}
void bfs(Point start, int cnt)
{
	while (!q.empty()) q.pop();
	while (!s.empty()) s.pop();
	q.push(start); vis[start.x][start.y] = true;
	s.push(start);
	int sum = 1;
	while (!q.empty())
	{
		Point from = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point to = from + dir[i];
			if (wall(to) || map[to.x][to.y] == '*' || vis[to.x][to.y]) continue;
			q.push(to); vis[to.x][to.y] = true;
			s.push(to); sum++;
		}
	}
	while (!s.empty())
	{
		Point p = s.top(); s.pop();
		num[p.x][p.y] = sum;
		block[p.x][p.y] = cnt;
	}
}
int inflag(int flag[], int x)
{
	for (int i = 0; i < 4; i++)
		if (flag[i] == x) return true;
	return false;
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 0; i <= n; i++) scanf("%s", map[i]);

		memset(vis, false, sizeof(vis));
		memset(num, 0, sizeof(num));
		memset(block, 0, sizeof(block));
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == '.' && !vis[i][j])
				{
					cnt++;
					bfs(Point(i, j), cnt);
				}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == '*')
				{
					int flag[4] = { 0 };
					Point from(i, j);
					int sum = 1;
					for (int k = 0; k < 4; k++)
					{
						Point to = from + dir[k];
						if (wall(to) || inflag(flag, block[to.x][to.y])) continue;
						sum += num[to.x][to.y];
						flag[k] = block[to.x][to.y];
					}
					map[i][j] = sum % 10 + '0';
				}

		for (int i = 0; i < n; i++) printf("%s\n", map[i]);
	}
	return 0;
}