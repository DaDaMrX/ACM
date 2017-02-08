/*
Codeforces 486C Palindrome Transformation
1.更改字符操作的次数是确定的，要让光标移动的次数尽可能少
2.字符串是循环的，从n右移到1再向右移与从n直接向左移效果相同，但从n到1多走一步，
在中间同理，故要让光标不越界，只在半个区间内移动
3.因为对称性，把所有的操作对称到左半区间
4.并不是所有的字符都要修改，扫描一遍找到要修改的左右边界，
光标先移到距离它最近的边界，然后处理到另一边界
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e7 + 10;

char s[N];
int n, p;

int main()
{
	while (~scanf("%d%d", &n, &p))
	{
		scanf("%s", &s[1]);
		int len = strlen(&s[1]);
		int mid = len / 2;
		int ans = 0;
		int left = mid + 1, right = 0;
		for (int i = 1; i <= mid; i++)
		{
			int t = abs(s[i] - s[len + 1 - i]);
			if (!t) continue;
			t = min(t, 26 - t);
			ans += t;
			if (i < left) left = i;
			if (i > right) right = i;
		}

		if (!ans)
		{
			printf("0\n");
			continue;
		}

		p = min(p, len + 1 - p);
		ans += min(abs(p - left), abs(p - right));
		ans += abs(right - left);

		printf("%d\n", ans);
	}
	return 0;
}