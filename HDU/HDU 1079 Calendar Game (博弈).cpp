/*
HDU 1079 Calendar Game (博弈)
1.打表找规律，与年份无关，月与日之和为偶数时先手必胜
2.有两个特殊情况，9月30日和11月30日也是必胜状态
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int y, m, d;
		scanf("%d%d%d", &y, &m, &d);
		if ((m + d) % 2 == 0 || (d == 30 && (m == 9 || m == 11)))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}