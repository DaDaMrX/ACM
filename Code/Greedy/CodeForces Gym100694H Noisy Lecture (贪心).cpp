// CodeForces Gym100694H Noisy Lecture (贪心)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
    int n;
    scanf("%d", &n);
    int maxa = 0;
    int a;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        maxa = max(maxa, a); 
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
    }
    int k;
    scanf("%d", &k);
    int sumc = 0;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &a);
        sumc += a;
    }
    printf("%d\n", k * maxa + sumc);
    return 0;
}
