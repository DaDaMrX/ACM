#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 10010
const double eps = 1e-9;
int a[N], b[N], c[N];
int n;
double F(double x)
{
	double maxx = a[0] * x * x + b[0] * x + c[0];
	for (int i = 1; i < n; i++)
		maxx = max(maxx, a[i] * x * x + b[i] * x + c[i]);
	return maxx;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		double left = 0, right = 1010;
		while (right - left > eps)
		{
			double range = (right - left) / 3;
			double mid1 = left + range;
			double mid2 = mid1 + range;
			double result1 = F(mid1);
			double result2 = F(mid2);
			if (result1 < result2) right = mid2;
			else left = mid1;
		}
		printf("%.4f\n", F(left));
	}
	return 0;
}