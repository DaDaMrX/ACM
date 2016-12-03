/*
CodeForces 100247F Battle Fury (二分)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

int n, p, q;
int a[N];

bool check(int s)
{
	ll de = (ll)s * q;
	for (int i = 1; i <= n; i++)
	{
		ll t = a[i] - de;
		if (t <= 0) continue;
		s -= t / (p - q) + (t % (p - q) != 0);
		if (s < 0) return false;
	}
	return true;
}

int main()
{
	scanf("%d%d%d", &n, &p, &q);
	int left = 0, right = 0;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		right = max(right, a[i]);
	}
	if (p == q)
	{
		printf("%d\n", right / p + (right % p != 0));
		return 0;
	}
	while (right - left > 1)
	{
		int mid = left + right >> 1;
		if (check(mid)) right = mid;
		else left = mid;
	}
	printf("%d\n", right);
	return 0;
}
