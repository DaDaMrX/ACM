/*
FZU 1759 Super A^B mod C (数论+欧拉函数降幂+快速幂)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int stoimod(char s[], int len, int m)
{
	ll ans = (s[0] - '0') % m;
	for (int i = 1; i < len; i++)
	{
		ans = (ans * 10 + s[i] - '0') % m;
	}
	return ans;
}

int phi(int n)
{
	int ans = n;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
			s = sqrt(n);
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}

int power(long long a, int n, int m)
{
	long long ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return ans;
}

int main()
{
	int a, b, c;
	char s[N];
	while (~scanf("%d%s%d", &a, s, &c))
	{
		int phic = phi(c);
		b = stoimod(s, strlen(s), phic) + phic;
		printf("%d\n", power(a, b, c));
	}
	return 0;
}