//Problem D Knitting (水)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;

int n, m, k;
int d[N], sum[N];

int main()
{
    while (scanf("%d%d%d", &n, &m, &k), n && m && k)
    {
        sum[0] = 0;
        int more = 0;
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", d + i);
            sum[i] = sum[i - 1] + d[i];
            more += sum[i];
        }
        int delta = sum[k];

        ll ans = n;
        m--;
        int c = m / k;
        int r = m % k;
        for (int i = 1; i <= c; i++)
        {
            ans += n * k + more;
            n += delta;
        }

        for (int i = 1; i <= r; i++)
        {
            n += d[i];
            ans += n;
        }

        printf("%I64d\n", ans);
    }
    return 0;
}
