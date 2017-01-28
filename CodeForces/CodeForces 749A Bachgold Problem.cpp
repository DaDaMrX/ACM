/****************************************************************************
 * CodeForces 749A Bachgold Problem
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
	int n;
	scanf("%d", &n);
	int k = n / 2;
	printf("%d\n", k);
	for (int i = 1; i < k; i++) printf("2 ");
	printf("%d\n", n & 1 ? 3 : 2);
	return 0;
}

