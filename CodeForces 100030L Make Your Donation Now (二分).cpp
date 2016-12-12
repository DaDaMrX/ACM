/********************************************************************************
CodeForces 100030L Make Your Donation Now (二分)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int a[N], b[N], n;

ll sum[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sum[n] = a[n];
	for (int i = n - 1; i >= 1; i--) sum[i] = sum[i + 1] + a[i];

	int ans;
	ll ans_sum = 0;
	for (int i = 1; i <= 2 * n; i++)
	{
		int p = i <= n ? a[i] : b[i - n];
		int k1 = lower_bound(b + 1, b + n + 1, p) - b - 1;
		int k2 = upper_bound(a + 1, a + n + 1, p) - a;
		int middle = n - k1 - (n + 1 - k2);

		ll s = (ll)middle * p + sum[k2];
		if (s > ans_sum)
		{
			ans_sum = s;
			ans = p;
		}
		else if (s == ans_sum && p < ans)
		{
			ans = p;
		}
	}

	printf("%d %I64d\n", ans, ans_sum);
	return 0;
}
