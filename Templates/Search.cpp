/*
BFS 

约定：
1. 地图为n行m列的字符矩阵，下标从0开始，可以在in_range()函数中修改
2. '#'为墙，'F'为终点，可以在bfs()函数中修改
3. step[][]数组，初始化-1，既标记是否走过，又标记走过的步数
4. 新扩展点合法性的判断是bfs的核心，此模板中包含了最基本的判断
	1. 检查是否越界
	2. 检查是否为墙
	3. 检查是否已经走过
	4. 检查是否为终点
	5.普通合法点，入队
*/

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

int n, m;
char map[N][N];
int step[N][N];

bool in_range(Point p)
{
	return P.x >= 0 && P.x < n && P.y >= 0 && p.y < m;
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
			//是否越界 是否为墙 是否已经走过
			if (!in_range(to) || map[to.x][to.y] == '#' || step[to.x][to.y] != -1) continue;
			step[to.x][to.y] = step[from.x][from.y] + 1;
			if (map[to.x][to.y] == 'F') return step[to.x][to.y];
			q.push(to);
		}
	}
}