/*
CodeForces 100247A The Power of the Dark Side
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

struct Triple
{
	int x, y, z;

	void sort()
	{
		if (y > x) swap(x, y);
		if (z > x) swap(x, z);
		if (z > y) swap(y, z);
	}
} a[N];
bool flag[N];
int n;

int main()
{
	scanf("%d", &n);
	int max2 = 0, max3 = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		a[i].sort();
		max2 = max(max2, a[i].y);
		max3 = max(max3, a[i].z);
	}
	int ans = 0;
	memset(flag, false, sizeof(flag));
	for (int i = 1; i <= n; i++)
		if (a[i].x > max2 && a[i].y > max3)
		{
			ans++;
			flag[i] = true;
		}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		if (flag[i]) printf("%d ", i);
	return 0;
}
