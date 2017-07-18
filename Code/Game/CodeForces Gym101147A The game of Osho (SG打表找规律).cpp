// CodeForces Gym101147A The game of Osho (SG打表找规律)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int f(int b, int n)
{
	if (b & 1 || b > n)  return n & 1;
	int t = (n - b) % (b + 1);
	if (t == 0) return 2;
	return t & 1 ? 0 : 1;
}

int main()
{
	freopen("powers.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int g, ans = 0;
		scanf("%d", &g);
		for (int i = 1; i <= g; i++)
		{
			int b, n;
			scanf("%d%d", &b, &n);
			ans ^= f(b, n);
		}
		printf("%d\n", ans == 0 ? 2 : 1);
	}
	return 0;
}
