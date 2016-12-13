/********************************************************************************
Problem L. Hard Problem (水)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

ll sum[N];
int n;

int main()
{
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%I64d", sum + i);
	for (int i = 1; i <= n; i++) printf("%I64d ", sum[i] - sum[i - 1]);
	return 0;
}
