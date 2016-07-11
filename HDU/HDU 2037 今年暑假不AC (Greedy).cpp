#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100
#define M 1000
struct program
{
	int start, finish, length;
} a[N];
bool time[M];
int n, ans;
bool cmp(program a, program b)
{
	return a.length < b.length;
}
int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].start, &a[i].finish);
			a[i].length = a[i].finish - a[i].start;
		}
		memset(time, true, sizeof(time));
		sort(a, a + n, cmp);
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			int j;
			for (j = a[i].start; j < a[i].finish; j++)
				if (!time[j]) break;
			if (j == a[i].finish)
			{
				ans++;
				for (int j = a[i].start; j < a[i].finish; j++) time[j] = false;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
