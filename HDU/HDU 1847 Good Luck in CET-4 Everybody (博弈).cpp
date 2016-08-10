/*
HDU 1847 Good Luck in CET-4 Everybody (博弈)
只有一堆，且策略集合有规律可循，故首先打表找规律
可以得知当n % 3 == 0时先手必败Cici赢，反之先手必胜Kiki赢
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		if (n % 3) printf("Kiki\n");
		else printf("Cici\n");
	}
	return 0;
}