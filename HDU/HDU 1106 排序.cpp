#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010
int ston(char s[], int a[])
{
	int sum = -1;
	char *p = strtok(s, "5");
	while (p)
	{
		a[++sum] = atoi(p);
		p = strtok(NULL, "5");
	}
	return sum + 1;
}
int main()
{
	char s[N];
	int a[N];
	while (~scanf("%s", s))
	{
		int n = ston(s, a);
		sort(a, a + n);
		for (int i = 0; i <= n - 2; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[n - 1]);
	}
	return 0;
}