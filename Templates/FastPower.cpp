/*
快速幂
PS: 有a*a运算，有溢出的可能
*/
int power(long long a, int n, int m)
{
	long long ans = 1;
	while (n)
	{
		if (n & 1) ans = ans * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return ans;
}