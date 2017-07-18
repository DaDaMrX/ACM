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
	for (int cas = 1; cas <= T; cas++)
	{
		int t, d;
		scanf("%d%d", &t, &d);
		printf("Case %d: ", cas);
		if (t & 1) printf("0\n");
		else printf("%.8f\n", 1.0 / (t + 1));
	}
	return 0;
}
