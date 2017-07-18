/********************************************************************************
Problem H. Game with the Stones (博弈)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

bool check(int n)
{
	while (n && n & 1) n >>= 1;
	return n == 0 ? true : false;
}

int main()
{
	int n;
	scanf("%d", &n);
	int m = 0;
	while (n--)
	{
		int a;
		scanf("%d", &a);
		m = max(m, a);
	}
	printf("%s\n", check(m) ? "Mike" : "Constantine");
	return 0;
}
