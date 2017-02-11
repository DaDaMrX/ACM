//Problem E Epic Professor (水)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

int n, a[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		int maxx = 0;
		for (int i = 1; i <= n; i++) maxx = max(maxx, a[i]);
		int add = 100 - maxx;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] + add >= 50) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
