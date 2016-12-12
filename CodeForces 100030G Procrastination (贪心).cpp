/************************************************************
CodeForces 100030G Procrastination (贪心)
************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 2e3 + 10;

struct Triple
{
    int c, i, x;
} a[N];

int k, n;

bool cmp1(Triple &t1, Triple &t2)
{
    return t1.c < t2.c;
}

bool cmp2(Triple &t1, Triple &t2)
{
    return t1.i < t2.i;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &k, &n);
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].c);
        a[i].i = i;
    }
    sort(a, a + n, cmp1);
    for (int i = 0; i < n; i++)
    {
        if (k >= a[i].c) 
        {
            k -= a[i].c; 
            a[i].x = a[i].c;
        }
        else 
        {
            a[i].x = k;
            break;
        }
    }
    sort(a, a + n, cmp2);
    for (int i = 0; i <= n - 2; i++) printf("%d ", a[i].x);
    printf("%d\n", a[n - 1].x);
    return 0;
}
