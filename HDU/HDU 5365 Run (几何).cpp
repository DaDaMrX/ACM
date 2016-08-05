/*
HDU 5365 Run (几何)
1.整数点只能组成正方形，不能组成正三角形，正五边形，正六边形，证明略
2.n=20，O(n^4)枚举
3.判断四个点能否构成正方形，比较6个距离，避免double，用距离的平方
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 25;

struct Point
{
	int x, y;
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};
int dist2(Point A, Point B)
{
	int dx = A.x - B.x, dy = A.y - B.y;
	return dx * dx + dy * dy;
}

int n;
Point p[N];
int d[6];

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
		int ans = 0;
		for (int i = 1; i <= n - 3; i++)
			for (int j = i + 1; j <= n - 2; j++)
				for (int k = j + 1; k <= n - 1; k++)
					for (int l = k + 1; l <= n; l++)
					{
						d[0] = dist2(p[i], p[j]);
						d[1] = dist2(p[i], p[k]);
						d[2] = dist2(p[i], p[l]);
						d[3] = dist2(p[j], p[k]);
						d[4] = dist2(p[j], p[l]);
						d[5] = dist2(p[k], p[l]);
						sort(d, d + 6);
						if (d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5]) ans++;
					}
		printf("%d\n", ans);
	}
	return 0;
}