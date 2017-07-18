// Codeforces Gym100694B Far Manager
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int p, n, m;
	scanf("%d%d%d", &p, &n, &m);
	int ans = INF;
	ans = min(ans, m);
	ans = min(ans, m / p + m % p);
	ans = min(ans, m / p + 1 + p - m % p);
	int t = n / p + (n % p > 0);
	int d = n - m;
	ans = min(ans, t + d);
	ans = min(ans, t + d / p + d % p);
	ans = min(ans, t + d / p + 1 + p - d % p);
	printf("%d\n", ans);
	return 0;
}
