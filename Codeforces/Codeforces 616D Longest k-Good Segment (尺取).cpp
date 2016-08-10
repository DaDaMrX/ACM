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
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int n, k;
int a[N];
int flag[N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	memset(flag, 0, sizeof(flag));
	int left = 1, right = 1, cnt = 0;
	int ans = 0, ans_left, ans_right;
	while (right <= n)
	{
		flag[a[right]]++;
		if (flag[a[right]] == 1) cnt++;
		right++;

		while (cnt > k)
		{
			flag[a[left]]--;
			if (flag[a[left]] == 0) cnt--;
			left++;
		}

		int len = right - left;
		if (len > ans)
		{
			ans = len;
			ans_left = left;
			ans_right = right - 1;
		}
	}

	printf("%d %d\n", ans_left, ans_right);
	return 0;
}