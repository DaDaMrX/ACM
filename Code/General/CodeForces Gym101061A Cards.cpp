// CodeForces Gym101061A Cards
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		ll x;
		scanf("%I64d", &x);
		int cnt = 0;
		while ((x & 1) == 0) x >>= 1, cnt++;
		printf("%s Box\n", cnt & 1 ? "Second" : "First");
	}
	return 0;
}