//Problem A Who Is The Winner (结构体排序)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

struct Team
{
	char name[25];
	int s, p;
} team[N];
int n;

bool cmp(Team& t1, Team& t2)
{
	if (t1.s != t2.s) return t1.s > t2.s;
	return t1.p < t2.p;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf("%s%d%d", team[i].name, &team[i].s, &team[i].p);
		sort(team, team + n, cmp);
		printf("%s\n", team[0].name);
	}
	return 0;
}
