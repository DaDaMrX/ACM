/*
CodeForces 630H Benches (组合数学)
ans = A(5,5) * C(n,5) * C(n,5) = 120 * C(n,5)^2 
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

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
    int n;
    while (~scanf("%d", &n))
    {
        ll t = C(n, 5);
        printf("%I64d\n", 120 * t * t);
    }
    return 0;
}
