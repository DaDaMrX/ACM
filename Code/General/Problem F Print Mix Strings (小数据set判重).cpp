// Problem F Print Mix Strings (小数据set判重)
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

char s1[10], s2[10];
int len1, len2;

set<string> s;
set<string>::iterator it;
void dfs(int i, int j, string str)
{
	if (i == len1)
	{
		str += s2 + j;
		s.insert(str);
		return;
	}
	if (j == len2)
	{
		str += s1 + i;
		s.insert(str);
		return;
	}

	dfs(i + 1, j, str + s1[i]);
	dfs(i, j + 1, str + s2[j]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", s1, s2);
		len1 = strlen(s1);
		len2 = strlen(s2);
		s.clear();
		dfs(0, 0, "");
		for (it = s.begin(); it != s.end(); it++)
			cout << *it << endl;
		printf("\n");
	}
	return 0;
}
