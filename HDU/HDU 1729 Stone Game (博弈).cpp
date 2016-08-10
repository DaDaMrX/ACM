/*
HDU 1729 Stone Game (博弈)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int dfs(int s, int c)
{
	int q = sqrt(s);
	while (q + q * q >= s) q--;
	if (c > q) return s - c;
	return dfs(q, c);
}

int main()
{
	int n, cas = 0;
	while (scanf("%d", &n), n)
	{
		int nim = 0;
		for (int i = 1; i <= n; i++)
		{
			int s, c;
			scanf("%d%d", &s, &c);
			nim ^= dfs(s, c);
		}
		printf("Case %d:\n", ++cas);
		if (nim) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}