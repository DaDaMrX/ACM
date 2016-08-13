/*
POJ 2653 Pick-up sticks (计算几何)
简单枚举，但要特别注意数据规模为1e5
对每一条线段，若向前检查覆盖掉那些线段，会T
应改为对每一条线段，向后检查是否被覆盖，若被覆盖立刻break
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;
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
bool intersection(Segment seg1, Segment seg2)
{
	Vector vec = seg1.b - seg1.a;
	Vector vec1 = seg2.a - seg1.a;
	Vector vec2 = seg2.b - seg1.a;
	bool b1 = cross(vec1, vec) * cross(vec2, vec) < 0;
	vec = seg2.b - seg2.a;
	vec1 = seg1.a - seg2.a;
	vec2 = seg1.b - seg2.a;
	bool b2 = cross(vec1, vec) * cross(vec2, vec) < 0;
	return b1 && b2;
}

int n;
Segment seg[N];
bool top[N];

int main()
{
	while (~scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf%lf%lf", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
		memset(top, true, sizeof(top));
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (top[i] && intersection(seg[i], seg[j]))
				{
					top[i] = false;
					break;
				}

		printf("Top sticks:");
		int i;
		for (i = 1;i <= n;++i)
			if (top[i]) break;
		printf(" %d", i);
		for (i++; i <= n; i++)
			if (top[i]) printf(", %d", i);
		printf(".\n");
	}
	return 0;
}