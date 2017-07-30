/****************************************************************************
 * CodeForces 745A Hongcow Learns the Cyclic Shift
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 55;

map<string, bool> m;

int main()
{
	char s[N];
	scanf("%s", s);
	int len = strlen(s);
	string str(s);
	m.clear();
	m[str] = true;
	int ans = 1;
	for (int i = 1; i < len; i++)
	{
		string tmp = str.substr(len - 1, 1) + str.substr(0, len - 1);
		if (!m[tmp]) ans++;
		m[tmp] = true;
		str = tmp;
	}
	printf("%d\n", ans);
	return 0;
}

