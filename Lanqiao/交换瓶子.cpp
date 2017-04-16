#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 10;

int n, val[N], pos[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", val + i), pos[val[i]] = i;;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (val[i] == i) continue;
		ans++;
		int value = val[i];
		val[i] = i;
		int postion = pos[i];
		pos[i] = i;
		val[postion] = value;
		pos[value] = postion;
	}
	printf("%d\n", ans);
	return 0;
}
