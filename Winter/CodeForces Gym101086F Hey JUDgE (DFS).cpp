// CodeForces Gym101086F Hey JUDgE (DFS)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int cnt[10];
char s[10];

bool dfs(int n)
{
	if (n == 6) return true;
	if (cnt[n])
	{
		cnt[n]--;
		if (dfs(n + 1)) return true;
		cnt[n]++;
	}
	for (int i = 1; i <= n / 2; i++)
		if (i == n - i && cnt[i] >= 2 || i != n - i && cnt[i] && cnt[n - i])
		{
			cnt[i]--; cnt[n - i]--;
			if (dfs(n + 1)) return true;
			cnt[i]++; cnt[n - i]++;
		}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 7; i++) 
			cnt[s[i] - 'A' + 1]++;
		printf("%s\n", dfs(1) ? "YES" : "NO");
	}
	return 0;
}
