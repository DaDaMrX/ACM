//CodeForces Gym101102F Exchange (字符串扫描X)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

char s[N];
bool vis[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int len = strlen(s);

		memset(vis, true, sizeof(vis));
		char key = 'z';
		for (int i = 0; i < len; i++) key = min(key, s[i]);
		int l = 0;
		while (key == s[l])
		{
			for (int i = 0; i < len; i++)
				if (s[i] == key) vis[i] = false;
			while (l < len && !vis[l]) l++;
			if (l >= len) break;
			key = 'z';
			for (int i = 0; i < len; i++)
				if (vis[i]) key = min(key, s[i]);
		}
		if (l >= len)
		{
			printf("%s\n", s);
			continue;
		}

		char a = s[l];
		for (int i = 0; i < len; i++)
		{
			if (s[i] == a) s[i] = key;
			else if (s[i] == key) s[i] = a;
		}
		printf("%s\n", s);
	}
	return 0;
}
