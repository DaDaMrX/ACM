#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

int a[N], b[N], c[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	ll ans = 0;
	while (true)
	{
		b[1] = c[n] = a[1] >> 1;
		for (int i = 2; i <= n; i++) b[i] = c[i - 1] = a[i] >> 1;
		for (int i = 1; i <= n; i++)
		{
			a[i] = b[i] + c[i];
			if (a[i] & 1) ans++, a[i]++;
		}
		int i;
		for (i = 2; i <= n; i++)
			if (a[i] != a[i - 1]) break;
		if (i > n) break;
	}
	printf("%lld\n", ans);
	return 0;
}
