#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

typedef struct Point
{
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
} Vector;

Point operator+(Point &P, Vector &V)
{
	return Point(P.x + V.x, P.y + V.y);
}

Vector dir[4] = { Point(-1, 0), Point(0, 1), Point(1, 0), Point(0, -1) };

int a[N][N];

int direct(char c)
{
	switch (c)
	{
		case 'U': return 0;
		case 'R': return 1;
		case 'D': return 2;
		case 'L': return 3;
	}
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	Point p; char s[5]; int k;
	scanf("%d%d%s%d", &p.x, &p.y, s, &k);
	int d = direct(s[0]);
	while (k--)
	{
		if (a[p.x][p.y])
		{
			d = (d + 1) % 4;
			a[p.x][p.y] ^= 1;
			p = p + dir[d];
		}
		else
		{
			d = (d - 1 + 4) % 4;
			a[p.x][p.y] ^= 1;
			p = p + dir[d];
		}
	}
	printf("%d %d\n", p.x, p.y);
	return 0;
}
