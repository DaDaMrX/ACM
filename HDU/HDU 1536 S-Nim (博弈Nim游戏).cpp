/*
HDU 1536 S-Nim (博弈Nim游戏)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;

int sg[N];
int s[110], k;

int dfs(int x)
{
	if (~sg[x]) return sg[x];

	bool vis[N];
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= k; i++)
		if (s[i] <= x)
			vis[dfs(x - s[i])] = true;

	int i = 0;
	while (vis[i]) i++;
	return sg[x] = i;
}

int main()
{
	while (scanf("%d", &k), k)
	{
		for (int i = 1; i <= k; i++) scanf("%d", &s[i]);
		memset(sg, -1, sizeof(sg));
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int l;
			scanf("%d", &l);
			int nim = 0;
			while (l--)
			{
				int h;
				scanf("%d", &h);
				nim ^= dfs(h);
			}
			if (nim) printf("W");
			else printf("L");
		}
		printf("\n");
	}
	return 0;
}