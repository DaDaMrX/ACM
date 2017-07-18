// CodeForces Gym101147G The Galactic Olympics (第二类斯特林数)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int mod = 1e9 + 7;

ll s[N][N]; 

ll fact(ll n)
{
	ll ans = 1;
	for (int i = 1; i <= n; i++) ans = ans * i % mod;
	return ans;
} 

int main()
{
	freopen("galactic.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (m > n) 
		{
			printf("0\n");
			continue;
		}
		for (int i = 1; i <= n; i++) s[i][1] = s[i][i] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 2; j < i; j++)
				s[i][j] = (j * s[i - 1][j] % mod + s[i - 1][j - 1]) % mod;
		printf("%I64d\n", s[n][m] * fact(m) % mod);
	}
	return 0;
}
