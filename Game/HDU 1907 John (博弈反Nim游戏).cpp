/*
HDU 1907 John (博弈反Nim游戏)
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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int nim = 0, cnt = 0;
		while (n--)
		{
			int a;
			scanf("%d", &a);
			if (a > 1) cnt++;
			nim ^= a;
		}
		if ((cnt == 0 && nim == 0) || (cnt > 0 && nim != 0)) printf("John\n");
		else printf("Brother\n");
	}
	return 0;
}