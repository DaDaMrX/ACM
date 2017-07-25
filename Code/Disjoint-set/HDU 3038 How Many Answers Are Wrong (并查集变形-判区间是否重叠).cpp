#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

int fa[N], sum[N];
void init(int n)
{	
	for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x)
{
	if (fa[x] != x)
	{
		int t = fa[x];
		fa[x] = find(t);
		sum[x] += sum[t];
	}
	return fa[x];
}


int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		init(n);
		memset(sum, 0, sizeof(sum));
		int ans = 0;
		while (m--)
		{
			int a, b, s;
			scanf("%d%d%d", &a, &b, &s);
			a--;
			int aa = find(a), bb = find(b);
			if (aa == bb)
			{
				if (sum[b] - sum[a] != s) ans++;
			}
			else
			{
				fa[bb] = aa;
				sum[bb] = sum[a] - sum[b] + s;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}