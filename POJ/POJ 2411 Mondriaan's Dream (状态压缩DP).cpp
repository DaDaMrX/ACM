#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 12;
int n, m;
ll dp[N][1 << N];

bool ok(int S)
{
	int i = 0;
	while (i < m)
	{
		if (S >> i & 1)
		{
			i++;
			if (i == m) return false;
			if ((S >> i & 1) == 0) return false;
			i++;
		}
		else
		{
			i++;
		}
	}
	return true;
}

bool check(int S, int T)
{
	int i = 0;
	while (i < m)
	{
		if (S >> i & 1)
		{
			if ((T >> i & 1) == 0)
			{
				i++;
				continue;
			}
			i++;
			if (i == m) return false;
			if (!( (S >> i & 1) & (T >> i & 1) )) return false;
			i++;
		}
		else
		{
			if (T >> i & 1) i++;
			else return false;
		}
	}
	return true;
}

int main()
{
	while (scanf("%d%d", &n, &m), n)
	{
		if (m > n) swap(m, n);
		for (int S = 0; S < ( 1 << m); S++)
			dp[0][S] = ok(S) ? 1 : 0;
		for (int i = 1; i < n; i++)
			for (int S = 0; S < ( 1 << m); S++)
			{
				dp[i][S] = 0;
				for (int T = 0; T < ( 1 << m); T++)
					if (check(S, T)) dp[i][S] += dp[i - 1][T];
			}
		printf("%lld\n", dp[n - 1][( 1 << m) - 1]);
	}
	return 0;
}