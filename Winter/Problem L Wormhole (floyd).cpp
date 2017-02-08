/********************************************************************************
Problem L Wormhole (floyd)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 70;

char name[N][60];
map<string, int> m;
struct Point
{
	int x, y, z;
} p[N];

int n;
double adj[N][N];

double dist(Point& p1, Point& p2)
{
	ll dx = p1.x - p2.x;
	ll dy = p1.y - p2.y;
	ll dz = p1.z - p2.z;
	return sqrt(dx * dx + dy * dy + dz * dz);

}

void floyd()
{
	for (int i = 1; i <= n; i++) adj[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n);
		m.clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%s%d%d%d", name[i], &p[i].x, &p[i].y, &p[i].z);
			m[string(name[i])] = i;
		}

		memset(adj, 0x3f, sizeof(adj));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = dist(p[i], p[j]);

		int w;
		scanf("%d", &w);
		char s1[60], s2[60];
		while (w--)
		{
			scanf("%s%s", s1, s2);
			adj[m[string(s1)]][m[string(s2)]] = 0;
		}

		floyd();


		int q;
		scanf("%d", &q);
		printf("Case %d:\n", cas);
		while (q--)
		{
			scanf("%s%s", s1, s2);
			printf("The distance from %s to %s is %.0f parsecs.\n", s1, s2, adj[m[string(s1)]][m[string(s2)]]);
		}
	}
	return 0;
}
