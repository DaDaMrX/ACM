#include <cstdio>
#include <cstring>
struct Matrix
{
	long long m[3][3];
	Matrix() {};
	Matrix(long long a, long long b, long long c, long long d, long long e, long long f, long long g, long long h, long long i)
	{
		m[0][0] = a; m[0][1] = b; m[0][2] = c;
		m[1][0] = d; m[1][1] = e; m[1][2] = f;
		m[2][0] = g; m[2][1] = h; m[2][2] = i;
	}
	Matrix power(long long n, int m);
	Matrix multiply(Matrix A, int m);
};
Matrix Matrix::multiply(Matrix A, int m)
{
	Matrix B;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			long long sum = 0;
			for (int k = 0; k < 3; k++)
				sum = (sum + this->m[i][k] * A.m[k][j]) % m;
			B.m[i][j] = sum;
		}
	return B;
}
Matrix Matrix::power(long long n, int m)
{
	Matrix A(1, 0, 0, 0, 1, 0, 0, 0, 1);
	while (n)
	{
		if (n & 1) A = A.multiply(*this, m);
		n >>= 1;
		*this = this->multiply(*this, m);
	}
	return A;
}
int power(long long a, long long n, int m)
{
	long long ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % m;
		n >>= 1;
		a = a * a % m;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n;
		int a, b, c, p;
		scanf("%lld%d%d%d%d", &n, &a, &b, &c, &p);
		if (n == 1) printf("1\n");
		else if (n == 2) printf("%d\n", power(a, b, p));
		else
		{
			Matrix A(c, 1, 0, 1, 0, 0, b, 0, 1);
			Matrix B = A.power(n - 2, p - 1);
			long long exp = b * B.m[0][0] + B.m[2][0];
			int ans = power(a, exp, p);
			printf("%d\n", ans);
		}
	}
	return 0;
}