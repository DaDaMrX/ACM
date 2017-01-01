/********************************************************************************
X CodeForces 100030F Magic Chains (字符串哈希)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 6e4 + 10;
const int M = 5e6 + 10;

struct Edge
{
	int to, next;
	Edge() {};
	Edge(int to, int next): to(to), next(next) {};
} edge[M];
int adj[N], no;

void init()
{
	memset(adj, -1, sizeof(adj));
	no = 0;
}
void add(int u, int v)
{
	edge[no] = Edge(v, adj[u]);
	adj[u] = no++;
}

int n;
string word[N];
map<string, int> mp;

int len;

int step[N], pre[N];
queue<int> q;
int bfs(int start, int finish)
{
	memset(step, -1, sizeof(step));
	memset(pre, -1, sizeof(pre));
	while (!q.empty()) q.pop();
	q.push(start); step[start] = 0; pre[start] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = adj[u]; i != -1; i = edge[i].next)
			if (step[edge[i].to] == -1)
            {
                Edge &e = edge[i];
				step[e.to] = step[u] + 1;
				pre[e.to] = u;
				if (e.to == finish) return step[finish];
                q.push(e.to); 
            }
	}
	return -1;
}

void print(string s)
{
	for (int i = 0; i < len; i++) printf("%c", s[i]);
	printf("\n");
}

void path(int u, int v)
{
	if (v == 0) return;
	path(u, pre[v]);
	print(word[v]);
}

char str[12];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	mp.clear();
	init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		word[i] = string(str);
		len = strlen(str);
		mp[word[i]] = i;
		for (int j = 0; j < len; j++)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (c == str[j]) continue;
				string s(str);
				s[j] = c;
				int k = mp[s];
				if (k) add(i, k), add(k, i); 
			}
		}
	}

	int ans = bfs(1, n) + 1;
	if (ans == 0)
	{
		printf("FAIL\n");
		return 0;
	}
	printf("%d\n", ans);
	path(1, n);
	return 0;
}
