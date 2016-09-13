#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;
char s[N];
int n, a, b, ans;
int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%d", &a);
	ans = INF;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &b);
		if (s[i - 1] == 'R' && s[i] == 'L')
			ans = min(ans, b - a >> 1);
		a = b;
	}
	if (ans < INF) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}