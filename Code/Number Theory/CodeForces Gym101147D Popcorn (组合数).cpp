// CodeForces Gym101147D Popcorn (组合数)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

ll C(int n, int m)
{
    ll ans = 1;
    m = min(m, n - m);
    int k = n - m;
    for (int i = 1; i <= m; i++)
        ans = ans * (i + k) / i;
    return ans;
}

int main()
{
    freopen("popcorn.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", C(n, m));
    }
    return 0;
}
