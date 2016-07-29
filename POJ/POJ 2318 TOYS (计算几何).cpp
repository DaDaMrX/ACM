/*
POJ 2318 TOYS (计算几何)
对每一个间隔，枚举每一个点，判断是否在间隔两边的线段异侧
1.因为每个点只会在一个间隔中出现，已经确定的点就不再判断
2.y1已经在cmath中定义为函数了
*/
#include <cstdio>
#include <cstring>
#include <cmath>
const int INF = 0x7f7f7f7f;
const int N = 5e3 + 10;
const double eps = 1e-6;

struct Point
{
	double x, y;
	Point() {};
	Point(double x, double y) : x(x), y(y) {};
};
typedef Point Vector;
struct Segment
{
	Point up, down;
	Segment() {};
	Segment(Point up, Point down) :up(up), down(down) {};
};
Vector operator+(Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator-(Vector A, Vector B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
double dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}
double cross(Vector A, Vector B)
{
	return A.x * B.y - B.x * A.y;
}

int n, m, x1, yy1, x2, y2;
Segment seg[N];
Point p[N];
bool vis[N];

bool middle(Segment left, Point p, Segment right)
{
	return cross((p - left.down), (p - left.up)) * cross((p - right.down), (p - right.up)) < eps;
}

int main()
{
	int cas = 0;
	while (scanf("%d%d%d%d%d%d", &n, &m, &x1, &yy1, &x2, &y2), n)
	{
		cas++;
		if (cas > 1) printf("\n");
		seg[0] = Segment(Point(x1, yy1), Point(x1, y2));
		for (int i = 1; i <= n; i++)
		{
			int u, l;
			scanf("%d%d", &u, &l);
			seg[i] = Segment(Point(u, yy1), Point(l, y2));
		}
		seg[n + 1] = Segment(Point(x2, yy1), Point(x2, y2));
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			p[i] = Point(x, y);
		}

		memset(vis, false, sizeof(vis));
		for (int i = 0; i <= n; i++)
		{
			int cnt = 0;
			for (int j = 1; j <= m; j++)
				if (!vis[j] && middle(seg[i], p[j], seg[i + 1]))
					cnt++, vis[j] = true;
			printf("%d: %d\n", i, cnt);
		}
	}
	return 0;
}