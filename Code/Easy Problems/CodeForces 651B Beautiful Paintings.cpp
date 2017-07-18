/*
CodeForces 651B Beautiful Paintings
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int n, cnt[N], a[N], ans;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    scanf("%d", &n);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        cnt[t]++;
    }

    int num = 0;
    for (int i = 1; i < N; i++)
        if (cnt[i]) a[num++] = cnt[i];
    sort(a, a + num, cmp);
    for (int i = 0; i <= num - 2; i++) a[i] = a[i] - a[i + 1];
    ans = 0;
    for (int i = 1; i < num; i++) ans += i * a[i];

    printf("%d\n", ans);
    return 0;
}
