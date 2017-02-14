//CodeForces Gym 101102H Cinema (字符串扫描)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

char s[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		int len = strlen(s);
		int dp = 0, maxx = 0;
		for (int i = 0; i < len; i++)
		{
			dp = s[i] == '0' ? dp + 1 : 0;
			maxx = max(maxx, dp);
		}
		printf("%s\n", maxx > k ? "yes" : "no");
	}
	return 0;
}
