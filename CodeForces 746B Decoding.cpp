/********************************************************************************
CodeForces 746B Decoding
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e3 + 10;

int n;
char s[N];

int main()
{
	scanf("%d%s", &n, s);
	if (n & 1)
	{
		for (int i = n - 2; i >= 1; i -= 2) printf("%c", s[i]);
		printf("%c", s[0]);
		for (int i = 2; i <= n - 1; i += 2) printf("%c", s[i]);
	}
	else
	{
		for (int i = n - 2; i >= 0; i -= 2) printf("%c", s[i]);
		for (int i = 1; i <= n - 1; i += 2) printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}