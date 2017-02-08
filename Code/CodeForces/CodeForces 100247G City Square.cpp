/*
CodeForces 100247G City Square
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

bool check(int n)
{
	int s = sqrt(n);
	for (int i = 0; i <= s; i++)
	{
		int tt = (n - i * i);
		int t = sqrt(tt);
		if (t * t == tt) return true; 
	}
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%s\n", check(n) ? "Yes" : "No");
	return 0;
}
