/*
CodeForces 110247D Hamming Distance (水)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 10;

char a[N], b[N], c[N];
int n;

char major(char a, char b, char c)
{
	if (a == b || a == c) return a;
	return b;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);
	for (int i = 0; i < n; i++) printf("%c", major(a[i], b[i], c[i]));
	printf("\n");
	return 0;
}
