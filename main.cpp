#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int g, l;
        scanf("%d%d", &g, &l);
        if (l % g)
        {
            printf("0\n");
            continue;
        }

        int n = l / g;
        int ans = 1;

        int s = sqrt(n);
        for (int i = 2; i <= s; i++)
            if (n % i == 0)
            {
                int r = 0;
                while (n % i == 0) n /= i, r++;
                ans *= r * 6;
                s = sqrt(n);
            }
        if (n > 1) ans *= 6;

        printf("%d\n", ans);
    }
    return 0;
}
