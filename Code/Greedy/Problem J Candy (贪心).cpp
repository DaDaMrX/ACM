//Problem J Candy (贪心)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 20;
const int M = 60;

int n, m, a[N], c[M];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[x]++;
		}
		for (int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			c[x]++;
		}

		int i, j = 0;
		for (i = 5; i <= 15; i++)
			if (a[i])
			{
				j++;
				while (j <= 50 && c[j] < a[i]) j++;
				if (j > 50) break;
			}

		printf("%s\n", i <= 15 ? "NO" : "YES");
	}
	return 0;
}
