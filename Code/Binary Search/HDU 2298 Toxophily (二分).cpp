#include <cstdio>
#include <cstring>
#include <cmath>
const double PI2 = 3.1415926535 / 2;
const double g = 9.8;
const double eps = 1e-8;
double x, y, v;
double trajectory(double theta)
{
	double a = x * tan(theta);
	double b = (g * x * x);
	double c = 2 * v * v * cos(theta) * cos(theta);
	return a - b / c;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (int I = 1; I <= T; I++)
	{
		scanf("%lf%lf%lf", &x, &y, &v);
		double left = 0, right = PI2;
		while (right - left > eps)
		{
			double mid = left + (right - left) / 2;
			double yy = trajectory(mid);
			if (yy < y) left = mid;
			else right = mid;
		}
		if (PI2 - left < eps) printf("-1\n");
		else printf("%.6lf\n", left);
	}
	return 0;
}