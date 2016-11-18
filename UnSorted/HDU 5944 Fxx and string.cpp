/*
HDU 5944 Fxx and string
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;

char s[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			for (int p = 2; p <= n; p++)
			{
				int j = i * p, k = j * p;
				if (j > n || k > n) break;
				if (s[i] == 'y' && s[j] == 'r' && s[k] == 'x') ans++;
				else if (s[i] == 'x' && s[j] == 'r' && s[k] == 'y') ans++;
			}
		printf("%I64d\n", ans);
	}
	return 0;
}
