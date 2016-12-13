/********************************************************************************
Problem K. Bracket Sequence (水)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

char s[N];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(') 
		{
			cnt++;
		}
		else
		{
			if (cnt == 0)
			{
				printf("IMPOSSIBLE\n");
				return 0;
			}
			cnt--;
		}
	}
	printf("%s", s);
	for (int i = 1; i <= cnt; i++) printf(")");
	printf("\n");
	return 0;
}
