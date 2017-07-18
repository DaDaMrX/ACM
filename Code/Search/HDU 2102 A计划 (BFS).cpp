/*
HDU 2102 A计划
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 12;

int n, m, t;
char map[2][N][N];

struct Point
{
	int k, x, y;
	Point() {};
	Point(int k, int x, int y): k(k), x(x), y(y) {};
};
struct Vector
{
	int x, y;
	Vector() {}
	Vector(int x, int y): x(x), y(y) {}
};
Vector dir[4];
Point operator+(Point &p, Vector &v)
{
	return Point(p.k, p.x + v.x, p.y + v.y);
}
void init_dir()
{
	dir[0] = Vector(1, 0);
	dir[1] = Vector(0, 1);
	dir[2] = Vector(-1, 0);
	dir[3] = Vector(0, -1);
}

bool in_range(Point &p)
{
	return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m;
}

queue<Point> q;
int step[2][N][N];
bool bfs(Point start)
{
	while (!q.empty()) q.pop();
	memset(step, -1, sizeof(step));
	init_dir();
	step[start.k][start.x][start.y] = 0;
	q.push(start);
	while (!q.empty())
	{
		Point from = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point to = from + dir[i];
			if (!in_range(to)) continue;
			if (map[to.k][to.x][to.y] == '#') to.k ^= 1;
			if (map[to.k][to.x][to.y] == '*' || map[to.k][to.x][to.y] == '#' || step[to.k][to.x][to.y] != -1) continue;
			if (map[to.k][to.x][to.y] == 'P') return true;
			step[to.k][to.x][to.y] = step[from.k][from.x][from.y] + 1;
			if (step[to.k][to.x][to.y] == t) return false;
			q.push(to);
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &t);
		for (int k = 0; k < 2; k++)
			for (int i = 0; i < n; i++)
				scanf("%s", map[k][i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (map[0][i][j] == '#' && map[1][i][j] == '#'
				|| map[0][i][j] == '#' && map[1][i][j] == '*'
				|| map[0][i][j] == '*' && map[1][i][j] == '#')
				map[0][i][j] = map[1][i][j] == '*';
			}
		printf("%s\n", bfs(Point(0, 0, 0)) ? "YES" : "NO");
	}
	return 0;
}
