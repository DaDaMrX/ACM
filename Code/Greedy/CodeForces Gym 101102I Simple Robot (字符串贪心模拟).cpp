//CodeForces Gym101102I Simple Robot (字符串贪心模拟)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

char s[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d%s", &n, &m, s);
		int len = strlen(s);
		int l = 0, r = 0, u = 0, d = 0;
		int x = 0, y = 0, ans = 0;
		for (int i = 0; i < len; i++)
		{
			switch (s[i])
			{
				case '>':
					if (r - l + 1 == m && y == r) ans++;
					else y++, r = max(r, y);
					break;
				case '<':
					if (r - l + 1 == m && y == l) ans++;
					else y--, l = min(l, y);
					break;
				case 'v':
					if (d - u + 1 == n && x == d) ans++;
					else x++, d = max(d, x);
					break;
				case '^':
					if (d - u + 1 == n && x == u) ans++;
					else x--, u = min(u, x);
					break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
