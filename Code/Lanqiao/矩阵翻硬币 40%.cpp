#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	ll n, m;
	scanf("%lld%lld", &n, &m);
	ll ans = (ll)sqrt(n) * (ll)sqrt(m);
	printf("%lld\n", ans);
	return 0;
}
