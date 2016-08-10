/*
POJ 1704 Georgia and Bob (博弈+Nim游戏变形)
1.从右到左，每两个棋子作为一组，若n为奇数，则在0位置补一个棋子
2.每组两个棋子之间的格数就是nim游戏中每堆石子的个数，组与组之间的空格不起作用
PS：输入之后先排序
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, a[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		a[0] = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int nim = 0;
		for (int i = n; i > 0; i -= 2)
			nim ^= a[i] - a[i - 1] - 1;
		if (nim) printf("Georgia will win\n");
		else printf("Bob will win\n");
	}
	return 0;
}