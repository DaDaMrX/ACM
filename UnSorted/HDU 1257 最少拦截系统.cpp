/*
HDU 1257 最少拦截系统
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int a[N], n, ans;

int main()
{
    while (~scanf("%d", &n))
    {
        memset(a, 0x7f, sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            int t;
            scanf("%d", &t);
            int j = 0;
            while (j < n && t >= a[j]) j++;
            a[j] = t;
        }
        ans = 0;
        while (a[ans] < INF) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
