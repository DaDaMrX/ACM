#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

char s1[10], s2[10];
int len1, len2;

char s[10];
void dfs(int k, int i, int j)
{
	if (i == len1)
	{
		while (j < len2) s[k++] = s2[j++];
		printf("%s\n", s);
		return;
	}
	if (j == len2)
	{
		while (i < len1) s[k++] = s1[i++];
		printf("%s\n", s);
		return;
	}

	if (s1[i] < s2[j])
	{
		s[k] = s1[i];
		dfs(k + 1, i + 1, j);
		s[k] = s2[j];
		dfs(k + 1, i, j + 1);
	}
	else if (s1[i] > s2[j])
	{
		s[k] = s2[j];
		dfs(k + 1, i, j + 1);
		s[k] = s1[i];
		dfs(k + 1, i + 1, j);
	}
	else
	{
		s[k] = s1[i];
		s[k + 1] = s2[j];
		dfs(k + 2, i + 1, j + 1);

		if (i < len1 - 1)
		{
			s[k] = s1[i];
			s[k + 1] = s1[i + 1];
			dfs(k + 2, i + 2, j);
		}
		
		if (j < len2 - 1)
		{
			s[k] = s2[j];
			s[k + 1] = s2[j + 1];
			dfs(k + 2, i, j + 2);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s", s1, s2);
		len1 = strlen(s1);
		len2 = strlen(s2);
		dfs(0, 0, 0);
		printf("\n");
	}
	return 0;
}

