/*
Codeforces 616D Longest k-Good Segment (尺取)
前提：连续子序列
条件：不同元素的数目cnt <= k
目标：ans = max{length}
1.用到不同元素的数目，用map查询O(logn)，用标记数组O(1)，本题ai <= 1e6，故用标记数组
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;
const int M = 1e6 + 10;

int n, k;
int a[N];

int cnt[M];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);

	memset(cnt, 0, sizeof(cnt));
	int ans = 0, ansl, ansr;
	int l = 1, r = 1, num = 0;
	while (l <= n)
	{
		while (r <= n && num <= k)
		{
			cnt[a[r]]++;
			if (cnt[a[r]] == 1) num++;
			r++;
		}
		if (num <= k)
		{
			if (r - l > ans)
			{
				ans = r - l;
				ansl = l;
				ansr = r - 1;
			}
			break;
		}

		if (r - 1 - l > ans)
		{
			ans = r - 1 - l;
			ansl = l;
			ansr = r - 2;
		}

		cnt[a[l]]--;
		if (cnt[a[l]] == 0) num--;
		l++;
	}

	printf("%d %d\n", ansl, ansr);
	return 0;
}
