/*
UVa 10066 The Twin Towers (LCS)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;

int a[N], b[N];
int n1, n2;
int dp[N][N];

int main()
{
	int cnt = 0;
	while (scanf("%d%d", &n1, &n2), n1)
	{
		for (int i = 1; i <= n1; i++) scanf("%d", &a[i]);
		for (int j = 1; j <= n2; j++) scanf("%d", &b[j]);
		for (int i = 0; i <= n1; i++) dp[i][0] = 0;
		for (int j = 0; j <= n2; j++) dp[0][j] = 0;
		for (int i = 1; i <= n1; i++)
			for (int j = 1; j <= n2; j++)
			{
				if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		printf("Twin Towers #%d\n", ++cnt);
		printf("Number of Tiles : %d\n\n", dp[n1][n2]);
	}
	return 0;
}