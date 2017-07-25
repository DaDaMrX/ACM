#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e6 + 10;

char s[N], t[N];

int main()
{
    int n;
    scanf("%d", &n);
    n *= 2;
    scanf("%s%s", s, t);
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && t[i] == '0') x++;
        else if (s[i] == '0' && t[i] == '1') y++;
        else if (s[i] == '1' && t[i] == '1') z++;
    }
    bool f = (z & 1) == 0 ? true : false;
    int a = (z + 1) / 2;
    int b = z / 2;
    if (x < y)
    {
        y -= x;
        if (f) b += y / 2;
        else b += (y + 1) / 2;
    }
    else if (x > y)
    {
        x -= y;
        if (f) a += (x + 1) / 2;
        else a += x / 2;
    }

    if (a > b) printf("First\n");
    else if (a < b) printf("Second\n");
    else printf("Draw\n");
    return 0;
}
