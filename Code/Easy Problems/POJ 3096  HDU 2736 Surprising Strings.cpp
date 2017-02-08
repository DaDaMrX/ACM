/*
POJ 3096 && HDU 2736 Surprising Strings (水)
字符串N=79，暴力枚举即可
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<char, char> pcc;
const int INF = 0x7f7f7f7f;
const int N = 100;

map<pcc, bool> mp;
char s[N];
int len;
bool surprising;

int main()
{
	while (scanf("%s", s), s[0] != '*')
	{
		len = strlen(s);
		surprising = true;
		for (int i = 0; i <= len - 2; i++)
		{
			mp.clear();
			for (int j = 0; j <= len - 2 - i; j++)
			{
				if (mp[pcc(s[j], s[j + i + 1])])
				{
					surprising = false;
					break;
				}
				mp[pcc(s[j], s[j + i + 1])] = true;
			}
			if (!surprising) break;
		}
		if (surprising) printf("%s is surprising.\n", s);
		else printf("%s is NOT surprising.\n", s);
	}
	return 0;
}