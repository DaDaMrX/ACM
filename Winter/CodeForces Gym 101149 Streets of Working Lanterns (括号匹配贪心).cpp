//CodeForces Gym 101149 Streets of Working Lanterns (括号匹配贪心)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;

char s[N], st[N];
int t;

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	if (len & 1)
	{
		printf("Impossible\n");
		return 0;
	}
	int l = 0, r = 0, q = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(') l++;
		else if (s[i] == ')') r++;
		else q++;
	}
	
	int left = 0;
	if (r > l) left += r - l;
	left += (q - abs(r - l)) / 2;

	int cnt = 0;
	for (int i = 0; i < len; i++)
		if (s[i] == '?')
		{
			if (cnt < left) s[i] = '(';
			else s[i] = ')';
			cnt++;
		}

	int t = 0, i;
	for (i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			st[t++] = s[i];
		}
		else
		{
			if (t == 0) break;
			t--;
		}
	}

	printf("%s\n", i < len ? "Impossible" : s);
	return 0;
}
