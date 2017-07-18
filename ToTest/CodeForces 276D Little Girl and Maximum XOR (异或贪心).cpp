#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	ll l, r;
	scanf("%lld%lld\n", &l, &r);
	int i;
	for (i = 62; i >= 0; i--)
		if ((1ll << i & l) ^ (1ll << i & r)) break;
	printf("%lld\n", (1ll << (i + 1)) - 1);
	return 0;
}
