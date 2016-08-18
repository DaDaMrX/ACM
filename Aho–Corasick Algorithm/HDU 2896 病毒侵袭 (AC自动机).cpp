/*
HDU 2896 病毒侵袭 (AC自动机)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;
const int M = 510 * 210;

const int Z = 128;
int trie[M][Z], no;
int fail[M], ed[M];
void init()
{
	memset(trie[0], 0, sizeof(trie[0]));
	no = 1;
	memset(ed, 0, sizeof(ed));
}
void insert(int i, char s[])
{
	int len = strlen(s);
	int p = 0;
	for (int i = 0; i < len; i++)
	{
		int c = s[i];
		if (!trie[p][c])
		{
			memset(trie[no], 0, sizeof(trie[no]));
			trie[p][c] = no++;
		}
		p = trie[p][c];
	}
	ed[p] = i;
}
queue<int> q;
void build()
{
	while (!q.empty()) q.pop();
	for (int i = 0; i < Z; i++)
		if (!trie[0][i]) trie[0][i] = 0;
		else
		{
			fail[trie[0][i]] = 0;
			q.push(trie[0][i]);
		}
	while (!q.empty())
	{
		int p = q.front(); q.pop();
		for (int i = 0; i < Z; i++)
			if (!trie[p][i]) trie[p][i] = trie[fail[p]][i];
			else
			{
				fail[trie[p][i]] = trie[fail[p]][i];
				q.push(trie[p][i]);
			}
	}
}
int query(char s[], vector<int> &vec)
{
	vec.clear();
	int p = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		p = trie[p][s[i]];
		int t = p;
		while (t)
		{
			if (ed[t]) vec.push_back(ed[t]);
			t = fail[t];
		}
	}
	sort(vec.begin(), vec.end());
	return vec.size();
}

char s[N];
vector<int> vec;

int main()
{
	int n;
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		insert(i, s);
	}
	build();
	int m;
	scanf("%d", &m);
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", s);
		if (query(s, vec))
		{
			ans++;
			printf("web %d:", i);
			for (int i = 0; i < vec.size(); i++)
				printf(" %d", vec[i]);
			printf("\n");
		}
	}
	printf("total: %d\n", ans);
	return 0;
}