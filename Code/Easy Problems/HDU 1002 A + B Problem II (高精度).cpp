/*
HDU 1002 A + B Problem II (高精度)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct Big
{
	int a[N], len;
	bool sign;
	int power = 8, base = 100000000;

	void reverse(char s[])
	{
		int len = strlen(s);
		int mid = len / 2 - 1;
		for (int i = 0; i <= mid; i++) swap(s[i], s[len - 1 - i]);
	}
	Big()
	{
		memset(a, 0, sizeof(a));
		sign = true;
		len = 1;
	};
	Big(char s[])
	{
		memset(a, 0, sizeof(a));
		sign = true;

		reverse(s);
		int ls = strlen(s);
		if (s[ls - 1] == '-') sign = false, ls--;

		len = -1;
		int w;
		for (int i = 0; i < ls; i++)
		{
			if (i % power == 0) a[++len] = 0, w = 1;
			a[len] += (s[i] - '0') * w;
			w *= 10;
		}
		len++;
	}
	void print()
	{
		if (!sign) printf("-");
		printf("%d", a[len - 1]);
		for (int i = len - 2; i >= 0; i--) printf("%0*d", power, a[i]);
	}
};

Big operator+(Big& a, Big& b)
{
	Big c;
	c.len = max(a.len, b.len);
	for (int i = 0; i < c.len; i++)
	{
		c.a[i] += a.a[i] + b.a[i];
		c.a[i + 1] = c.a[i] / c.base;
		c.a[i] %= c.base;
	}
	if (c.a[c.len]) c.len++;
	return c;
}

char s[N];

int main()
{
	int T;
	scanf("%d", &T);
	for (int cas = 1;  cas <= T; cas++)
	{
		if (cas > 1) printf("\n");
		scanf("%s", s);
		Big a(s);
		scanf("%s", s);
		Big b(s);
		Big c = a + b;
		printf("Case %d:\n", cas);
		a.print(); printf(" + "); b.print(); printf(" = "); c.print(); printf("\n");
	}
	return 0;
}