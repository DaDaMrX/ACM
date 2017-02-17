// CodeForces Gym100971B Derangement
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;

int n, a[N];
int st[N], t;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	int ans = 0, t = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == i)
		{
			st[++t] = i;
			ans++;
		}
	if (ans == 0) return printf("0\n"), 0;
	if (ans == 1)
	{
		printf("1\n");
		if (st[1] != 1) printf("%d %d", 1, st[1]);
		else printf("%d %d\n", 1, n); 
		return 0;
	}
	if ((ans & 1) == 0)
	{
		printf("%d\n", ans / 2);
		for (int i = 1; i <= t; i += 2)
			printf("%d %d\n", st[i], st[i + 1]);
		
	}
	else
	{
		printf("%d\n", ans / 2 + 1);
		printf("%d %d\n", st[1], st[2]);
		printf("%d %d\n", st[1], st[3]);
		for (int i = 4; i <= t; i += 2)
			printf("%d %d\n", st[i], st[i + 1]);
	}
	return 0;
}

