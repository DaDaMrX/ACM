/*
HDU 3065 病毒侵袭持续中 (AC自动机)
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e6 + 10;
const int M = 5e4 + 10;

const int Z = 26;
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
		int c = s[i] - 'A';
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
void query(char s[], int num[])
{
	int len = strlen(s);
	int p = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] < 'A' || s[i] > 'Z')
		{
			p = 0;
			continue;
		}
		p = trie[p][s[i] - 'A'];
		int t = p;
		while (t)
		{
			if (ed[t]) num[ed[t]]++;
			t = fail[t];
		}
	}
}

char s[1010][55], text[N];
int num[1010];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		init();
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s[i]);
			insert(i, s[i]);
		}
		getchar();
		build();

		fgets(text, N, stdin);
		text[strlen(text) - 1] = '\0';
		memset(num, 0, sizeof(num));
		query(text, num);
		for (int i = 1; i <= n; i++)
			if (num[i])
				printf("%s: %d\n", s[i], num[i]);
	}
	return 0;
}