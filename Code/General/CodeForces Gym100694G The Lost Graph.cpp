// CodeForces Gym100694G The Lost Graph
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, fa[N];

int main()
{
    scanf("%d", &n);
    char s[5];
    int u;
    scanf("%s%d", s, &u);
    fa[u] = -1;
    int p = u;
    for (int i = 2; i <= 2 * n; i++)
    {
        scanf("%s%d", s, &u);
        if (s[0] == 'i')
        {
            printf("%d %d\n", p, u);
            fa[u] = p;
            p = u;
        }
        else
        {
            p = fa[p];
        }
    }
    return 0;
}
