#include <cstdio>
#include <cstring>
#define N 110
struct student
{
	int solve, score;
	char time[10];
}stu[N];
int sum[6];
int n;
void input()
{
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%*c%s", &stu[i].solve, stu[i].time);
		sum[stu[i].solve]++;

		if (stu[i].solve == 5) stu[i].score = 100;
		else if (stu[i].solve == 0) stu[i].score = 50;
		else stu[i].score = 0;
	}
	for (int i = 1; i <= 4; i++) sum[i] /= 2;
}
void rank()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= sum[i]; j++)
		{
			int mini;
			char mint[20] = "99:99:99";
			for (int k = 1; k <= n; k++)
				if (stu[k].solve == i && !stu[k].score && strcmp(stu[k].time, mint) < 0)
				{
					strcpy(mint, stu[k].time);
					mini = k;
				}
			stu[mini].score = 10 * (i + 5) + 5;
		}
		for (int k = 1; k <= n; k++)
			if (stu[k].solve == i && !stu[k].score) stu[k].score = 10 * (i + 5);
	}
}
void output()
{
	for (int i = 1; i <= n; i++) printf("%d\n", stu[i].score);
	printf("\n");
}
int main()
{
	while (scanf("%d", &n), ~n)
	{
		input();
		rank();
		output();
	}
	return 0;
}