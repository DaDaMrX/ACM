#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

ll inv[N];
void get_inv(int n, int mod)
{
    inv[1] = 1;
    for (int i = 2; i < n; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}

bool prime(int n)
{
	if (n == 0 || n == 1) return false;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0) return false;
	return true; 
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1) return printf("YES\n1\n"), 0;
    if (n == 4) return printf("YES\n1\n3\n2\n4\n"), 0;
    if (!prime(n)) return printf("NO\n"), 0;
    printf("YES\n");
    get_inv(n, n);
    printf("1\n");
    for (int i = 2; i < n; i++) printf("%d\n", inv[i - 1] * i % n);
    printf("%d\n", n);
    return 0;
}