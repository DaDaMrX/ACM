/*
POJ 1696 Space Ant (计算几何凸包变式)
1.一定可以走完所有的点
2.开始选取y最小的点作为参考点（y相同选x小的）
3.每次取出极角最小的，下次排序时利用数组头指针前移取出刚选的点
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 60;
const double eps = 1e-10;

struct Point
{
	double x, y;
	int no;
	Point() {};
	Point(double x, double y, int no = -1) : x(x), y(y), no(no) {};
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
double norm(Vector A)
{
	return sqrt(A.x * A.x + A.y * A.y);
}

int n;
Point p[N];
Point referPoint;

bool cmp1(Point p1, Point p2)
{
	if (abs(p1.y - p2.y) > eps) return p1.y < p2.y;
	return p1.x < p2.x;
}
bool cmp2(Point p1, Point p2)
{
	return cross(p1 - referPoint, p2 - referPoint) > 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int no, x, y;
			scanf("%d%d%d", &no, &x, &y);
			p[i] = Point(x, y, no);
		}

		printf("%d", n);
		sort(p, p + n, cmp1);
		printf(" %d", p[0].no);
		referPoint = p[0];
		for (int i = 1; i < n; i++)
		{
			sort(p + i, p + n, cmp2);
			printf(" %d", p[i].no);
			referPoint = p[i];
		}
		printf("\n");
	}
	return 0;
}