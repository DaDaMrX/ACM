#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 100 + 10;

int a[N];
char s[N];
ll dp[N][N];

ll f(ll n)
{
    ll ans = 1;
    for (int i = 2; i <= n; i++) ans = ans * i % mod;
    return ans;
}

ll power(ll a, ll n, ll m)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return ans;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++) dp[i][i] = a[i];
        for (int l = 2; l <= n; l++)
        {
            for (int i = 1; i + l - 1 <= n; i++)
            {
                int j = i + l - 1;
                dp[i][j] = 0;
                for (int k = i; k < j; k++)
                {
                    if (s[k] == '+') dp[i][j] = (dp[i][j] + (dp[i][k] + dp[k + 1][j]) % mod) % mod;
                    else if (s[k] == '-') dp[i][j] = (dp[i][j] + (dp[i][k] - dp[k + 1][j]) % mod) % mod;
                    else dp[i][j] = (dp[i][j] + (dp[i][k] * dp[k + 1][j]) % mod) % mod;
                }
                dp[i][j] = (dp[i][j] % mod + mod) % mod;
                dp[i][j] = dp[i][j] * power(l - 1, mod - 2, mod) % mod;
            }
        }
        printf("%lld\n", dp[1][n] * f(n - 1) % mod);
    }
    return 0;
}