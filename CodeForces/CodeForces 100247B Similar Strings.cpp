/*
CodeForces 100247B Similar Strings
用map
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

map<string, int> mp;
char s[N];
int n;

map<char, char> mp2;
string change(char s[])
{
	mp2.clear();
	string str = "";
	int len = strlen(s);
	char num = '1';
	for (int i = 0; i < len; i++)
	{
		if (mp2[s[i]] == 0) mp2[s[i]] = num++;
		str += mp2[s[i]];
	}
	return str;
}

int main()
{
	scanf("%d", &n);
	mp.clear();
	ll ans = 0;
	while (n--)
	{
		scanf("%s", s);
		string str = change(s);
		ans += mp[str]++;
	}
	printf("%I64d\n", ans);
	return 0;
}
