/*
POJ 3320 Jessica's Reading Problem (尺取)
前提：连续区间
条件：不同元素的数目=整个序列中不同元素数目（覆盖所有知识点）
目标：长度尽可能小，ans = min{length}
1.统计不同元素出现的次数，用map O(logn)或标记数组 O(1)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int n, a[N];
map<int, int> mp;

int main()
{
	scanf("%d", &n);
	mp.clear();
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		mp[a[i]]++;
	}
	int sum = mp.size();
	
	mp.clear();
	int left = 0, right = 0, ans = n;
	while (true)
	{
		while (right < n && mp.size() < sum)
		{
			mp[a[right]]++;
			right++;
		}
		if (mp.size() < sum) break;

		ans = min(ans, right - left);

		mp[a[left]]--;
		if (!mp[a[left]]) mp.erase(mp.find(a[left]));
		left++;
	}

	printf("%d\n", ans);
	return 0;
}