// CodeForces Gym101061D Max or Min that is the question (水)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int a[8];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 5; i++) scanf("%d", a + i);
        sort(a + 1, a + 6);
        printf("%d\n", a[4] * a[5]);
    }
    return 0;
}
