/********************************************************************************
CodeForces 746D Green and Black Tea
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int n, k, a, b;
	scanf("%d%d%d%d", &n, &k, &a, &b);
	char ta = 'G', tb = 'B';
	if (a > b) swap(a, b), swap(ta, tb);
	int x = b / (a + 1);
	int m = b % (a + 1);
	if (x + (m > 0) > k)
	{
		printf("NO\n");
		return 0;
	}
	if (m == 0)
	{
		for (int j = 1; j <= x; j++) printf("%c", tb);
		for (int i = 1; i <= a; i++)
		{
			printf("%c", ta);
			for (int j = 1; j <= x; j++) printf("%c", tb);
		}
	}
	else
	{
		for (int j = 1; j <= x + 1; j++) printf("%c", tb);
		for (int i = 1; i < m; i++)
		{
			printf("%c", ta);
			for (int j = 1; j <= x + 1; j++) printf("%c", tb);
		}
		for (int i = 1; i <= a + 1 - m; i++)
		{
			printf("%c", ta);
			for (int j = 1; j <= x; j++) printf("%c", tb);
		}
	}
	printf("\n");
	return 0;
}
