#include <cstdio>
#include <cstring>
#define N 10
struct balloon
{
	char col[20];
	int num;
}dic[N];
int sum;
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		sum = 0;
		int max = 0, maxi;
		char s[20];
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s);
			int j;
			for (j = 1; j <= sum; j++)
				if (!strcmp(s, dic[j].col))
				{
					dic[j].num++;
					break;
				}
			if (j > sum)
			{
				sum++;
				strcpy(dic[sum].col, s);
				dic[sum].num = 1;
			}
			if (dic[j].num > max) max = dic[maxi = j].num;
		}
		puts(dic[maxi].col);
	}
	return 0;
}