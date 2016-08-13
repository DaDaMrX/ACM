#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
int a[N];
int n, c, ans;
bool check(int x)
{
	int pre, cur, num = c - 1;
	pre = 0; cur = 1;
	while (num)
	{
		while (cur < n && a[cur] - a[pre] < x) cur++;
		if (cur == n) return false;
		num--; pre = cur; cur++;
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int left = a[1] - a[0];
	for (int i = 2; i < n; i++)
		if (a[i] - a[i - 1] < left) left = a[i] - a[i - 1] < left;
	int right = a[n - 1] - a[0];
	while (left <= right)
	{
		int mid = left + (right - left >> 1);
		if (check(mid)) ans = mid, left = mid + 1;
		else right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}