/*
HDU 3032 Nim or not Nim (博弈+Nim游戏+拆分)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int n, a[N];

int sg(int x)
{
	if (x % 4 == 0) return x - 1;
	if (x % 4 == 3) return x + 1;
	return x;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int nim = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			nim ^= sg(a[i]);
		}
		if (nim) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}