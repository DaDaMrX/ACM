#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int n, ans;
int main()
{
	while (~scanf("%d", &n))
	{
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++)
		{
			int a;
			scanf("%d", &a);
			q.push(a);
		}
		ans = 0;
		for (int i = 1; i < n; i++)
		{
			int sum = 0;
			sum += q.top(); q.pop();
			sum += q.top(); q.pop();
			q.push(sum);
			ans += sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}
