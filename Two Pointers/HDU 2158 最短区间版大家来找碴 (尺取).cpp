/*
HDU 2158 最短区间版大家来找碴 (尺取)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int n, m;
int a[N];
bool flag[1000010];
int num[1000010];

int main()
{
	while (scanf("%d%d", &n, &m), n)
	{
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		while (m--)
		{
			memset(flag, false, sizeof(flag));
			int sum = 0;
			int q;
			scanf("%d", &q);
			for (int i = 1; i <= q; i++)
			{
				int t;
				scanf("%d", &t);
				if (!flag[t])
				{
					flag[t] = true;
					sum++;
				}
			}

			memset(num, 0, sizeof(num));
			int left = 1, right = 1;
			int cnt = 0;
			int ans = INF;
			while (true)
			{
				while (right <= n && cnt < sum)
				{
					if (flag[a[right]])
					{
						num[a[right]]++;
						if (num[a[right]] == 1) cnt++;
					}
					right++;
				}


				if (cnt < sum) break;

				ans = min(ans, right - left);

				if (flag[a[left]])
				{
					num[a[left]]--;
					if (!num[a[left]]) cnt--;
				}
				left++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}