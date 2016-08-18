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



struct Trie
{
	int next[M][26], fail[M], end[M];
	int root, L;
	int newnode()
	{
		for (int i = 0; i < 26; i++)
			next[L][i] = -1;
		end[L++] = 0;
		return L - 1;
	}
	void init()
	{
		L = 0;
		root = newnode();
	}
	void insert(char s[])
	{
		int len = strlen(s);
		int now = root;
		for (int i = 0; i < len; i++)
		{
			if (next[now][s[i] - 'a'] == -1)
				next[now][s[i] - 'a'] = newnode();
			now = next[now][s[i] - 'a'];
		}
		end[now]++;
	}
	void build()
	{
		queue<int> q;
		fail[root] = root;
		for (int i = 0; i < 26; i++)
			if (next[root][i] == -1) next[root][i] = root;
			else
			{
				fail[next[root][i]] = root;
				q.push(next[root][i]);
			}
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			for (int i = 0;i < 26;i++)
				if (next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else
				{
					fail[next[now][i]] = next[fail[now]][i];
					q.push(next[now][i]);
				}
		}
	}
	int query(char s[])
	{
		int len = strlen(s);
		int now = root;
		int ans = 0;
		for (int i = 0;i < len;i++)
		{
			now = next[now][s[i] - 'a'];
			int tmp = now;
			while (tmp != root)
			{
				ans += end[tmp];
				end[tmp] = 0;
				tmp = fail[tmp];
			}
		}
		return ans;
	}
} ac;



int trie[N][26], no;
int ed[N];
void init()
{
	memset(trie[0], 0, sizeof(trie[0]));
	no = 1;
	memset(ed, 0, sizeof(ed));
}
void insert(char *str)
{
	int p = 0;
	while (*str)
	{
		int c = (*str++) - 'a';
		if (!trie[p][c])
		{
			memset(trie[no], 0, sizeof(trie[no]));
			trie[p][c] = no++;
		}
		p = trie[p][c];
	}
	ed[p]++;
}
int fail[N];
queue<int> q;
void build()
{
	while (!q.empty()) q.pop();
	for (int i = 0; i < 26; i++)
	{
		if (trie[0][i])
		{
			q.push(trie[0][i]);
			fail[trie[0][i]] = 0;
		}
	}
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; i++)
		{
			int v = trie[u][i];
			if (v)
			{
				q.push(v);
				int t = fail[u];
				while (t && !trie[t][i]) t = fail[t];
				fail[v] = trie[t][i];
			}
		}
	}
}
int query(char *str)
{
	int ans = 0;
	int p = 0;
	while (*str)
	{
		int c = (*str++) - 'a';
		while (p && !trie[p][c]) p = fail[p];
		p = trie[p][c];
		int tmp = p;
		while (tmp)
		{
			ans += ed[tmp];
			ed[tmp] = 0;
			tmp = fail[tmp];
		}
	}
	return ans;
}