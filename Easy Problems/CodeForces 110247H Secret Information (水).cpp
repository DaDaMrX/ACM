/*
CodeForces 110247H Secret Information (水)
找连续对应字符不同的子串的段数
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

int n;
char a[N], b[N];

int main()
{
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	int ans = 0;
	bool same = true;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
		{
			same = true;
		}
		else
		{
			if (same) ans++;
			same = false;
		}
	}	
	printf("%d\n", ans);
	return 0;
}
