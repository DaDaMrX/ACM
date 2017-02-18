// CodeForces Gym 101086H Another Square in the Floor (水)
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
		int x, y;
		scanf("%d%d", &x, &y);
		int m = max(x, y);
		printf("%d\n", m * m);
	}
	return 0;
}
