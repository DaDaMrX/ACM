#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int N = 3e5 + 10;
struct Segment
{
	int left, right;
} seg[N / 2 + 5];
map<int, bool> m;
int a[N];
int n, ans;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	m.clear();
	ans = 1; seg[ans].left = 1; m[a[1]] = true;
	int i = 2;
	while (i <= n)
	{
		if (m[a[i]])
		{
			seg[ans].right = i;
			if (i == n) break;
			ans++;
			i++;
			seg[ans].left = i;
			m.clear();
		}
		m[a[i]] = true;
		i++;
	}
	if (i > n)
	{
		if (ans == 1)
		{
			printf("-1\n");
			return 0;
		}
		ans--;
		seg[ans].right = n;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++)
		printf("%d %d\n", seg[i].left, seg[i].right);
	return 0;
}