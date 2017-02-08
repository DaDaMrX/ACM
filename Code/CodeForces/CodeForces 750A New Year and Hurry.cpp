/****************************************************************************
 * CodeForces 750A New Year and Hurry
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
	int n, k;
	scanf("%d%d", &n, &k);
	int s = 240 - k;
	int time = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		time += i * 5;
		if (time > s) break;
	}
	printf("%d\n", i - 1);
	return 0;
}

