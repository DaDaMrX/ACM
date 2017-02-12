//Problem C Too Many Coins (排序)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

int n, s, a[N];
struct Coin
{
	int type;
	ll sum;
} coin[N];

int t[N];

bool cmp1(Coin& c1, Coin& c2)
{
	if (c1.sum != c2.sum) return c1.sum > c2.sum;
	return c1.type > c2.type;
}

bool cmp2(Coin& c1, Coin& c2)
{
	return c1.type < c2.type;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &s);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		sort(a, a + n);

		int c = 0;
		ll sum = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] != a[i - 1])
			{
				coin[c].type = a[i - 1];
				coin[c].sum = sum;
				sum = 0;
				c++;
			}
			sum += a[i];
		}
		coin[c].type = a[n - 1];
		coin[c].sum = sum;
		c++;
		sort(coin, coin + c, cmp1);

		sum = 0;
		int cnt;
		for (cnt = 0; cnt < c; cnt++)
		{
			sum += coin[cnt].sum;
			if (sum >= s) break;
		}
		if (cnt >= c)
		{
			printf("Impossible\n");
			continue;
		}

		for (int i = 0; i <= cnt; i++) t[i] = coin[i].type;
		sort(t, t + cnt + 1);
		for (int i = 0; i <= cnt; i++) printf("%d ", t[i]);
		printf("\n");
	}
	return 0;
}
