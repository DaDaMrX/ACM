/*
A. Interview with Oleg
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 110;

int n;
char s[N];

int main()
{
	scanf("%d%s", &n, s);
	int i = 0;
	while (i <= n - 3)
	{
		if (s[i] != 'o' || s[i + 1] != 'g' || s[i + 2] != 'o')
		{
			printf("%c", s[i]);
			i++;
			continue;
		}
		printf("***");
		i += 3;
		while (s[i] == 'g' && s[i + 1] == 'o') i += 2;
	}
	while (i < n) printf("%c", s[i++]);
	printf("\n");
	return 0;
}
