/*
POJ 3061 Subsequence (尺取)
前提：连续区间
条件：sum >= k
目标：ans = min{length}
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int n, k;
int a[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

		int ans = INF;
		int left = 1, right = 1, sum = 0;
		while (true)
		{
			while (right <= n && sum < k) sum += a[right++];
			if (sum < k) break;
			ans = min(ans, right - left);
			sum -= a[left++];
		}

		if (ans == INF) printf("0\n");
		else printf("%d\n", ans);
	}
	return 0;
}




int ans = INF;
int l = 1, r = 1, sum = 0;
while (true)
{
	while (r <= n && sum < k) sum += a[r++];
	if (sum < k) break;
	ans = min(ans, r - l);
	sum -= a[l++];
}



