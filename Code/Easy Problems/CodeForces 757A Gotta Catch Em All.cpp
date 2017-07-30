/****************************************************************************
 * CodeForces 757A Gotta Catch Em All
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

char s[N];
map<char, int> m;
int cnt[10];

void init()
{
	m.clear();
	m['B'] = 1;
	m['u'] = 2;
	m['l'] = 3;
	m['b'] = 4;
	m['a'] = 5;
	m['s'] = 6;
	m['r'] = 7;
}

int main()
{
	scanf("%s", s);
	init();
	int len = strlen(s);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < len; i++) cnt[m[s[i]]]++;
	int ans = INF;
	for (int i = 1; i <= 7; i++) ans = min(ans, cnt[i]);
	ans = min(ans, cnt[2] / 2);
	ans = min(ans, cnt[5]/ 2);
	printf("%d\n", ans);
	return 0;
}

