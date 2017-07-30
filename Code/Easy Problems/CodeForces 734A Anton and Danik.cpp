/****************************************************************************
 * CodeForces 734A Anton and Danik
 ****************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

char s[N];
int n;

int main()
{
	scanf("%d%s", &n, s);
	int anton = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'A') anton++;
	int danik = n - anton;
	if (anton > danik) printf("Anton\n");
	else if (anton < danik) printf("Danik\n");
	else printf("Friendship\n");
	return 0;
}

