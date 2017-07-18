//Problem E Minesweeper (水)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;

int n, m;
char map[N][N];

typedef struct Point
{
	int x, y;
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
} Vector;
Point operator+(Point P, Vector V)
{
	return Point(P.x + V.x, P.y + V.y);
}
Vector dir[8] = { Vector(0, 1), Vector(1, 0), Vector(0, -1), Vector(-1, 0),
 Vector(1, 1), Vector(1, -1), Vector(-1, 1), Vector(-1, -1) };

void deal(Point from)
{
    for (int i = 0; i < 8; i++)
    {
        Point to = from + dir[i];
        if (map[to.x][to.y] != '*') map[to.x][to.y]++;
    }
}

int main()
{
    while (scanf("%d%d", &n, &m), n)
    {
        memset(map, '0', sizeof(map));
        for (int i = 1; i <= n; i++) scanf("%s", map[i] + 1);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (map[i][j] == '.') map[i][j] = '0';
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (map[i][j] == '*') deal(Point(i, j));
        for (int i = 1; i <= n; i++) map[i][m + 1] = '\0';

        for (int i = 1; i <= n; i++) printf("%s\n", map[i] + 1);
    }
    return 0;
}
