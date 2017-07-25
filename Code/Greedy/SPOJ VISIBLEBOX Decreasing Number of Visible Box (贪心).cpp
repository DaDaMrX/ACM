#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int a[N];
queue<int> q;

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)	scanf("%d", a + i);
		sort(a, a + n);
		while (!q.empty()) q.pop();
		q.push(a[0]);
		for (int i = 1; i < n; i++)
		{
			if (a[i] >= 2 * q.front()) q.pop();
			q.push(a[i]);
		}
		printf("Case %d: %d\n", cas, q.size());
	}
	return 0;
}