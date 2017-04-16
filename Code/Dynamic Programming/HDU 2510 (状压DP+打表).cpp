#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 20;

int dp[(1 << (N + 1)) + 10];
int ans[30];

int count(int S)
{
	int cnt = 0;
	while (S) S &= S - 1, cnt++;
	return cnt;
}

void init()
{
	memset(ans, 0, sizeof(ans));
	dp[(1 << 1) + 0] = 0; dp[(1 << 1) + 1] = 1;
	for (int n = 2; n <= N; n++)
	{
		int sum = n * (n + 1) / 2;
		for (int S = 0; S < (1 << n); S++)
		{
			int SS = (S ^ (S >> 1)) & ~(1 << (n - 1));
			dp[(1 << n) + S] = count(S) + dp[(1 << (n - 1)) + SS];
			if (2 * dp[(1 << n) + S] == sum) ans[n]++;
		}
	}
	ans[21] = 0;
	ans[22] = 0;
	ans[23] = 431095;
	ans[24] = 822229;
}

int main()
{
	init();
	int n;
	while (scanf("%d", &n), n) printf("%d %d\n", n, ans[n]);
	return 0;
}
