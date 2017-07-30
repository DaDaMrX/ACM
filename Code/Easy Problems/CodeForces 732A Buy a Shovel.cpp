/****************************************************************************
 * CodeForces 732A Buy a Shovel
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int k, r;
	scanf("%d%d", &k, &r);
	int i;
	for (i = 1; i < 10; i++)
	{
		int t = i * k % 10;
		if (t == 0 || t == r) break;
	}
	printf("%d\n", i);
	return 0;
}

