#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 110;
class Map
{
private:
	int n, m;
	char map[N][N];
	struct Point
	{
		int x, y;
		Point() {};
		Point(int x, int y) : x(x), y(y) {};
		Point operator+(Point a)
		{
			return Point(this->x + a.x, this->y + a.y);
		}
	};
	Point dir[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
				 {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
	int count(int i, int j)
	{
		Point from(i, j);
		int sum = 0;
		for (int k = 0; k < 8; k++)
		{
			Point to = from + dir[k];
			if (map[to.x][to.y] == '*') sum++;
		}
		return sum;
	}
public:
	Map() {};
	Map(int n, int m) : n(n), m(m)
	{
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++) 
			scanf("%s", &map[i][1]);
	}
	void check()
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (map[i][j] == '.')
					map[i][j] = count(i, j) + '0';
	}
	void print()
	{
		for (int i = 1; i <= n; i++)
			printf("%s\n", &map[i][1]);
	}
};
int main()
{
	int n, m, cnt = 0;
	while (scanf("%d%d", &n, &m), n)
	{
		cnt++;
		if (cnt > 1) printf("\n");
		Map map(n, m);
		map.check();
		printf("Field #%d:\n", cnt);
		map.print();
	}
	return 0;
}