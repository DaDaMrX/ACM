/****************************************************************************
 * CodeForces 758A Holiday Of Equality
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

int n, a[N];

int main()
{
	scanf("%d", &n);
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d\n", a + i);
		maxx = max(maxx, a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += maxx - a[i];
	printf("%d\n", ans);
	return 0;
}

