/*
CodeForces 217C Memory and De-Evolution (水)
从小到大变化更简单
每次取最短的边，往大里变，即另外两条变之和减1，如果已经超了目标x就停止
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int a[3], x, y;
	scanf("%d%d", &x, &y);
	a[0] = a[1] = a[2] = y;
	int ans = 0, i = 0;
	while (true)
	{
		int sum = a[(i + 1) % 3] + a[(i + 2) % 3] - 1;
		if (sum >= x) break;
		a[i] = sum;
		ans++;
		i = (i + 1) % 3;
	}
	ans += 3;
	printf("%d\n", ans);
	return 0;
}
