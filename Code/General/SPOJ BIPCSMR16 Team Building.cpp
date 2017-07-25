#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll x, y, z;
		scanf("%lld%lld%lld", &x, &y, &z);
		if (x > y) swap(x, y);
		if (z < y) swap(y, z);
		if (z < x) swap(x, z);
		if (z >= 2 * (x + y)) printf("%lld\n", (x + y));
		else printf("%lld\n", (x + y + z) / 3);
	}
	return 0;
}