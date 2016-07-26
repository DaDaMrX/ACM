#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50010
int bit[N], a[N], b[N];
int n, ans;
inline int lowbit(int i) { return i & -i; }
void discrete()
{
	for (int i = 1; i <= n; i++) b[i] = a[i];
	sort(b + 1, b + 1 + n);
	int size = unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + 1 + size, a[i]) - b;
}
void add(int i, int key)
{
	for (; i <= n; i += lowbit(i)) bit[i] += key;
}
int sum(int i)
{
	int ans = 0;
	for (; i; i -= lowbit(i)) ans += bit[i];
	return ans;
}
int main()
{
	while (~scanf("%d", &n))
	{
		memset(bit, 0, sizeof(bit));
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i]++;
		discrete();
		ans = 0;
		for (int i = n; i; i--)
		{
			ans += sum(a[i] - 1);
			add(a[i], 1);
		}
		int now = ans;
		for (int i = 1; i < n; i++)
		{
			int small = sum(a[i] - 1);
			now = now - small + n - small - 1;
			ans = min(ans, now);
		}
		printf("%d\n", ans);
	}
	return 0;
}