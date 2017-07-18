//POJ 2623 Sequence Median (排序)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 3e5 + 10;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	
	if (n & 1) 
	{
		printf("%d.0\n", a[n / 2]);
		return 0;
	}
	double ans = ((ll)a[n / 2] + a[n / 2 - 1]) / 2.0;
	printf("%.1f\n", ans);
	return 0;
}
