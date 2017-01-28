/****************************************************************************
 * CodeForces 762A k-th divisor
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

ll d[N];
int t;

int main()
{
	ll n; int k;
	scanf("%I64d%d\n", &n, &k);
	ll s = sqrt(n);
	t = 0;
	ll i;
	for (i = 1; i <= s; i++)
		if (n % i == 0)
		{
			d[++t] = i;
			if (t == k) break;
		}
	if (i <= s)
	{
		printf("%I64d\n", i);
		return 0;
	}
	if (s * s == n)
	{
		if (k >= 2 * t) printf("-1\n");
		else printf("%I64d\n", n / d[2 * t - k]);
	}
	else
	{
		if (k > 2 * t) printf("-1\n");
		else printf("%I64d\n", n / d[2 * t - k + 1]);
	}
	return 0;
}

