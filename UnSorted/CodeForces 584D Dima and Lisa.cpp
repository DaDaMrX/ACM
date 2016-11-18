/*
CodeForces 584D Dima and Lisa
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

bool prime(int n)
{
	if (n == 0 || n == 1) return false;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++)
		if (n % i == 0) return false;
	return true; 
}

int main()
{
	int n;
	scanf("%d", &n);

	if (prime(n))
	{
		printf("1\n%d\n", n);
		return 0;
	}

	if (prime(n - 2))
	{
		printf("2\n2 %d\n", n - 2);
		return 0;
	}

	if (prime(n - 4))
	{
		printf("3\n2 2 %d\n", n - 4);
		return 0;
	}

	printf("3\n");
	int p = n - 1;
	while (!prime(p)) p--;
	printf("%d ", p);

	n -= p;
	for (int i = 3; i < n; i += 2)
		if (prime(i) && prime(n - i))
		{
			printf("%d %d\n", i, n - i);
			break;
		}
	return 0;
}
