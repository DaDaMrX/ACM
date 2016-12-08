/************************************************************
Problem D. Broadcasting (水)
数学上ans=ceil(log(n)/log(k+1))，但计算对数特别容易丢失精度，改用while累乘
************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 0;
    ll s = 1;
    while (s < n)
    {
        s *= k + 1;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
