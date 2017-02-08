/*
CodeForces 625A Guest From the Past (水)
1. 如果塑料瓶饮料价格a小于玻璃瓶饮料净价格b-c，则全买a，相等也全买a
2. 否则，优先买b-c，但要注意，当剩余钱数大于b-c但小于b的时候，就不能买b-c了，
为保证每次都能顺利买b-c，先在n当中减去一个c，然后全买b-c，ans = (n-c)/(b-c),
此时剩余的钱数(n-c)%(b-c)+c < b，不够买一瓶b饮料，此时再全部买a，ans += ((n-c)%(b-c)+c)/a
3. 特判：当b-c<a且n<c时，n-c为负，此时只能买a
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
	ll n, a, b, c;
	scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
	if (a <= b - c)
	{
		printf("%I64d\n", n / a);
	}
	else if (n < c)
	{
		printf("%I64d\n", n / a);
	}
	else
	{
		printf("%I64d\n", (n - c) / (b - c) + ((n - c) % (b - c) + c) / a);
	}
	return 0;
}
