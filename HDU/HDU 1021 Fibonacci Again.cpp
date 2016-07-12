#include <cstdio>
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		if (n == 0 || n == 1)
		{
			printf("no\n");
			continue;
		}
		if (n == 2)
		{
			printf("yes\n");
			continue;
		}
		if (n % 4 == 2) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}