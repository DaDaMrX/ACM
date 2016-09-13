/*
POJ 3253 Fence Repair (贪心)
不用优先队列，改用两个队列，在一个数组上
O(nlogn)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e4 + 10;

int a[N], n;

int main()
{
	scanf("%d", &n);
	int front1 = 0, rear1 = 0;
	for (int i = 0; i < n; i++) scanf("%d", &a[rear1++]);
	sort(a, a + n);
	
	int front2 = 0, rear2 = 0;
	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		int s = 0, minx = INF, mini;

		if (rear1 > front1)
		{
			minx = a[front1];
			mini = 1;
		}
		if (rear2 > front2 && a[front2] < minx)
		{
			minx = a[front2];
			mini = 2;
		}
		s += minx;
		if (mini == 1) front1++;
		else front2++;

		minx = INF;
		if (rear1 > front1)
		{
			minx = a[front1];
			mini = 1;
		}
		if (rear2 > front2 && a[front2] < minx)
		{
			minx = a[front2];
			mini = 2;
		}
		s += minx;
		if (mini == 1) front1++;
		else front2++;

		ans += s;
		a[rear2++] = s;
	}
	printf("%I64d\n", ans);
	return 0;
}

/*
POJ 3253 Fence Repair (贪心)
用cnt数组，不需排序，O(n)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e4 + 10;
const int M = 5e4 + 10;

int n, a[N], cnt[M];

int main()
{
	scanf("%d", &n);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		cnt[t]++;
	}
	
	ll ans = 0;
	int t = 0, front = 0, rear = 0;
	for (int i = 1; i < n; i++)
	{
		int sum = 0, minx = INF, mini;

		while (t < M && !cnt[t]) t++;
		if (t < M)
		{
			minx = t;
			mini = 1;
		}
		if (rear > front && a[front] < minx)
		{
			minx = a[front];
			mini = 2;
		}
		if (mini == 1)
		{
			sum += t;
			cnt[t]--;
		}
		else
		{
			sum += a[front++];
		}

		minx = INF;
		while (t < M && !cnt[t]) t++;
		if (t < M)
		{
			minx = t;
			mini = 1;
		}
		if (rear > front && a[front] < minx)
		{
			minx = a[front];
			mini = 2;
		}
		if (mini == 1)
		{
			sum += t;
			cnt[t]--;
		}
		else
		{
			sum += a[front++];
		}

		ans += sum;
		a[rear++] = sum;
	}
	printf("%I64d\n", ans);
	return 0;
}