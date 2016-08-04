/*
HDU 5749 Colmerauer (单调栈+组合数学)
单调栈：计算每个点a[i][j]上下左右能延拓的最远位置left[i][j],right[i][j],up[i][j],down[i][j]，再转换成最远距离
组合数学：累加每个点的贡献ans = sum{ a * (left * right * (left + right) / 2) * (up * down  * (up + down) / 2) }
PS：最后计算贡献时，取模与除法在一起要特别注意
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;
const ll mod = 1ll << 32;

int n, m;
int a[N][N];
int left[N][N], right[N][N], up[N][N], down[N][N];

int st[N], top;
void lefttoright(int i, int m)
{
	top = 0;
	for (int j = 1; j <= m; j++)
	{
		while (top && a[i][j] <= a[i][st[top]])
		{
			right[i][st[top]] = j - 1;
			top--;
		}
		st[++top] = j;
	}
	while (top)
	{
		right[i][st[top]] = m;
		top--;
	}
}
void righttoleft(int i, int m)
{
	top = 0;
	for (int j = m; j >= 1; j--)
	{
		while (top && a[i][j] <= a[i][st[top]])
		{
			left[i][st[top]] = j + 1;
			top--;
		}
		st[++top] = j;
	}
	while (top)
	{
		left[i][st[top]] = 1;
		top--;
	}
}
void uptodown(int j, int n)
{
	top = 0;
	for (int i = 1; i <= n; i++)
	{
		while (top && a[i][j] >= a[st[top]][j])
		{
			down[st[top]][j] = i - 1;
			top--;
		}
		st[++top] = i;
	}
	while (top)
	{
		down[st[top]][j] = n;
		top--;
	}
}
void downtoup(int j, int n)
{
	top = 0;
	for (int i = n; i >= 1; i--)
	{
		while (top && a[i][j] >= a[st[top]][j])
		{
			up[st[top]][j] = i + 1;
			top--;
		}
		st[++top] = i;
	}
	while (top)
	{
		up[st[top]][j] = 1;
		top--;
	}
}

ll calc(ll a, ll left, ll right, ll up, ll down)
{
	ll ans1 = left * right * (left + right) / 2;
	ll ans2 = up * down * (up + down) / 2;
	return ans1 * ans2 % mod * a % mod;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);

		for (int i = 1; i <= n; i++)
		{
			lefttoright(i, m);
			righttoleft(i, m);
		}
		for (int j = 1; j <= m; j++)
		{
			uptodown(j, n);
			downtoup(j, n);
		}

		ll ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				ll sum = calc(a[i][j], j - left[i][j] + 1, right[i][j] - j + 1, i - up[i][j] + 1, down[i][j] - i + 1);
				ans = (ans + sum) % mod;
			}

		printf("%lld\n", ans);
	}
	return 0;
}