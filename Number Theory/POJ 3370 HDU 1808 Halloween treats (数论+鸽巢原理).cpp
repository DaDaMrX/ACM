/*
POJ 3370 HDU 1808 Halloween treats (数论+鸽巢原理)
整除问题，与同余有关
首先处理出这n个数的前缀和sum[]，其中sum[0]=0，这样我们就得到了n+1个数，
将其模m后，因为m <= n，那么由鸽巢原理得这n+1个数中最少存在两个数相同，令其为sum[i],sum[j]，
即之前的sum[i]和sum[j]模n同余，所以sum[j]-sum[i]为m的倍数，
即原数列第i+1项到第j项之间的j-i个数的和必然为m的倍数
PS:
1. 找模m后的n+1个数中相同的两个数，因为a[i]<=1e5，最快的方法使线性查表
2. 带有输入的for循环中不能用break，要保证所有的数据都要输入
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int m, n;
int sum[N], pos[N];

int main()
{
    while (scanf("%d%d", &m, &n), m)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &sum[i]);
            sum[i] = (sum[i] + sum[i - 1]) % m;
        }

        memset(pos, -1, sizeof(pos));
        for (int i = 0; i <= n; i++)
        {
            if (pos[sum[i]] != -1)
            {
                for (int j = pos[sum[i]] + 1; j < i; j++) printf("%d ", j);
                printf("%d\n", i);
                break;
            }
            else pos[sum[i]] = i;
        }
    }
    return 0;
}
