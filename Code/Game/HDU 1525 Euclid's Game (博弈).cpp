/*
HDU 1525 Euclid's Game (博弈)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

bool check(int a, int b)
{
	if (b > a && b < 2 * a) return !check(b - a, a);
	return true;
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b), a)
	{
		if (a > b) swap(a, b);
		if (check(a, b)) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}