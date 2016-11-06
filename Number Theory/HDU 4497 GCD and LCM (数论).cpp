/*
HDU 4497 GCD and LCM (数论)
显然若lcm%gcd!=0时无解，令n=lcm/gcd，对n质因数分解后得到n=p1^k1*p2^k2*…*pm^km，那么必然有 
a/g=p1^a1*p2^a2*…*pm^am 
b/g=p1^b1*p2^b2*…*pm^bm 
c/g=p1^c1*p2^c2*…*pm^cm 
所以对于任意i(1<=i<=m)，都有min(ai,bi,ci)=0,max(ai,bi,ci)=ki，当ai,bi,ci三者之中居中者取1~ki-1时，
总共有6*(ki-1)种情况，当取0或者ki时，有2*3=6种情况，所以对于每个i，都有6*(ki-1)+6=6*ki种情况，
所以枚举n的所有质因子幂级数k每次累乘6*k即可 
*/
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
