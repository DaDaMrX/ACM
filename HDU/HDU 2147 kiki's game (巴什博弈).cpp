/*
HDU 2147 kiki's game (巴什博弈)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m), n)
	{
		if ((n & 1) && (m & 1)) printf("What a pity!\n");
		else printf("Wonderful!\n");
	}
	return 0;
}