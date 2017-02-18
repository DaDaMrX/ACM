// CodeForces Gym101086M ACPC Headquarters: AASTMT (Stairway to Heaven) (模拟)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 10;

bool p[N][400], flag[N];
char contest[15];

map<string, int> mp;
set<string> name;
set<string>::iterator it;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(p, false, sizeof(p));
		memset(flag, true, sizeof(flag));
		mp.clear();
		name.clear();
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			int s, e, v;
			scanf("%s%d%d%d", contest, &s, &e, &v);
			for (int j = 1; j <= v; j++)
			{
				string str;
				cin >> str;
				if (mp[str] == 0) mp[str] = ++num;
				int id = mp[str];
				if (!flag[id]) continue;
				int k;
				for (k = s; k <= e; k++)
				{
					if (p[id][k]) break;
					p[id][k] = true;
				}
				if (k <= e) flag[id] = false, name.insert(str);
			}
		}
		printf("%d\n", name.size());
		for (it = name.begin(); it != name.end(); it++) cout << *it << endl;
	}
	return 0;
}
