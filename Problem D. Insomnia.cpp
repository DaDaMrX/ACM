/********************************************************************************
Problem D. Insomnia
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int n, f[N];

int main()
{
	scanf("%d", &n);
	memset(f, 0, sizeof(f));
	f[1] = 1;
	int mid = n >> 1;
	for (int i = 1; i <= mid; i++)
		for (int j = 2 * i ; j <= n; j += i)
			f[j] += f[i];
	printf("%d\n", f[n]);
	return 0;
}
