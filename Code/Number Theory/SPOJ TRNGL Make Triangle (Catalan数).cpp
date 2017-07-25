#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e5 + 7;
const int N = 1e3 + 10;

ll cat[N];
void catalan(int n)
{
    memset(cat, 0, sizeof(cat));
    cat[0] = cat[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            cat[i] = (cat[i] + cat[j] * cat[i - j - 1] % mod) % mod;
}

int main()
{
    int T;
    scanf("%d", &T);
    catalan(1005);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        printf("%lld\n", cat[n - 2]);
    }
    return 0;
}