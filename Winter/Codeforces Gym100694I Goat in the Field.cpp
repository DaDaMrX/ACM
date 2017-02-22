// Codeforces Gym100694I Goat in the Field
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

char dir[10], s[25], name[25];

int main()
{
	int x, y, n;
	scanf("%d%d%s%d", &x, &y, dir, &n);
	int minx = INF;
	for (int i = 1; i <= n; i++)
	{
		int x1, y1;
		scanf("%s%d%d", s, &x1, &y1);
		int x0 = x, y0 = y, step = 0;

		if (dir[0] == 'L')
		{
			int dy = abs(y0 - y1);
			step = dy / 2 + (dy % 2 > 0);
			x0 -= step;
			int dx = abs(x0 - x1);
			if (x0 < x1) step += dx;
			else if (x0 > x1) step += dx / 3 + (dx % 3 > 0);
		}
		else if (dir[0] == 'R')
		{
			int dy = abs(y0 - y1);
			step = dy / 2 + (dy % 2 > 0);
			x0 += step;
			int dx = abs(x0 - x1);
			if (x0 > x1) step += dx;
			else if (x0 < x1) step += dx / 3 + (dx % 3 > 0);
		}
		else if (dir[0] == 'U')
		{
			int dx = abs(x0 - x1);
			step = dx / 2 + (dx % 2 > 0);
			y0 += step;
			int dy = abs(y0 - y1);
			if (y0 > y1) step += dy;
			else if (y0 < y1) step += dy / 3 + (dy % 3 > 0);
		}
		else
		{
			int dx = abs(x0 - x1);
			step = dx / 2 + (dx % 2 > 0);
			y0 -= step;
			int dy = abs(y0 - y1);
			if (y0 < y1) step += dy;
			else if (y0 > y1) step += dy / 3 + (dy % 3 > 0);
		}

		if (step < minx)
		{
			minx = step;
			strcpy(name, s);
		}
	}
	printf("%s\n", name);
	return 0;
}
