//Problem H Sheldon Numbers (打表)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int N = 6e3 + 10;

ll a[N];
int tol;

char str[100];

int main()
{
    tol = 0;
    // for (int la = 1; la <= 63; la++)
    //     for (int lb = 1; lb <= 63; lb++)
    //     {
    //         ll mark = ((ll)1 << la) - 1;
    //         ll x = (ll)0 | mark;
    //         if (lb == 1) a[++t] = x;
    //         if (la + lb > 63) continue;
    //         x = x << lb;
    //         a[++t] = x;

    //         int s = 63 / (la + lb);
    //         for (int i = 2; i <= s; i++)
    //         {
    //             x = x << la | mark;
    //             a[++t] = x;
    //             x = x << lb;
    //             a[++t] = x;
    //         }
    //         if ((63 - la - lb) % (la + lb) > la)
    //         {
    //             x = x << la | mark;
    //             a[++t] = x;
    //         }
    //     }

    for (int i = 1; i <= 63; i++)
	{
		for (int j = 1; j <= 63; j++)
		{
			for (int k = 0; k <= 63; k++)
			{
				if (i / (j + k) >= 1 && !( k == 0 && i % j == 0 && i != j) )
				{
					int t = i % (j + k);
					if (t == 0)
					{
						ll p = ((ll)1 << j) - (ll)1;
						p = p << k;

						ll num = p;
						int q = i / (j + k);
						for (int w = 1; w < q; w++)
						{
							p = p << (j + k);
							num += p;
						}
						a[++tol] = num;

					}

					if (t == j)
					{
						ll p = ((ll)1 << j) - (ll)1;

						ll num = p;
						int q = i / (j + k);
						for (int w = 1; w <= q; w++)
						{
							p = p << (j + k);
							num += p;
						}
						a[++tol] = num;
					}
				}
			}
		}
	}
    
    //printf("sum = %d\n", t);
    sort(a + 1, a + tol + 1);

    ll l, r;
    scanf("%I64d%I64d", &l, &r);
    int ans = upper_bound(a + 1, a + tol + 1, r) - lower_bound(a + 1, a + tol + 1, l);
    printf("%d\n", ans);
    return 0;
}
