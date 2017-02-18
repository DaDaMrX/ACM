#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int cnt[6];
char s[8];

bool dfs(int i)
{
	if (i == 6) return true;
	if (cnt[i])
	{
		cnt[i]--;
		if (dfs(i + 1)) return true;
	}
	
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 7; i++) cnt[s[i] - 'a' + 1]++;
		printf("%s\n", dfs(1) ? "YES" : "NO");
	}
	return 0;
}
