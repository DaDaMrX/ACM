#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e3 + 10;

int n, a[N];

int f(int l, int r, int h)
{
	if (l > r) return 0;
	int m = min_element(a + l, a + r + 1) - a;
	return min(r - l + 1, f(l, m - 1, a[m]) + f(m + 1, r, a[m]) + a[m] - h);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	printf("%d\n", f(1, n, 0));
	return 0;
}
