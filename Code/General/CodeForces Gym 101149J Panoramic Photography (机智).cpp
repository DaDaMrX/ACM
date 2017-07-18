//CodeForces Gym 101149J Panoramic Photography (机智)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int n;
	scanf("%d", &n);
	ll ans = 0;
	int a = 0, b;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b);
		if (b > a) ans += b - a;
		a = b;
	}	
	printf("%I64d\n", ans);
	return 0;
}
