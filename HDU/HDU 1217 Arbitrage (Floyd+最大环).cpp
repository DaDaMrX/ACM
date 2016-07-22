#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 40;
map<string, int> mp;
double dis[N][N];
int n, m;
void floyd()
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = max(dis[i][j], dis[i][k] + dis[k][j]);
}
int main()
{
	int cnt = 0;
	while (scanf("%d", &n), n)
	{
		cnt++;
		mp.clear();
		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			mp[s] = i;
		}
		scanf("%d", &m);
		memset(dis, 0, sizeof(dis));
		for (int i = 1; i <= m; i++)
		{
			string s, t;
			double w;
			cin >> s >> w >> t;
			dis[mp[s]][mp[t]] = log(w);
		}
		floyd();
		bool flag = false;
		for (int i = 1; i <= n; i++)
			if (dis[i][i] > 0)
			{
				flag = true;
				break;
			}
		printf("Case %d: ", cnt);
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}