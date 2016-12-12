/********************************************************************************
POJ 1064 Cable master (二分)
两种写法，可以用double二分，也可以*100转化成int二分，推荐后一种。
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;

int n, k;
int a[N];

bool check(int l)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i] / l;
		if (sum >= k) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &k);
	int left = 0, right = 0;
	for (int i = 1; i <= n; i++) 
	{
		double f;
		scanf("%lf", &f);
		a[i] = floor(100 * f);
		right = max(right, a[i]);
	}
	right++;

	while (right - left > 1)
	{
		int mid = left + right >> 1;
		if (check(mid)) left = mid;
		else right = mid;
	}

	printf("%.2f\n", (double)left / 100);
	return 0;
}


/********************************************************************************
POJ 1064 Cable master (二分)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;
const double eps = 1e-5;

int n, k;
double a[N];

bool check(double l)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += floor(a[i] / l);
		if (sum >= k) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &k);
	double left = 0.0, right = 0.0;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%lf", a + i);
		right = max(right, a[i]);
	}

	while (right - left > eps)
	{
		double mid = (left + right) / 2;
		if (check(mid)) left = mid;
		else right = mid;
	}

	printf("%.2f\n", floor(right*100) / 100);
	return 0;
}
