/*
HDU 1527 取石子游戏 (威佐夫博弈)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int a, b;
	while (~scanf("%d%d", &a, &b))
	{
		if (a > b) swap(a, b);
		int k = b - a;
		int aa = k * (1 + sqrt(5)) / 2;
		if (a == aa) printf("0\n");
		else printf("1\n");
	}

	return 0;
}