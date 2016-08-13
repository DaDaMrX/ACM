/*
HDU 1850 Being a Good Boy in Spring Festival (博弈+Nim游戏)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;

int n, a[N];

int main()
{
	while (scanf("%d", &n), n)
	{
		int nim = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			nim ^= a[i];
		}
		if (!nim)
		{
			printf("0\n");
			continue;
		}
		int ans = 0;
		for (int i = 0; i <= n; i++)
			if (a[i] > (nim ^ a[i])) ans++;
		printf("%d\n", ans);
	}
	return 0;
}