/*
HDU 1159 Common Subsequence (LCS)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

char a[N], b[N];
int dp[N][N];

int main()
{
	while (~scanf("%s%s", a, b))
	{
		int la = strlen(a);
		int lb = strlen(b);
		for (int i = 0; i <= la; i++) dp[i][0] = 0;
		for (int j = 0; j <= lb; j++) dp[0][j] = 0;
		for (int i = 1; i <= la; i++)
			for (int j = 1; j <= lb; j++)
			{
				if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		printf("%d\n", dp[la][lb]);
	}
	return 0;
}