#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 15
int a[N];
const int vol = 50;
int n, gray, ans;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		scanf("%d", &gray);
		sort(a, a + n);
		ans = a[n - 1] / vol;
		if (a[n - 1] % vol) ans++;
		int sum = ans * vol;
		for (int i = 0; i < n; i++) a[i] = sum - a[i];
		while (gray)
		{
			if (!a[2])
			{
				ans++;
				for (int i = 0; i < n; i++) a[i] += vol;
			}
			gray--;
			for (int i = 0; i < 3; i++) a[i]--;
			sort(a, a + n, cmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
