#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int a[2 * N], l[2 * N];
int st[2 * N], t;

void monotone1(int n)
{
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        while (t > 0 && a[st[t - 1]] <= a[i]) t--;
        l[i] = t == 0 ? -1 : st[t - 1];
        st[t++] = i;
    }
}

int r[2 * N];
void monotone2(int n)
{
    int t = 0;
    for (int i = n; i >= 1; i--)
    {
        while (t > 0 && a[st[t - 1]] <= a[i]) t--;
        r[i] = t == 0 ? -1 : st[t - 1];
        st[t++] = i;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i + n] = a[i];
        monotone1(2 * n);
        monotone2(2 * n);
        for (int i = 1; i <= n; i++)
            printf("%d %d\n", l[i + n] > n ? l[i + n] - n : l[i + n], r[i] > n ? r[i] - n : r[i]);
    }
    return 0;
}