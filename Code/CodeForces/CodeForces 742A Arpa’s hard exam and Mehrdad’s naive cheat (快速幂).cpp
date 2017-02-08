/************************************************************
CodeForces 742A Arpa’s hard exam and Mehrdad’s naive cheat (快速幂)
************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

ll power(ll a, ll n, ll m)
{
	ll ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return ans;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", power(1378, n, 10));
    return 0;
}
