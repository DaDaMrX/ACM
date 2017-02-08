/*
POJ 1654 Area (计算几何多边形面积)
1.叉积结果除以2才是三角形面积
2.结果只能为整数或.5
3.用abs对long long求绝对值编译不通过，要用llabs
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;
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

Vector dir[10] = { {0, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 0},
					{0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1} };
char s[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		Point last(0, 0);
		long long ans = 0;
		for (int i = 0; s[i] != '5'; i++)
		{
			Point now = last + dir[s[i] - '0'];
			ans += cross(now, last);
			last = now;
		}
		if (ans & 1) printf("%lld.5\n", llabs(ans) / 2);
		else printf("%lld\n", llabs(ans) / 2);
	}
	return 0;
}