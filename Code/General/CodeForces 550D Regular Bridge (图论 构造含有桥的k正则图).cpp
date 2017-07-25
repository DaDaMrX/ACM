#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int main()
{
    int k;
    scanf("%d", &k);
    if ((k & 1) == 0) return printf("NO\n"), 0;
    printf("YES\n");
    printf("%d %d\n", 4 * k - 2, (2 * k + 1) * (k - 1) + 1);
    for (int i = 2; i <= k; i++) printf("%d %d\n%d %d\n", 1, i, 2 * k, i + 2 * k - 1);
    for (int i = 2; i <= k; i++)
        for (int j = k + 1; j < 2 * k; j++)
        {
            printf("%d %d\n", i, j);
            printf("%d %d\n", i + 2 * k - 1, j + 2 * k - 1);
        }
    for (int i = k + 1; i < 2 * k - 1; i += 2)
    {
        printf("%d %d\n", i, i + 1);
        printf("%d %d\n", i + 2 * k - 1, i + 1 + 2 * k - 1);
    }
    printf("%d %d\n", 1, 2 * k);
    return 0;
}