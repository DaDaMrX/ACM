/*
CodeForces 625A Guest From the Past (水)
如果塑料瓶饮料价格a小于玻璃瓶饮料净价格b-c，则全买a，相等也全买a

否则，优先买b-c，但要注意，当剩余钱数大于b-c但小于b的时候，就不能买b-c了，
为保证每次都能顺利买b-c，现在n当中减去一个b，然后全买b-c，在用减去的那个b买一个b-c，
最后，剩下的钱如果还能买的话就再全买a

特判：当b-c<a,但n-b为负数的情况，即b-c便宜，但钱数却不够b，就只能买a了
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
	else
	{
		if (n < b)
		{
			printf("%I64d\n", n / a);
			return 0;
		}
		ll ans = 0;
		ans = (n - b) / (b - c) + 1;
		ll left = (n - b) % (b - c) + c;
		ans += left / a;
		printf("%I64d\n", ans);
	}
	return 0;
}
