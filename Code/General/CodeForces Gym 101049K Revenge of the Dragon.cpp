//CodeForces Gym 101049K Revenge of the Dragon
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
	double ax, ay, bx, by;
	double k = 0.916297857297023;
	scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);
	double dx = ax - bx;
	double dy = ay - by;
	printf("%.10f\n", k * (dx * dx + dy * dy));
	return 0;
}
