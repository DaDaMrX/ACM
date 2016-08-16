/*
POJ 3264 Balanced Lineup (RMQ)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 5e4 + 10;

int a[N];
int dpmax[N][20], dpmin[N][20], mm[N];
void ST(int n)
{
	mm[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		mm[i] = ((i & (i - 1))) == 0 ? mm[i - 1] + 1 : mm[i - 1];
		dpmax[i][0] = dpmin[i][0] = a[i];
	}
	for (int j = 1; j <= mm[n]; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			dpmax[i][j] = max(dpmax[i][j - 1], dpmax[i + (1 << (j - 1))][j - 1]);
			dpmin[i][j] = min(dpmin[i][j - 1], dpmin[i + (1 << (j - 1))][j - 1]);
		}
}
int rmq(int left, int right)
{
	int k = mm[right - left + 1];
	int maxx = max(dpmax[left][k], dpmax[right - (1 << k) + 1][k]);
	int minx = min(dpmin[left][k], dpmin[right - (1 << k) + 1][k]);
	return maxx - minx;
}

int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ST(n);
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", rmq(a, b));
	}
	return 0;
}