/*
HDU 3183 A Magic Lamp (贪心+RMQ)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

char s[N];
int m;

int dp[N][20], mm[N];
void ST(int n)
{
	mm[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		mm[i] = ((i & (i - 1))) == 0 ? mm[i - 1] + 1 : mm[i - 1];
		dp[i][0] = i;
	}
	for (int j = 1; j <= mm[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			int x = dp[i][j - 1], y = dp[i + (1 << (j - 1))][j - 1];
			dp[i][j] = s[x] <= s[y] ? x : y;
		}
}
int rmq(int left, int right)
{
	int k = mm[right - left + 1];
	int x = dp[left][k], y = dp[right - (1 << k) + 1][k];
	return s[x] <= s[y] ? x : y;
}

int main()
{
	while (~scanf("%s%d", s + 1, &m))
	{
		int len = strlen(s + 1);
		ST(len);
		int left = 1, right = m + 1;
		int sum = len - m;
		bool flag = false;
		while (sum--)
		{
			left = rmq(left, right);
			if (s[left] != '0' || flag)
			{
				printf("%c", s[left]);
				flag = true;
			}
			left++; right++;
		}
		if (!flag) printf("0");
		printf("\n");
	}
	return 0;
}