//CodeForces Gym 101149B No Time for Dragons (贪心)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

struct P
{
	int a, b, c;
} t[N];
int n;

bool cmp(P& p1, P& p2)
{
	if (p1.c != p2.c) return p1.c > p2.c;
	return p1.a < p2.a;
}

int main()
{
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &t[i].a, &t[i].b);
		t[i].c = t[i].a - t[i].b;
		ans += t[i].b;
	}
	ll now = ans;
	sort(t, t + n, cmp);

	for (int i = 0; i < n; i++)
	{
		if (now < t[i].a)
		{
			int d = t[i].a - now;
			now = t[i].a;
			ans += d;
		}
		now -= t[i].b;
	}

	printf("%I64d\n", ans);
	return 0;
}
