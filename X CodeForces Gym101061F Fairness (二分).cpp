// X CodeForces Gym101061F Fairness (二分)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 110;

int n, a[N];

bool check(int m)
{
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x < y) x += a[i];
        else y += a[i];
        if (abs(x - y) > m) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1; i <= n; i++) scanf("%d", a + i), sum += a[i];
        int l = 0, r = sum;
        while (r - l > 1)
        {
            int m = l + r >> 1;
            if (check(m)) r = m;
            else l = m;
        }
        printf("%d\n", r);
    }
    return 0;
}
