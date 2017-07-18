#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int bit[N], n;
inline int lowbit(int x) { return x & -x; }
void init()
{
	memset(bit, 0, sizeof(bit));
}
void add(int i, int x)
{
	for (; i <= n; i += lowbit(i)) bit[i] += x;
}
int sum(int i)
{
	int ans = 0;
	for (; i; i -= lowbit(i)) ans += bit[i];
	return ans;
}

int a[N];
ll cnt[N];
int main()
{
	int m;
	scanf("%d", &m);
	n = 0;
	for (int i = 1; i <= m; i++) scanf("%d", a + i), n = max(n, ++a[i]);
	init();
	for (int i = 1; i <= m; i++)
	{
		add(a[i], 1);
		cnt[i] = sum(n) - sum(a[i]);
	}
	init();
	for (int i = m; i >= 1; i--)
	{
		add(a[i], 1);
		cnt[i] += sum(a[i] - 1);
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++) ans += cnt[i] * (cnt[i] + 1) / 2;
	printf("%lld\n", ans);
	return 0;
}
