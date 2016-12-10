/********************************************************************************
Problem K. Triskaidekaphobia (水)
********************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

char s[N];

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%s", s);
	int len = strlen(s);
	int ans = INF;
	for (int mid = 0; mid <= len; mid++)
	{
		int sum = 0;
		for (int i = 0; i < mid; i++)
			if (s[i] == '1') sum++;
		for (int i = mid; i < len; i++)
			if (s[i] == '3') sum++;
		ans = min(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}
