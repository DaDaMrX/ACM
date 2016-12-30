/********************************************************************************
CodeForces 746A Compote
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int minx = a;
	minx = min(minx, b / 2);
	minx = min(minx, c / 4);
	printf("%d\n", minx * 7);
	return 0;
}
