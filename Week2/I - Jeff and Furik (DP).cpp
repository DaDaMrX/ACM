#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 3e3 + 10;

int n, a[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int s = 0;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i] > a[j]) s++;
	int ans = s & 1 ? 1 + s / 2 * 4 : 2 * s;
	printf("%d.0000000\n", ans);
	return 0;
}
