#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500010
inline int lowbit(int x)
{
	return x & (-x);
}
int a[N], c[N], s[N];
int t[N];
int n;
long long ans;
void update(int i, int value)
{
	for (; i <= n; i += lowbit(i)) c[i] += value;
}
int sum(int i)
{
	int ans = 0;
	for (; i; i -= lowbit(i)) ans += c[i];
	return ans;
}
int find(int x, int a[], int l, int r)
{
	int left = l, right = r;
	int mid = left + (right - left) / 2;
	while (left <= right)
	{
		if (a[mid] == x) break;
		if (x < a[mid]) right = mid - 1;
		else left = mid + 1;
		mid = left + (right - left) / 2;
	}
	return mid;
}
void discrete()
{
	for (int i = 1; i <= n; i++) t[i] = a[i];
	sort(t + 1, t + 1 + n);
	for (int i = 1; i <= n; i++) a[i] = find(a[i], t, 1, n);
}
int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		discrete();
		memset(c, 0, sizeof(c));
		ans = 0;
		for (int i = n; i; i--)
		{
			update(a[i], 1);
			ans += sum(a[i] - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}