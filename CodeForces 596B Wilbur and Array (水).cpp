/*
CodeForces 596B Wilbur and Array (水)
从b[]到0变
从左到右扫，每次贪心优先满足当前高度
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

int n, b[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	ll ans = 0, now = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += abs(b[i] - now);
		now = b[i];
	}
	printf("%I64d\n", ans);
	return 0;
}
