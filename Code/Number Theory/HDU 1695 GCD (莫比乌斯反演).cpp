#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int prime[N], mu[N], sum[N];
bool flag[N];
void Mobius(int n)
{
    memset(flag, false, sizeof(flag));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!flag[i]) prime[tot++] = i, mu[i] = -1;
        for (int j = 0; j < tot && i * prime[j] <= n; j++)
        {
            int k = i * prime[j];
            flag[k] = true;
            if (i % prime[j] == 0) { mu[k] = 0; break; }
            else mu[k] = -mu[i];
        }
    }
}

ll f(int n, int m, int d)
{
    if (n > m) swap(n, m);
    n /= d; m /= d;
    ll ans = 0;
    for (int i = 1, last = 1; i <= n; i = last + 1)
    {
        last = min(n / (n / i), m / (m / i));
        ans += (ll)(sum[last] - sum[i - 1]) * (n / i) * (m / i);
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    Mobius(1e5);
    sum[0] = 0;
    for (int i = 1; i <= 1e5; i++) sum[i] = sum[i - 1] + mu[i];
    for (int cas = 1; cas <= T; cas++)
    {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if (k == 0)
        {
            printf("Case %d: 0\n", cas);
            continue;
        }
        if (b > d) swap(b, d);
        ll ans = f(b, d, k) - f(b, b, k) / 2;
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}

/*********************
Input
2
1 3 1 5 1
1 11014 1 14409 9

Output
Case 1: 9
Case 2: 736427
*********************/