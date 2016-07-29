#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 20;
const double eps = 1e-10;

struct Point
{
	double x, y;
	Point() {};
	Point(double x, double y) : x(x), y(y) {};
};
typedef Point Vector;
Vector operator-(Vector A, Vector B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
double cross(Vector A, Vector B)
{
	return A.x * B.y - B.x * A.y;
}
struct Segment
{
	Point a, b;
	Segment() {};
	Segment(Point a, Point b) :a(a), b(b) {};
};
double distan(Point p1, Point p2)
{
	double dx = p2.x - p1.x, dy = p2.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}
bool online(Point p, Segment seg)
{
	return abs(cross(p - seg.a, seg.b - seg.a)) < eps;
}
bool inrec(Point p, Segment seg)
{
	double xleft, xright, yup, ydown;
	if (seg.a.x < seg.b.x) xleft = seg.a.x, xright = seg.b.x;
	else xleft = seg.b.x, xright = seg.a.x;
	if (seg.a.y < seg.b.y) ydown = seg.a.y, yup = seg.b.y;
	else ydown = seg.b.y, yup = seg.a.y;
	return (p.x >= xleft && p.x <= xright && p.y >= ydown && p.y <= yup);
}
bool onseg(Point p, Segment seg)
{
	return online(p, seg) && inrec(p, seg);
}
bool intersection(Segment seg1, Segment seg2)
{
	if (onseg(seg1.a, seg2) || onseg(seg1.b, seg2) || onseg(seg2.a, seg1) || onseg(seg2.b, seg1))
		return false;

	Vector vec = seg1.b - seg1.a;
	Vector vec1 = seg2.a - seg1.a;
	Vector vec2 = seg2.b - seg1.a;
	bool b1 = (cross(vec1, vec) * cross(vec2, vec) < 0);
	vec = seg2.b - seg2.a;
	vec1 = seg1.a - seg2.a;
	vec2 = seg1.b - seg2.a;
	bool b2 = (cross(vec1, vec) * cross(vec2, vec) < 0);
	return b1 && b2;
}

int n;
Point p[4 * N];
double dis[4 * N];
Segment seg[3 * N];
int numPoint, numSeg;
double map[4 * N][4 * N];

bool vis[N];
void dijkstra(int start)
{
	memset(dis, 0x7f, sizeof(dis));
	dis[start] = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i <= numPoint; i++)
	{
		int mini = -1;
		for (int j = 0; j <= numPoint; j++)
			if (!vis[j] && (mini == -1 || dis[j] < dis[mini])) mini = j;
		vis[mini] = true;
		for (int j = 0; j <= numPoint; j++)
			if (map[mini][j] < INF)
				dis[j] = min(dis[j], dis[mini] + map[mini][j]);
	}
}

int main()
{
	while (scanf("%d", &n), ~n)
	{
		p[0] = Point(0, 5); dis[0] = 0;
		numPoint = 1, numSeg = 1;
		for (int i = 1; i <= n; i++)
		{
			double x, yy1, y2, y3, y4;
			scanf("%lf%lf%lf%lf%lf", &x, &yy1, &y2, &y3, &y4);
			p[numPoint++] = Point(x, yy1);
			p[numPoint++] = Point(x, y2);
			p[numPoint++] = Point(x, y3);
			p[numPoint++] = Point(x, y4);
			seg[numSeg++] = Segment(Point(x, 0), Point(x, yy1));
			seg[numSeg++] = Segment(Point(x, y2), Point(x, y3));
			seg[numSeg++] = Segment(Point(x, y4), Point(x, 10));
		}
		p[numPoint] = Point(10, 5);
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
				if (k > numSeg) map[i][j] = map[j][i] = distan(p[i], p[j]);
				else map[i][j] = map[j][i] = INF;
			}

		dijkstra(0);

		printf("%.2lf\n", dis[numPoint]);
	}
	return 0;
}


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 20;
const double eps = 1e-6;

struct Point
{
	double x, y;
	Point() {};
	Point(double x, double y) : x(x), y(y) {};
};
typedef Point Vector;
Vector operator-(Vector A, Vector B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
double cross(Vector A, Vector B)
{
	return A.x * B.y - B.x * A.y;
}
struct Segment
{
	Point a, b;
	Segment() {};
	Segment(Point a, Point b) :a(a), b(b) {};
};
double distan(Point p1, Point p2)
{
	double dx = p2.x - p1.x, dy = p2.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}
bool intersection(Segment seg1, Segment seg2)
{
	Vector vec = seg1.b - seg1.a;
	Vector vec1 = seg2.a - seg1.a;
	Vector vec2 = seg2.b - seg1.a;
	bool b1 = (cross(vec1, vec) * cross(vec2, vec) < 0);
	vec = seg2.b - seg2.a;
	vec1 = seg1.a - seg2.a;
	vec2 = seg1.b - seg2.a;
	bool b2 = (cross(vec1, vec) * cross(vec2, vec) < 0);
	return b1 && b2;
}

int n;
Point p[4 * N];
double dis[4 * N];
Segment seg[3 * N];


int main()
{
	while (scanf("%d", &n), ~n)
	{
		p[0] = Point(0, 5); dis[0] = 0;
		int numPoint = 1, numSeg = 1;
		for (int i = 1; i <= n; i++)
		{
			double x, yy1, y2, y3, y4;
			scanf("%lf%lf%lf%lf%lf", &x, &yy1, &y2, &y3, &y4);
			p[numPoint++] = Point(x, yy1);
			p[numPoint++] = Point(x, y2);
			p[numPoint++] = Point(x, y3);
			p[numPoint++] = Point(x, y4);
			seg[numSeg++] = Segment(Point(x, 0), Point(x, yy1));
			seg[numSeg++] = Segment(Point(x, y2), Point(x, y3));
			seg[numSeg++] = Segment(Point(x, y4), Point(x, 10));
		}
		p[numPoint] = Point(10, 5);
		numSeg--;

		for (int i = 1; i <= numPoint; i++)
		{
			dis[i] = INF;
			int sumj = (i - 1) / 4 * 4;
			for (int j = 0; j <= sumj; j++)
			{
				double len = distan(p[i], p[j]);
				int left;
				if (j == 0) left = 1;
				else left = ((j - 1) / 4 + 1) * 3 + 1;
				int right = (i - 1) / 4 * 3;
				Segment s(p[i], p[j]);
				int k;
				for (k = left; k <= right; k++)
					if (intersection(s, seg[k])) break;
				if (k > right) dis[i] = min(dis[i], dis[j] + len);
			}
		}

		printf("%.2lf\n", dis[numPoint]);
	}
	return 0;
}