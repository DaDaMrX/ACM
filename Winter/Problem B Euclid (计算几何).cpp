//Problem B Euclid (计算几何)
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
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
} Vector;

Vector operator-(Point A, Point B)    
{
    return Vector(A.x - B.x, A.y - B.y);
}

Vector operator+(Vector A, Vector B)
{
    return Vector(A.x + B.x, A.y + B.y);
}

Vector operator*(double k, Vector A)
{
    return Vector(k * A.x, k * A.y);
}

double cross(Vector A, Vector B)
{
    return A.x * B.y - B.x * A.y;
}

double cross(Point A ,Point B, Point C)
{
    return cross(B - A, C - A);
}

int main()
{
    while (true)
    {
        Point A, B, C, D, E, F;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", 
            &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y, &E.x, &E.y, &F.x, &F.y);
        if (A.x == 0 && A.y == 0 && B.x == 0 && B.y == 0 && C.x == 0 && C.y == 0 
            && D.x == 0 && D.y == 0 && E.x == 0 && E.y == 0 && F.x == 0 && F.y == 0) break;

        double SH = abs(cross(D, E, F)) / 4;
        double SC = abs(cross(A, B, C)) / 2;
        double k = SH / SC;
        Point H = A + k * (C - A);
        Point G = H + B - A;

        printf("%.3f %.3f %.3f %.3f\n", G.x, G.y, H.x, H.y);
    }
    return 0;
}
