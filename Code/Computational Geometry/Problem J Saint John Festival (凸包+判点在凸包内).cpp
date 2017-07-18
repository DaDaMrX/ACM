//Problem J Saint John Festival (凸包+判点在凸包内)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const double eps = 1e-8;
const int N = 1e4 + 10;

typedef struct Point
{
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
} Vector;
Vector operator-(Point A, Point B)    
{
    return Vector(A.x - B.x, A.y - B.y);
}

double dot(Vector A, Vector B)
{
    return A.x * B.x + A.y * B.y;
}
double norm(Vector A)
{
    return sqrt(dot(A, A));
}

double dist(Point A, Point B)
{
	double dx = A.x - B.x;
	double dy = A.y - B.y;
	return sqrt(dx * dx + dy * dy);
}

double cross(Vector A, Vector B)
{
	return A.x * B.y - B.x * A.y;
}

double cross(Point A ,Point O, Point B)
{
    return cross(A - O, B - O);
}

int sign(double x)
{
    if(abs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}

int n, m;
Point p[N], c[N];
Point referPoint;
bool cmp1(Point p1, Point p2)
{
	if (sign(p1.y - p2.y) != 0) return p1.y < p2.y;
	return p1.x < p2.x;
}
bool cmp2(Point p1, Point p2)
{
	Vector A = p1 - referPoint, B = p2 - referPoint;
	int sgn = sign(cross(A, B));
	if (sgn != 0) return sgn > 0;
	return norm(A) < norm(B);
}
void graham()
{
	sort(p + 1, p + n + 1, cmp1);
	referPoint = p[1];
	sort(p + 2, p + n + 1, cmp2);
	m = 0;
	c[++m] = p[1];
	c[++m] = p[2];
	for (int i = 3; i <= n; i++)
	{
		while (cross(p[i] - c[m], c[m] - c[m - 1]) > 0)
			m--;
		c[++m] = p[i];
	}
}

bool in_convex(Point P)
{
	if (sign(cross(P, c[1], c[2])) > 0) return false;
	if (sign(cross(P, c[1], c[m])) < 0) return false;

	int low = 2, high = m;
	while (high - low > 1)
	{
		int mid = low + high >> 1;
		int sgn = sign(cross(P, c[1], c[mid]));
		if (sgn == 0) 
			return sign(dist(P, c[1]) - dist(c[mid], c[1])) <= 0 ? true : false;
		if (sgn < 0) low = mid;
		else high = mid;
	}

	return sign(cross(P, c[low], c[high])) <= 0 ? true : false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
	graham();

	int q, ans = 0;
	scanf("%d", &q);
	while (q--)
	{
		Point P;
		scanf("%lf%lf", &P.x, &P.y);
		if (in_convex(P)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
