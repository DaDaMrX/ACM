#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 25
const double eps = 1e-4;
double run[N], cycle[N];
int n, t;
double calc(double r)
{
	double k = t - r;
	double cheater = r / run[n] + k / cycle[n];
	double minx = r / run[1] + k / cycle[1] - cheater;
	for (int i = 2; i < n; i++) 
		minx = min(minx, r / run[i] + k / cycle[i] - cheater);
	return minx;
}
int main() 
{
	while (~scanf("%d%d", &t, &n)) 
	{
		for (int i = 1; i <= n; i++) scanf("%lf%lf", &run[i], &cycle[i]);
		double left = 0, right = t;
		while (right - left > eps)
		{
			double range = (right - left) / 3;
			double mid1 = left + range;
			double mid2 = mid1 + range;
			if (calc(mid1) < calc(mid2)) left = mid1;
			else right = mid2;
		}
		double hour = calc(left);
		if (hour > 0) printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", hour * 3600, left, t - left);
		else printf("The cheater cannot win.\n");
	}
	return 0;
}