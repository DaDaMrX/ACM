#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int k, a, b;
	scanf("%d%d%d", &k, &a, &b);
	if (a / k == 0 && b % k || b / k == 0 && a % k)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", a / k + b / k);
	}
	return 0;
}
