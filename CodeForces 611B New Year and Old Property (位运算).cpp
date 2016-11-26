/*
CodeForces 611B New Year and Old Property (位运算)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2000 + 10;

ll a[N];

int main()
{
	int k = 0;
	for (int i = 1; i <= 63; i++)
	{
		ll t = pow(2, i + 1) - 1;
		for (int j = i - 1; j >= 0; j--, k++)
		{
			a[k] = t;
			a[k] ^= (ll)1 << j;
		}
	}
	
	ll l, r;
	scanf("%I64d%I64d", &l, &r);
	int i = 0;
	while (a[i] < l) i++;
	int j = 1952;
	while (a[j] > r) j--;
	printf("%d\n", j - i + 1);
	return 0;
}
