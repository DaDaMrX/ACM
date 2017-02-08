/*
POJ 2356 Find a multiple (数论+鸽巢原理)
对这n个数排序，处理得到前缀和数组sum[]，其中sum[0]=0，这样就得到了n+1个数，
对这n+1个数模n，由鸽巢原理可知至少有2个数相同，记为sum[i],sum[j]，
即原来的前缀和数组中至少有两个数模n同余，这两个数之间的数的和必为n的倍数
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e4 + 10;
const int M = 15010;

int a[N], sum[N];
int pos[M];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + a[i]) % n;
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i <= n; i++)
    {
        if (pos[sum[i]] == -1)
        {
            pos[sum[i]] = i;
            continue;
        }
        printf("%d\n", i - pos[sum[i]]);
        for (int j = pos[sum[i]] + 1; j <= i; j++) printf("%d\n", a[j]);
        break;
    }
    return 0;
}
