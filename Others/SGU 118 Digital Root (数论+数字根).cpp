/*
SGU 118 Digital Root (数论+数字根)
数字根：各位数字相加，若大于9则再相加，直到成为个位数为止
性质：
1.f(n) = (n - 1) % 9 + 1
就是一种取模运算，模运算的性质都成立
2.f(a + b) = f(f(a) + f(b))
3.f(a * b) = f(f(a) * f(b))
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, a[N];

int f(int n)
{
	return (n - 1) % 9 + 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int s = 1, sum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			s = f(s * f(a[i]));
			sum = f(sum + s);
		}
		printf("%d\n", sum);	
	}
	return 0;
}