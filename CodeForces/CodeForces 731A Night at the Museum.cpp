/****************************************************************************
 * CodeForces 731A Night at the Museum
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

char s[N];

int main()
{
	scanf("%s", s);
	char p = 'a';
	int ans = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		ans += min((s[i] - p + 26) % 26, (p - s[i] + 26) % 26);
		p = s[i];
	}
	printf("%d\n", ans);
	return 0;
}

