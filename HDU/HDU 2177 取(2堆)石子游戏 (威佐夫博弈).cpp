/*
HDU 2177 取(2堆)石子游戏 (威佐夫博弈)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const double gold = (1 + sqrt(5)) / 2;

bool Wythoff(int a, int b)
{
	int k = b - a;
	int aa = k * gold;
	if (aa == a) return true;
	return false;
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b), a)
	{
		if (Wythoff(a, b))
		{
			printf("0\n");
			continue;
		}
		printf("1\n");
		for (int i = 1; i <= a; i++)
			if (Wythoff(a - i, b - i))
			{
				printf("%d %d\n", a - i, b - i);
				break;
			}
		for (int i = 1; i <= a; i++)
			if (Wythoff(a - i, b))
			{
				printf("%d %d\n", a - i, b);
				break;
			}
		if (a == b) continue;
		for (int i = 1; i <= b; i++)
		{
			int aa = a, bb = b - i;
			if (aa > bb) swap(aa, bb);
			if (Wythoff(aa, bb))
			{
				printf("%d %d\n", aa, bb);
				break;
			}
		}
	}
	return 0;
}