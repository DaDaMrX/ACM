#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 505
int a[N], b[N], c[N], ab[N * N], x;
int la, lb, lc, lab, lx;
int main()
{
	int cnt = 0;
	while (~scanf("%d%d%d", &la, &lb, &lc))
	{
		cnt++; printf("Case %d:\n", cnt);
		for (int i = 1; i <= la; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= lb; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= lc; i++) scanf("%d", &c[i]);
		lab = 0;
		for (int i = 1; i <= la; i++)
			for (int j = 1; j <= lb; j++)
				ab[++lab] = a[i] + b[j];
		sort(ab + 1, ab + 1 + lab);
		lab = unique(ab + 1, ab + 1 + lab) - ab;
		scanf("%d", &lx);
		for (int i = 1; i <= lx; i++)
		{
			scanf("%d", &x);
			int j;
			for (j = 1; j <= lc; j++)
			{
				int key = x - c[j];
				if (*lower_bound(ab + 1, ab + 1 + lab, key) == key)	break;
			}
			if (j <= lc) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}