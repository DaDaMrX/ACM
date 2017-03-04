#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 100;

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

int main()
{
	int n;
	while (~scanf("%d", &n)) printf("%d\n", phi(n) / 2);
	return 0;
}
