#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 5e3 + 10;

typedef struct Point
{
    ll x, y;
    Point() {}
    Point(ll x, ll y): x(x), y(y) {}
} Vector;

Vector operator-(Point A, Point B)    
{
    return Vector(A.x - B.x, A.y - B.y);
}

ll cross(Vector A, Vector B)
{
    return A.x * B.y - B.x * A.y;
}

ll area(Point A ,Point B, Point C)
{
    return abs(cross(B - A, C - A));
}

Point p[N];

int main()
{
	int n;
	scanf("%d%*I64d", &n);
	for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &p[i].x, &p[i].y);
	int a = 1, b = 2, c = 3;
	ll s = area(p[a], p[b], p[c]);
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 1; i <= n; i++)
		{
			ll t = area(p[i], p[b], p[c]);
			if (t > s) s = t, a = i, flag = true;
			t = area(p[a], p[i], p[c]);
			if (t > s) s = t, b = i, flag = true;
			t = area(p[a], p[b], p[i]);
			if (t > s) s = t, c = i, flag = true;
		}
	}
	printf("%I64d %I64d\n", p[a].x + p[b].x - p[c].x, p[a].y + p[b].y - p[c].y);
	printf("%I64d %I64d\n", p[b].x + p[c].x - p[a].x, p[b].y + p[c].y - p[a].y);
	printf("%I64d %I64d\n", p[c].x + p[a].x - p[b].x, p[c].y + p[a].y - p[b].y);
	return 0;
}