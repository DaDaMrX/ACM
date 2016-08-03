/*
POJ 2635 The Embarrassed Cryptographer (数论+大数分段取模)
L <= 1e6，线性筛出1e6的素数
枚举L以内所有素数，若能整除K，则输出BAD
K用字符数组s[]存储，因为要多次取模，故三位一组转存到int数组a[]中
1.不转存会T，四位一组转存会WA
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int mark[N], prime[N];
void get_prime(int n)
{
	memset(mark, 0, sizeof(mark));
	int res = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) mark[i] = prime[res++] = i;
		for (int j = 0; j < res && prime[j] * i <= n; j++)
		{
			mark[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) break;
		}
	}
}

int change(char s[], int len, int sum, int a[])
{
	int n = (len / sum) + (len % sum > 0);
	for (int i = n - 1, j = len - 1; i >= 0; i--)
	{
		a[i] = 0;
		int weight = 1;
		for (int k = 1; k <= sum; k++)
		{
			a[i] += (s[j] - '0') * weight;
			j--;
			weight *= 10;
			if (j < 0) break;
		}
	}
	return n;
}
int mod(int a[], int n, int sum, int m)
{
	int ans = 0;
	int weight = 1;
	for (int i = 1; i <= sum; i++) weight *= 10;
	for (int i = 0; i < n; i++)
		ans = ((ans * weight) % m + a[i] % m) % m;
	return ans;
}

int main()
{
	get_prime(N - 1);
	char s[110];
	int a[110];
	int L;
	while (scanf("%s%d", s, &L), L)
	{
		int n = change(s, strlen(s), 3, a);
		bool flag = true;
		for (int i = 0; prime[i] < L; i++)
			if (!mod(a, n, 3, prime[i]))
			{
				printf("BAD %d\n", prime[i]);
				flag = false;
				break;
			}
		if (flag) printf("GOOD\n");
	}
	return 0;
}