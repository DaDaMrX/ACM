/*
POJ 3250 Bad Hair Day (单调栈)
对每一个a[i]，求以a[i]为严格最大值向右延拓的最大区间，累加
维护一个严格单调递减的栈，每个元素向右延拓的最远位置与当前位置之差，
即为这头牛能够看到的牛的数量
PS：ans中累加每头牛能看到的牛的数量，会超过int范围！
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 8e4 + 10;

int n, a[N];
int st[N], top;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	ll ans = 0;
	top = 0;
	for (int i = 1; i <= n; i++)
	{
		while (top && a[i] >= a[st[top]])
		{
			ans += i - 1 - st[top];
			top--;
		}
		st[++top] = i;
	}
	while (top)
	{
		ans += n - st[top];
		top--;
	}

	printf("%lld\n", ans);
	return 0;
}