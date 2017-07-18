// CodeForces Gym100971F Two Points (数学二次函数求最值)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	double x1, y1, x2, y2;
	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	double vx1, vy1, vx2, vy2;
	scanf("%lf%lf%lf%lf", &vx1, &vy1, &vx2, &vy2);
	double dx = x1 - x2, dy = y1 - y2;
	double dvx = vx1 - vx2, dvy = vy1 - vy2;
	double a = dvx * dvx + dvy * dvy;
	double b = 2 * (dx * dvx + dy * dvy);
	double c = dx * dx + dy * dy;
	double x0 = -b / 2 / a;
	double ans;
	if (x0 > 0) ans = sqrt(c - b * b / 4 / a);
	else ans = sqrt(dx * dx + dy * dy);
	printf("%.10f\n", ans);
	return 0;
}
