#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

char s[N];
bool t[30][30];
bool l[30], r[30];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	memset(t, false, sizeof(t));
	memset(l, false, sizeof(l));
	memset(r, false, sizeof(r));
	for (int i = 0; i < len; i++)
	{
		int y = s[i] - 'A';
		for (int j = 0; j < 26; j++)
			if (l[j]) t[j][y] = true;
		l[y] = true;
	}
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char s1[5], s2[5];
		scanf("%s%s", s1, s2);
		printf("%s\n", t[s1[0] - 'A'][s2[0] - 'A'] ? "YA" : "TIDAK");
	}
    return 0;
}
