/********************************************************************************
Problem E. Tests Preparation (状态压缩)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 22;

int n, m;
ll a[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		while (k--)
		{
			int t;
			scanf("%d", &t);
			a[i] |= (ll)1 << t - 1;
		}		
	}

	int ans = INF, ans_state;
	ll ok = ((ll)1 << m) - 1;
	for (int S = 1; S < (1 << n); S++)
	{
		ll sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if ((S >> i) & 1)
			{
				sum |= a[i];
				cnt++;
			}
		if (sum == ok && cnt < ans)
		{
			ans = cnt;
			ans_state = S;
		}
	}

	printf("%d\n", ans);

	int i = 0;
	while (((ans_state >> i) & 1) == 0) i++;
	printf("%d", i + 1);

	for (i++; i < n; i++)
		if ((ans_state >> i) & 1)
			printf(" %d", i + 1);
	return 0;
}
