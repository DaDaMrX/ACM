/*
HDU 4194 Peer Review (模拟)
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct
{
	int institution;
	int paper[6];
	set<int> reviewer;
} person[N];
map<string, int> mp;
int n, k;
bool flag[N];

int main()
{
	while (scanf("%d%d", &k, &n), k)
	{
		mp.clear();
		int num = 0;
		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			if (!mp[s]) mp[s] = ++num;
			person[i].institution = mp[s];
			for (int j = 1; j <= k; j++) scanf("%d", &person[i].paper[j]);
			person[i].reviewer.clear();
		}

		memset(flag, true, sizeof(flag));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				int t = person[i].paper[j];
				if (t == i || person[t].institution == person[i].institution)
				{
					flag[t] = false;
					continue;
				}
				if (person[t].reviewer.find(i) != person[t].reviewer.end())
				{
					flag[t] = false;
					continue;
				}
				person[t].reviewer.insert(i);				
			}
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (person[i].reviewer.size() != k) flag[i] = false;
			ans += flag[i] ? 0 : 1;
		}

		if (!ans) printf("NO PROBLEMS FOUND\n");
		else if (ans == 1) printf("1 PROBLEM FOUND\n");
		else printf("%d PROBLEMS FOUND\n", ans);
	}
	return 0;
}