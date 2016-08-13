#include <cstdio>
#include <cstring>
#define N 25
bool isPrime[N];
int ring[N];
int pr;
bool visit[N];
int n, count;
void setPrime()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < N; i++) if (isPrime[i])
		for (int j = 2 * i; j < N; j += i)
			isPrime[j] = false;
}
void print()
{
	printf("1");
	for (int i = 2; i <= n; i++) printf(" %d", ring[i]);
	printf("\n");
}
void dfs(int i)
{
	if (i > n)
	{
		if (isPrime[ring[n] + 1]) print();
		return;
	}
	for (int j = 2; j <= n; j++)
		if (!visit[j] && isPrime[ring[i - 1] + j])
		{
			ring[++pr] = j;
			visit[j] = true;
			dfs(i + 1);
			pr--;
			visit[j] = false;
		}
}
int main()
{
	setPrime();
	count = 0;
	while (~scanf("%d", &n))
	{
		printf("Case %d:\n", ++count);
		memset(visit, false, sizeof(visit));
		ring[1] = 1; pr = 1;
		dfs(2);
		printf("\n");
	}
	return 0;
}