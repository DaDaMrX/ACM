/*
CodeForces 630I Parking Lot (组合数学)
ans = 3 * (3 * n - 1) * pow(4, n - 3)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;
typedef long long ll;

ll pow(ll a, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        printf("%I64d\n", 3 * (3 * n - 1) * pow(4, n - 3));
    }
    return 0;
}
