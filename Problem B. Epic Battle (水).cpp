/************************************************************
Problem B. Epic Battle (水)
************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 25;

int n, a, sum;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		sum += a;
	}
	printf("%s\n", (sum - n) & 1 ? "Constantine" : "Mike");
	return 0;
}
