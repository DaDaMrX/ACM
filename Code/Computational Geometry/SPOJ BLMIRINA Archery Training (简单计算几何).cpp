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
	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		double x, y, r;
		scanf("%lf%lf%lf", &x, &y, &r);
		double a = atan(y / x);
		double b = asin(r / sqrt(x * x + y * y));
		double l = sqrt(x * x + y * y - r * r);
		double X = l * cos(a + b);
		double Y = l * sin(a + b);
		printf("%.6f %.6f\n", X, Y);
	}
	return 0;
}