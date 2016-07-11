#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 20010
int dragon[N], knight[N];
int n, m, ans;
int main()
{
	while (scanf("%d%d", &n, &m), n)
	{
		for (int i = 0; i < n; i++) scanf("%d", &dragon[i]);
		for (int j = 0; j < m; j++) scanf("%d", &knight[j]);
		sort(dragon, dragon + n);
		sort(knight, knight + m);
		ans = 0;
		int i, j = 0;
		for (i = 0; i < n; i++)
		{
			while (j < m && knight[j] < dragon[i]) j++;
			if (j == m) break;
			ans += knight[j];
			j++;
		}
		if (i < n) printf("Loowater is doomed!\n");
		else printf("%d\n", ans);
	}
	return 0;
}
