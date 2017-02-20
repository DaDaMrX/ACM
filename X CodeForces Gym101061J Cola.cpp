// X CodeForces Gym101061J Cola
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m;
int c[N], a[N];
ll w;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", c + i);
        memset(a, 0, sizeof(a));
        w = 0;
        while (m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            for (; x <= n && y > 0; x++)
            {
                int t = min(c[x] - a[x], y);
                a[x] += t;
                y -= t;
            }
            w += y;
        }
        printf("%d\n", w);
        for (int i = 1; i <= n; i++) printf("%d%c", a[i], i < n ? ' ' : '\n');
    }
    return 0;
}
