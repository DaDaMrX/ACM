/*
KMP algorithm
*/
#include <cstdio>
#include <cstring>
const int N = 20;
int next[N];
int kmp(char text[], char pattern[])
{
	int lt = strlen(text);
	int lp = strlen(pattern);
	for (int i = 0, j = -1; i <= lp; i++, j++)
	{
		next[i] = j;
		while (~j && pattern[i] != pattern[j]) j = next[j];
	}
	int ans = 0;
	for (int i = 0, j = 0; i <= lt; i++, j++)
	{
		if (j == lp) ans++;
		while (~j && text[i] != pattern[j]) j = next[j];
	}
	return ans;
}
int main()
{
	char text[N], pattern[N];
	scanf("%s%s", text, pattern);
	printf("%d\n", kmp(text, pattern));
	return 0;
}
/*
Sample Input
ababababa
aba

Sample Output
4
*/