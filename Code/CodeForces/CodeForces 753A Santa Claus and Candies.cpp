/****************************************************************************
 * CodeForces 753A Santa Claus and Candies
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int n, s[N];

int main()
{
	scanf("%d", &n);
	int sum = 0;
	s[0] = 0;
	int k;
	for (k = 1; sum + k <= n; k++)
	{
		s[k] = k;
		sum += k;
	}
	k--;
	s[k] += n - sum;
	printf("%d\n", k);
	for (int i = 1; i < k; i++) printf("%d ", s[i]);
	printf("%d\n", s[k]);
	return 0;
}

