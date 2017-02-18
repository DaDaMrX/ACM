// CodeForces Gym100971K Palindromization (字符串)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

char s[N], t[N];

void del(char s[], int t)
{
	int len = strlen(s);
	for (int i = t; i < len - 1; i++) s[i] = s[i + 1];
	s[len - 1] = '\0';
}

void reverse(char s[])
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) swap(s[i], s[len - 1 - i]);
}

char str[N];
bool pal(char s[])
{
	strcpy(str, s);
	reverse(str);
	return strcmp(str, s) == 0;
}

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	if (pal(s)) return printf("YES\n%d\n", len / 2 + 1), 0;
	int i = 0;
	while (i < len / 2 && s[i] == s[len - 1 - i]) i++;

	strcpy(t, s);
	del(t, i);
	if (pal(t)) return printf("YES\n%d\n", i + 1), 0;

	strcpy(t, s);
	del(t, len - 1 - i);
	if (pal(t)) return printf("YES\n%d\n", len - i), 0;
	
	printf("NO\n");
	return 0;
}
