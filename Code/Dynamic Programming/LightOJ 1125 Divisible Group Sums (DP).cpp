#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int a[210];
ll dp[210][15][25];

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        printf("Case %d:\n", cas);
        while (q--)
        {
            int d, m;
            scanf("%d%d", &d, &m);
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i <= n; i++) dp[i][0][0] = 1;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    for (int k = 0; k < d; k++)
                    {
                        dp[i][j][k] += dp[i - 1][j][k];
                        dp[i][j][k] += dp[i - 1][j - 1][((k - a[i]) % d + d) % d];
                    }
            printf("%lld\n", dp[n][m][0]);
        }
    }
    return 0;
}