#include <cstdio>
#include <cstring>
void multiply(int a[2][2], int b[2][2], int m)
{
	int ans[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			ans[i][j] = 0;
			for (int k = 0; k < 2; k++)
				ans[i][j] += a[i][k] * b[k][j] % m;
			ans[i][j] %= m;
		}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			a[i][j] = ans[i][j];
}
int fibonacci(int a[2][2], int n, int m)
{
	int ans[2][2] = { 1, 0, 0, 1 };
	while (n)
	{
		if (n & 1) multiply(ans, a, m);
		multiply(a, a, m);
		n >>= 1;
	}
	return ans[0][1];
}
int main()
{
	int n;
	while (scanf("%d", &n), ~n)
	{
		int a[2][2] = { 1, 1, 1, 0 };
		printf("%d\n", fibonacci(a, n, 10000));
	}
	return 0;
}