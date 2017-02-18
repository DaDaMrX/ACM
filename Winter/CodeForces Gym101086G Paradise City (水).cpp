// CodeForces Gym101086G Paradise City (水)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

char s[3][3 * N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 3; i++) scanf("%s", s[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int p = (i - 1) * 3, sum = 0;
			for (int x = 0; x < 3; x++)
				for (int y = p; y < i * 3; y++)
					if (s[x][y] == '*') sum += 4;
			ans = max(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}
