//Problem C Street Lamps (字符串扫描)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

int n;
char s[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%s", &n, s);
		int ans = 0;
		int l = 0, r = -1;
		while (true)
		{
			l = r + 1;
			while (l < n && s[l] == '*') l++;
			if (l >= n) break;
			r = l + 1;
			while (r < n && s[r] == '.') r++;
			int len = r - l;
			if (l > 0) len--;
			if (r < n) len--;
			ans += len / 3 + (len % 3 > 0);
		}
		printf("%d\n", ans);
	}
	return 0;
}
