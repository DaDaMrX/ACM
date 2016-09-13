/*
UVa 850 Crypt Kicker II
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 90;

char s[110][90];
char key[50] = "the quick brown fox jumps over the lazy dog";
int lenkey = strlen(key);
int encrypt[26], decrypt[26];

int main()
{
	int T;
	scanf("%d%*c%*c", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		if (cas > 1) printf("\n");

		int n = 1;
		while (fgets(s[n], sizeof(s[n]), stdin) && s[n][0] != '\n') n++;
		n--;

		int i;
		for (i = 1; i <= n; i++)
		{
			memset(encrypt, -1, sizeof(encrypt));
			memset(decrypt, -1, sizeof(decrypt));
			int len = strlen(s[i]) - 1; 
			if (len != lenkey) continue;
			int j;
			for (j = 0; j < len; j++)
			{
				if (s[i][j] == ' ') continue;
				int a = key[j] - 'a', x = s[i][j] - 'a';
				if (decrypt[x] == -1 && encrypt[a] == -1)
				{
					decrypt[x] = a;
					encrypt[a] = x;
				}
				else if (decrypt[x] != -1 && encrypt[a] != -1)
				{
					continue;
				}
				else break;
			}
			if (j == len) break;
		}

		if (i > n)
		{
			printf("No solution.\n");
			continue;
		}
		
		for (int i = 1; i <= n; i++)
		{
			int len = strlen(s[i]) - 1;
			for (int j = 0; j < len; j++)
			{
				if (s[i][j] == ' ') printf(" ");
				else printf("%c", decrypt[s[i][j] - 'a'] + 'a');
			}
			printf("\n");
		}
	}
	return 0;
}