#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int n, a[N], l[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	l[1] = a[1];
	int len = 1;
	for (int i = 2; i <= n; i++)
	{
		int k = upper_bound(l + 1, l + len + 1, a[i]) - l;
		l[k] = a[i];
		len = max(len, k);
	}
	printf("%d\n", len);
	return 0;
}
