//X Problem G Pool Table (计算几何)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

typedef struct Point
{
	int x, y;
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
} Vector;
Point operator+(Point P, Vector V)
{
	return Point(P.x + V.x, P.y + V.y);
}
Vector dir[4] = { Vector(-1, 1), Vector(-1, -1), Vector(1, -1), Vector(1, 1) };

int L, W, n;
Point C, T;

double dist(Point A, Point B)
{
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    while (scanf("%d%d%d%d%d%d%d", &L, &W, &C.x, &C.y, &T.x, &T.y, &n), L)
    {
        int x2 = L - C.x, y2 = W - C.y;
        double ans = INF;
        Point P(n, 0);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                P = P + dir[i];
                Point S = C;
                if (P.x & 1) S.x = x2;
                if (P.y & 1) S.y = y2;
                S.x += P.x * L;
                S.y += P.y * W;

                ans = min(ans, dist(S, T));
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
