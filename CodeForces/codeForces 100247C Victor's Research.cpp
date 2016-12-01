/*
codeForces 100247C Victor's Research
给定n个整数和s，问有多少个连续子序列，元素之和为s。N=2e5。    
即使前缀和优化，枚举起点和终点，O(1)查询，O(n^2)也会T

用map，快速索引之前的sum值
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

int n;
ll sum[N];
ll s;

map<ll, int> mp;

int main()
{
	scanf("%d%I64d", &n, &s);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%I64d", &sum[i]), sum[i] += sum[i - 1];
	mp.clear();
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans += mp[sum[i] - s];
		mp[sum[i]]++;
	}
	printf("%d\n", ans);
	return 0;
}
