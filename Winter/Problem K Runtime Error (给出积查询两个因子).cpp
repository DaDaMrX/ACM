//Problem K Runtime Error (给出积查询两个因子)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, k, cnt[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		memset(cnt, 0, sizeof(cnt));
		int maxx = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			cnt[x]++;
			maxx = max(maxx, x);
		}

		int x;
		for (x = 1; x <= maxx; x++)
			if (cnt[x] && k % x == 0)
			{
				int y = k / x;
				if (y != x && cnt[y] || y == x && cnt[y] > 1)
				{
					printf("%d %d\n", x, y);
					break;
				}
			}
		if (x > maxx) printf("-1\n");
	}
	return 0;
}
