#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int x[N], y[N], l[N], r[N];
int s[4 * N], t, a[4 * N];

int dp[4 * N][20], lg[4 * N];
void ST(int n)
{
	lg[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		lg[i] = ((i & (i - 1))) == 0 ? lg[i - 1] + 1 : lg[i - 1];
		dp[i][0] = a[i];
	}
	for (int j = 1; j <= lg[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
}
int rmq(int left, int right)
{
	int k = lg[right - left + 1];
	return max(dp[left][k], dp[right - (1 << k) + 1][k]);
}

int main()
{
	int n;
	scanf("%d", &n);
	t = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", x + i, y + i);
		s[t++] = x[i]; s[t++] = y[i];
	}
	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", l + i, r + i);
		s[t++] = l[i]; s[t++] = r[i];
	}
	sort(s + 1, s + t + 1);
	t = unique(s + 1, s + t + 1) - s;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		int X = lower_bound(s + 1, s + t + 1, x[i]) - s;
		int Y = lower_bound(s + 1, s + t + 1, y[i]) - s;
		a[X]++; a[Y + 1]--;
	}
	for (int i = 1; i < t; i++) a[i] += a[i - 1];
	ST(t - 1);
	for (int i = 1; i <= q; i++)
	{
		int L = lower_bound(s + 1, s + t + 1, l[i]) - s;
		int R = lower_bound(s + 1, s + t + 1, r[i]) - s;
		printf("%d\n", rmq(L, R));
	}
	return 0;
}