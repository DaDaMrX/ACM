// CodeForces Gym101061H Robocon Club (数学)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;
const double PI = acos(-1);

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        double L, r, Vl, Vr, S;
        scanf("%lf%lf%lf%lf%lf", &L, &r, &Vl, &Vr, &S);
        if (Vl == Vr) 
        {
            printf("0.000 %.3f\n", S * Vl * 2 * PI * r);
            continue;
        }
        double s1 = S * Vl * 2 * PI * r;
        double s2 = S * Vr * 2 * PI * r;
        if (Vl < Vr)
        {
            double R = L * s1 / (s2 - s1);
            double th = s2 / (R + L);
            double x = (R + L / 2) * (cos(th) - 1);
            double y = (R + L / 2) * sin(th);
            printf("%.3f %.3f\n", x, y);
        }
        else
        {
            double R = L * s2 / (s1 - s2);
            double th = s1 / (R + L);
            double x = (R + L / 2) * (1 - cos(th));
            double y = (R + L / 2) * sin(th);
            printf("%.3f %.3f\n", x, y);
        }
    }
    return 0;
}
