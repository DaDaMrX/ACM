//Problem D Dice Cup (水)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m) swap(n, m);
    for (int i = n + 1; i <= m + 1; i++) printf("%d\n", i);
    return 0;
}
