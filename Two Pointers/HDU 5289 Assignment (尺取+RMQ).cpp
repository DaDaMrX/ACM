/*
HDU 5289 Assignment (尺取+RMQ)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int a[N], n, k;

int dpmax[N][20], dpmin[N][20], mm[N];
void ST(int n)
{
	mm[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		mm[i] = ((i & (i - 1))) == 0 ? mm[i - 1] + 1 : mm[i - 1];
		dpmax[i][0] = a[i];
		dpmin[i][0] = a[i];
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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		ST(n);
		ll ans = 0;
		int right = 2;
		for (int left = 1; left <= n; left++)
		{
			while (right <= n && rmq(left, right) < k) right++;
			ans += right - left;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}