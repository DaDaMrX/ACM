/******************************************************************************
 * CodeForces 760A Petr and a calendar
 ******************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	int m, d;
	scanf("%d%d", &m, &d);
	int t = days[m] - (8 - d);
	printf("%d\n", 1 + t / 7 + (t % 7 > 0));
	return 0;
}

