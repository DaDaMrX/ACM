/*
HDU 5621 KK's Point (组合数学)
1.没有重复交点，ans=C(n,4) + n = n(n-1)(n-2)(n-3)/24
2.n=1e5, n(n-1)(n-2)(n-3)超long long，也超unsigned long long
3.边除边乘，任意2个相邻的数中一定有一个是2的倍数，任意3个相邻的数中一定有一个是3的倍数
4.n * (n-1) / 2 * (n-2) / 3 * (n-3) 此时会超long long，但刚好不超unsigned long long
5.long long最大值2^63-1,约为1e18，更准确为9e18
6.此题亦可推公式累加，亦可dp
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ull n;
		scanf("%I64u", &n);
		printf("%I64u\n", n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4 + n);
	}
	return 0;
}