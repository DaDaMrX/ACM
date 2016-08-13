/*
HDU 5251 矩形面积 (凸包+旋转卡壳)
找到对踵点后在垂直方向再找到最大宽度
另解：线段树+扫面线
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double INF = 1e100;
const double eps = 1e-6;
const int N = 1e3 + 10;

struct Point
{
	double x, y;
	Point() {};
	Point(double x, double y) : x(x), y(y) {};
};
typedef Point Vector;
struct Segment
{
	Point a, b;
	Segment() {};
	Segment(Point a, Point b) :a(a), b(b) {};
};
bool operator!=(Vector A, Vector B)
{
	return A.x != B.x || A.y != B.y;
}
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
double norm(Vector A)
{
	return sqrt(A.x * A.x + A.y * A.y);
}
double dist(Point p1, Point p2)
{
	return norm(p2 - p1);
}
double dist(Point p, Segment seg)
{
	return abs(cross(seg.b - seg.a, p - seg.a)) / norm(seg.b - seg.a);
}

int n, m;
Point p[4 * N], convex[4 * N];
Point refer;

bool cmp1(Point p1, Point p2)
{
	if (abs(p1.y - p2.y) > eps) return p1.y < p2.y;
	return p1.x < p2.x;
}
bool cmp2(Point p1, Point p2)
{
	double c = cross(p1 - refer, p2 - refer);
	if (abs(c) > eps) return c > 0;
	return norm(p1 - refer) < norm(p2 - refer);
}
int graham(int n)
{
	sort(p + 1, p + 1 + n, cmp1);
	refer = p[1];
	sort(p + 2, p + 1 + n, cmp2);
	int m = 0;
	convex[m++] = p[1];
	convex[m++] = p[2];
	for (int i = 3; i <= n; i++)
	{
		while (cross(p[i] - convex[m - 1], convex[m - 1] - convex[m -2]) > 0)
			m--;
		convex[m++] = p[i];
	}
	return m;
}

double f(double k, Point p)
{
	return p.y - k * p.x;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int I = 1; I <= T; I++)
	{
		scanf("%d", &n);
		int num = 1;
		for (int i = 1; i <= n; i++)
		{
			int x1, yy1, x2, y2, x3, y3, x4, y4;
			scanf("%d%d%d%d%d%d%d%d", &x1, &yy1, &x2, &y2, &x3, &y3, &x4, &y4);
			p[num++] = Point(x1, yy1);
			p[num++] = Point(x2, y2);
			p[num++] = Point(x3, y3);
			p[num++] = Point(x4, y4);
		}
		m = graham(4 * n);

		double ans = INF;
		for (int i = 0; i < m; i++)
		{
			Segment seg(convex[i], convex[(i + 1) % m]);
			double maxh = 0;
			for (int j = 0; j < m; j++)
			{
				maxh = max(maxh, dist(convex[j], seg));
			}

			double k2 = (seg.b.y - seg.a.y) / (seg.b.x - seg.a.x);
			double k = -1 / k2;
			double minb = INF, maxb = -INF;
			for (int j = 0; j < m; j++)
			{
				double b = f(k, convex[j]);
				minb = min(minb, b);
				maxb = max(maxb, b);
			}

			double d = (maxb - minb) * cos(atan(k));
			double area = maxh * d;
			ans = min(ans, area);
		}

		printf("Case #%d:\n", I);
		printf("%.0lf\n", ans);
	}
	return 0;
}