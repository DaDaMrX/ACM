#include <cstdio>
#include <cmath>
using namespace std;
double l, n, c, s;
double eps = 1e-5;
double calc(double h)
{
	double R = ((h * h * 4) + (l * l)) / (8 * h);
	double thita = 2 * asin(l / (2 * R));
	return thita * R;
}
int main()
{
	while (scanf("%lf%lf%lf", &l, &n, &c) != EOF)
	{
		if (l < 0 && n < 0 && c < 0)
			break;
		double s;
		s = (1 + n * c) * l;
		double left = 0;
		double right = l / 2;
		double R, mid;
		while (right - left > eps)
		{
			mid = left + (right - left) / 2;
			if (calc(mid) < s) left = mid;
			else right = mid;
		}
		printf("%.3lf\n", mid);
	}
	return 0;
}