//Problem B Rock-Paper-Scissors (前缀和)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int n;
char str[N];
int r[N], p[N], s[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%s", &n, str + 1);
		r[0] = p[0] = s[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			r[i] = r[i - 1];
			p[i] = p[i - 1];
			s[i] = s[i - 1];
			if (str[i] == 'R') r[i]++;
			else if (str[i] == 'P') p[i]++;
			else s[i]++;
		}

		int ans = 0;
		for (int nr = 0; nr <= n; nr++)
			for (int np = nr; np <= n; np++)
			{
				int win = 0;
				win += s[nr];
				win += r[np] - r[nr];
				win += p[n] - p[np];
				int loss = 0;
				loss += p[nr];
				loss += s[np] - s[nr];
				loss += r[n] - r[np];
				if (win > loss) ans++;
			}
		
		printf("%d\n", ans);
	}
	return 0;
}
