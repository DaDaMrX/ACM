#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const double eps = 1e-8;

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
int sgn(double x)
{
	if (abs(x) < eps) return 0;
	return x > 0 ? 1 : -1;
}
bool intersection(Segment seg1, Segment seg2)
{
	return
		min(seg1.a.x, seg1.b.x) < max(seg2.a.x, seg2.b.x) &&
		min(seg2.a.x, seg2.b.x) < max(seg1.a.x, seg1.b.x) &&
		min(seg1.a.y, seg1.b.x) < max(seg2.a.y, seg2.b.y) &&
		min(seg2.a.y, seg2.b.y) < max(seg1.a.y, seg1.a.y) &&
		sgn(cross(seg1.b - seg1.a, seg2.a - seg1.a)) * sgn(cross(seg1.b - seg1.a, seg2.b - seg1.a)) <= 0 &&
		sgn(cross(seg2.b - seg2.a, seg1.a - seg2.a)) * sgn(cross(seg2.b - seg2.a, seg1.b - seg2.a)) <= 0;
}
double norm(Vector A)
{
	return sqrt(A.x * A.x + A.y * A.y);
}
double dist(Point p1, Point p2)
{
	return norm(p2 - p1);
}

int n;
Point p[4 * N];
Segment seg[3 * N];
double map[4 * N][4 * N];

void floyd(int n)
{
	for (int k = 0; k <= n; k++)
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				if (map[i][k] < INF && map[k][j] < INF)
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

int main()
{
	while (scanf("%d", &n), ~n)
	{
		p[0] = Point(0.0, 5.0);
		int numPoint = 1, numSeg = 1;
		for (int i = 1; i <= n; i++)
		{
			double x, yy1, y2, y3, y4;
			scanf("%lf%lf%lf%lf%lf", &x, &yy1, &y2, &y3, &y4);
			p[numPoint++] = Point(x, yy1);
			p[numPoint++] = Point(x, y2);
			p[numPoint++] = Point(x, y3);
			p[numPoint++] = Point(x, y4);
			seg[numSeg++] = Segment(Point(x, 0.0), Point(x, yy1));
			seg[numSeg++] = Segment(Point(x, y2), Point(x, y3));
			seg[numSeg++] = Segment(Point(x, y4), Point(x, 10.0));
		}
		p[numPoint] = Point(10.0, 5.0);
		numSeg--;

		for (int i = 0; i <= numPoint; i++)
			for (int j = 0; j <= numPoint; j++)
			{
				if (i == j)
				{
					map[i][j] = map[j][i] = 0;
					continue;
				}
				Segment s(p[i], p[j]);
				int k;
				for (k = 1; k <= numSeg; k++)
					if (intersection(s, seg[k])) break;
				if (k <= numSeg) map[i][j] = map[j][i] = INF;
				else map[i][j] = map[j][i] = dist(p[i], p[j]);
			}

		floyd(numPoint);

		printf("%.2lf\n", map[0][numPoint]);
	}
	return 0;
}

/*
18
1 4 6 6.5 8
3.4 4 4.5 6.5 8
4 4 6 6.5 8
5.3 4 4.5 6.5 9
6 4 6 6.5 8
7 4 6 6.5 8
7.001 2 7 8 9
8.567 3 4.5 6 7
9.1 4 6 6.5 8
9.4 4 4.5 6.5 8
9.435 4 6 6.5 8
9.45 4 4.5 6.5 9
9.66 4 6 6.5 8
9.77 4 6 6.5 8
9.8 2 7 8 9
9.85 4 6 6.5 8
9.8501 4 6 6.5 8
9.999 3 4.5 6 7
3
1 9 9.1 9.2 9.5
3 0.1 0.2 0.3 0.4
9 9 9.1 9.2 9.5
-1

10.54
27.56
*/