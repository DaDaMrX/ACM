/****************************************************************************
 * CodeForces 735A Ostap and Grasshopper
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

char s[N];
int n, k;

int main()
{
	scanf("%d%d%s", &n, &k, s);
	int len = strlen(s);
	int start, finish;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'G') start = i;
		else if (s[i] == 'T') finish = i;
	}
	if (start > finish) swap(start, finish);
	if ((finish - start) % k)
	{
		printf("NO\n");
		return 0;
	}
	int i;
	for (i = start + k; i < finish && s[i] != '#'; i += k);
	printf("%s\n", i < finish ? "NO" : "YES");
	return 0;
}

