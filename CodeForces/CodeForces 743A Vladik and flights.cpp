/****************************************************************************
 * CodeForces 743A Vladik and flights
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
	int n, a, b;
	scanf("%d%d%d%*c", &n, &a, &b);
	if (a == b)
	{
		printf("0\n");
		return 0;
	}
	if (a > b) swap(a, b);
	char sa, sb;
	int i;
	for (i = 1; i <= a; i++) scanf("%c", &sa);
	for (; i <= b; i++) scanf("%c", &sb);
	printf("%d\n", sa == sb ? 0 : 1);
	return 0;
}

