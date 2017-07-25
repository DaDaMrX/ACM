#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

int n, m;

int ans;
int s[10];
void dfs(int step, int sum)
{
    if (sum == n)
    {
        ans++;
        return;
    }
    if (step == 6) return;
    for (int i = s[step - 1]; i <= m; i++)
    {
        int tmp = i * i * i;
        sum += tmp; s[step] = i;
        if (sum > n) break;
        dfs(step + 1, sum);
        sum -= tmp;
    }
}

int main()
{
    scanf("%d", &n);
    m = pow(n, 1.0 / 3) + 1;
    s[0] = 1;
    ans = 0;
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}
