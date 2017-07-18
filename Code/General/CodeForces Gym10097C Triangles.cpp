// CodeForces Gym10097C Triangles
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	int ans = a[n] - a[1] + 1;
	if (ans >= a[1] + a[2]) return printf("NO\n"), 0;
	printf("YES\n%d\n", ans);
	return 0;
}

