#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 110
int a[N][N], dp[N][N];
int n;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				scanf("%d", &a[i][j]);

		for (int j = 1; j <= n; j++) dp[n][j] = a[n][j];
		for (int i = n - 1; i > 0; i--)
			for (int j = 1; j <= i; j++)
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];

		printf("%d\n", dp[1][1]);
	}
	return 0;
}