//Problem G Heavy Coins (状态压缩) 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 12;

int n, s, a[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &s);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		sort(a, a + n);
		int States = 1 << n, ans = 0;
		for (int S = 0; S < States; S++)
		{
			char str[40];
			itoa(S, str, 2);

			int sum = 0, cnt = 0;
			for (int i = 0; i < n; i++)
				if (S & (1 << i))
					sum += a[i], cnt++;
			if (sum < s) continue;
			
			bool flag = true;
			for (int i = 0; i < n; i++)
				if (S & (1 << i))
				{
					if (sum - a[i] >= s) flag = false;
					else true;
					break;
				}

			if (flag) ans = max(ans, cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}


/*
int n, s, a[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &s);
		for (int i = 1; i <= n; i++) scanf("%d", a + i); 
		sort(a + 1, a + n + 1);

		int sum = 0;
		int cnt;
		for (cnt = 1; cnt <= n; cnt++)
		{
			sum += a[cnt];
			if (sum >= s) break;
		}
		for (int i = cnt; i >= 1; i--)
			if (sum - a[i] >= s)
			{
				sum -= a[i];
				cnt--;
			}

		printf("%d\n", cnt);
	}
	return 0;
}
*/
