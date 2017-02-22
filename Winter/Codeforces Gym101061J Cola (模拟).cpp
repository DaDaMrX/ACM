// Codeforces Gym101061J Cola (Ä£Äâ)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m; 
ll a[N], c[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%I64d", c + i);
		memset(a, 0, sizeof(a));
		int x;
		ll y;
		while (m--)
		{
			scanf("%d%I64d", &x, &y);
			a[x] += y;
		}
		for (int i = 1; i <= n; i++)
			if (a[i] > c[i])
			{
				a[i + 1] += a[i] - c[i];
				a[i] = c[i];
			}
		printf("%I64d\n", a[n + 1]);
		for (int i = 1; i <= n; i++) printf("%I64d%c", a[i], i < n ? ' ' : '\n');
	}
	return 0;
}
