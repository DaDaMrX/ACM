/****************************************************************************
 * CodeForces 752A Santa Claus and a Place in a Class
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
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	char pos;
	if (k & 1) pos = 'L', k++;
	else pos = 'R';
	k /= 2;
	int lane = k / m;
	int desk = k % m;
	if (desk) lane++;
	else desk = m;
	printf("%d %d %c\n", lane, desk, pos);
	return 0;
}

