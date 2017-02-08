/*
HDU 2222 Keywords Search (AC自动机)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;
const int M = 50 * 1e4;

const int Z = 26;
int trie[M][Z], no;
int fail[M], ed[M];
void init()
{
	memset(trie[0], 0, sizeof(trie[0]));
	no = 1;
	memset(ed, 0, sizeof(ed));
}
void insert(char s[])
{
	int len = strlen(s);
	int p = 0;
	for (int i = 0; i < len; i++)
	{
		int c = s[i] - 'a';
		if (!trie[p][c])
		{
			memset(trie[no], 0, sizeof(trie[no]));
			trie[p][c] = no++;
		}
		p = trie[p][c];
	}
	ed[p]++;
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
int query(char s[])
{
	int ans = 0;
	int p = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		p = trie[p][s[i] - 'a'];
		int t = p;
		while (t)
		{
			ans += ed[t];
			ed[t] = 0;
			t = fail[t];
		}
	}
	return ans;
}

char s[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		int n;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%s", s);
			insert(s);
		}
		build();
		scanf("%s", &s);
		printf("%d\n", query(s));
	}
	return 0;
}