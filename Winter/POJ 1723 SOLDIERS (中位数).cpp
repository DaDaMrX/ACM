//POJ 1723 SOLDIERS (中位数)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;

int n, x[N], y[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d%d", x + i, y + i);

    ll ans = 0;
    int n2 = n / 2;

    sort(y, y + n);
    for (int i = 0; i < n2; i++)
	ans += y[n - 1 - i] - y[i];

    sort(x, x + n);
    for (int i = 0; i < n; i++)
	x[i] -= i;
    sort(x, x + n);
    for (int i = 0; i < n2; i++)
	ans += x[n - 1 - i] - x[i];

    printf("%lld\n", ans);
    return 0;
}
