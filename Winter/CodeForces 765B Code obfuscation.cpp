//CodeForces 765B Code obfuscation
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 510;

bool flag[30];
char s[N];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	memset(flag, false, sizeof(flag));
	flag[0] = true;
	bool can = true;
	for (int i = 0; i < len; i++)
	{
		if (flag[s[i] - 'a']) 
		{
			flag[s[i] - 'a' + 1] = true;
		}
		else
		{
			can = false;
			break;
		}
	}
	printf("%s\n", can ? "YES" : "NO");
	return 0;
}
