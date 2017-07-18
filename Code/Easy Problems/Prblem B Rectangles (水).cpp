// Prblem B Rectangles (ˮ)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int left = INF, right = -INF;
		int up = -INF, down = INF;
		for (int i = 1; i <= 4 * n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			left = min(left, x);
			right = max(right, x);
			down = min(down, y);
			up = max(up, y);
		}
		int S = (right - left) * (up - down);
		printf("%d\n", S);
	}
	return 0;
}

