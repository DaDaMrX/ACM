//CodeForces Gym 101149E The Best among Equals
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

int n, l[N], r[N];

int main()
{
	int n;
	scanf("%d", &n);
	l[0] = -INF;
	int m1 = 0, m2 = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", l + i, r + i);
		if (l[i] >= l[m1])
		{
			m2 = m1;
			m1 = i;
		}
		else if (l[i] >= l[m2])
		{
			m2 = i;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i != m1)
		{
			if (r[i] >= l[m1]) ans++;
		}
		else
		{
			if (r[i] >= l[m2]) ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}
