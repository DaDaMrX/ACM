#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int st[N];

void print()
{
	for (int i = 1; i < 4; i++) printf("%d ", st[i]);
	printf("%d\n", st[4]);
}

bool dfs(int t, int n)
{
	if (t == 4)
	{
		int s = sqrt(n);
		if (s * s == n) 
		{
			st[t] = s;
		   	print();
			return true;
		}
		else return false;
	}
	for (int i = 0; i * i <= n; i++)
	{
		st[t] = i;
		if (dfs(t + 1, n - i * i)) return true;
	}
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	dfs(1, n);
	return 0;
}
