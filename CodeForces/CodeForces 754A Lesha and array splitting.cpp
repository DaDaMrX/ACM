/****************************************************************************
 * CodeForces 754A Lesha and array splitting
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

int n, a[N], f[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	f[1] = 1;
	int i = 1;
	while (i <= n && a[i] == 0) f[i++] = 1;
	if (i > n)
	{
		printf("NO\n");
		return 0;
	}
	f[i] = 1;
	for (i++; i <= n; i++)
	{
		if (a[i] == 0) f[i] = f[i - 1];
		else f[i] = f[i - 1] + 1;
	}
	printf("YES\n");
	printf("%d\n", f[n]);
	printf("1 ");
	for (int i = 2; i <= n; i++)
		if (f[i] != f[i - 1])
			printf("%d\n%d ", i - 1, i);
	printf("%d\n", n);
	return 0;
}

