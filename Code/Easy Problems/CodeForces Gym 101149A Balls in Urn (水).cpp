//CodeForces Gym 101149A Balls in Urn (水)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int main()
{
	int n;
	scanf("%d", &n);
	int maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		maxx = max(maxx ,x);
	}
	printf("%d\n", maxx);
	return 0;
}
