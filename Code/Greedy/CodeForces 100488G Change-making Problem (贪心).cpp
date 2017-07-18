/********************************************************************************
Round 6 Problem G. Change-making Problem (贪心)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int n, s, a[N];

int main()
{
	scanf("%d%d", &n, &s);
	a[0] = 1;
	int i;	
	for (i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		ll tmp = (ll)t * a[i - 1];
		if (tmp > s) break;
		a[i] = tmp;
	}
	int ans = 0;
	for (i--; i >= 0 && s >= 0; i--)
	{
		ans += s / a[i];
		s %= a[i];
	}
	printf("%d\n", ans);
	return 0;
}
