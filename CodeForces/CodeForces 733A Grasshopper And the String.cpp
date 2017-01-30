/****************************************************************************
 * CodeForces 733A Grasshopper And the String
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
	int len = strlen(s);
	int last = -1, ans = 0;
	for (int i = 0; i < len; i++)
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
		{
			ans = max(ans, i - last);
			last = i;
		}
	ans = max(ans, len - last);
	printf("%d\n", ans);
	return 0;
}

