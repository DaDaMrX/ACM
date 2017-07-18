//Problem G Game of Cards (SG)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int p, k, n, a[N];

int sg[N];
int dfs(int x)
{
	if (sg[x] != -1) return sg[x];
	bool vis[15];
	memset(vis, false, sizeof(vis));
	for (int i = 0; i <= k; i++)
	{
		if (i >= x) break;
		int left = x - i;
		if (a[left] > left) continue;
		left -= a[left];
		vis[dfs(left)] = true;
	}
	int i = 0;
	while (vis[i]) i++;
	return sg[x] = i;
}

int main()
{
	scanf("%d%d", &p, &k);
	int ans = 0;
	while (p--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		memset(sg, -1, sizeof(sg));
		int t = dfs(n);
		ans ^= t;
	}
	printf("%s\n", ans ? "Alice can win." : "Bob will win.");
	return 0;
}
