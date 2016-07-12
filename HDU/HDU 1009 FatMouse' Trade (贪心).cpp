#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010
struct node
{
	int v, c;
	double r;
} a[N];
int m, n;
double ans;
bool cmp(node a, node b)
{
	return a.r > b.r;
}
int main()
{
	while (scanf("%d%d", &m, &n), ~m)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].v, &a[i].c);
			a[i].r = (double)a[i].v / a[i].c;
		}
		sort(a, a + n, cmp);
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (m > a[i].c)
			{
				m -= a[i].c;
				ans += a[i].v;
			}
			else
			{
				ans += a[i].v * ((double)m / a[i].c);
				break;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
