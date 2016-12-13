/********************************************************************************
Problem G. The Last Wish (水)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

char s[N];
bool dict[N], flag[N];
queue<char> q;

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	if (len > 26)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	memset(dict, false, sizeof(dict));
	memset(flag, false, sizeof(flag));
	for (int i = 0; i < len; i++)
	{
		if (dict[s[i] - 'a']) flag[i] = true;
		dict[s[i] - 'a'] = true;
	}
	while (!q.empty()) q.pop();
	for (char c = 'a'; c <= 'z'; c++)
		if (!dict[c - 'a']) 
			q.push(c);
	for (int i = 0; i < len; i++)
	{
		if (!flag[i]) printf("%c", s[i]);
		else printf("%c", q.front()), q.pop();
	}
	printf("\n");
	return 0;
}
