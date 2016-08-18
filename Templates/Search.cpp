struct Point
{
	int x, y;
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};
typedef Point Vector;
Point operator+(Point P, Vector V)
{
	return Point(P.x + V.x, P.y + V.y);
}
Vector dir[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

char map[N][N];
int step[N][N];

bool wall(Point p)
{
	return P.x >= 1 && P.x <= n && P.y >= 1 && p.y <= n;
}
queue<Point> q;
int bfs(Point start)
{
	while (!q.empty()) q.pop();
	memset(step, -1, sizeof(step));
	q.push(start); step[start.x][start.y] = 0;
	while (!q.empty())
	{
		Point from = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point to = from + dir[i];
			if (!wall(to) || map[to.x][to.y] == '#') continue;
			if (map[to.x][to.y] == 'F') return step[from.x][from.y] + 1;
			q.push(to); step[to.x][to.y] = step[from.x][from.y] + 1;
		}
	}
}