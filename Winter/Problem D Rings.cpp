//Problem D Rings
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 110;

int n, m;
char map[N][N];
int a[N][N];

bool check(int i, int j)
{
    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) return true;
    if (map[i][j + 1] == '.' || map[i + 1][j] == '.' || map[i][j - 1] == '.' || map[i - 1][j] == '.') return true;
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", map[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == '.') a[i][j] = 0;

    int k = 1;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (map[i][j] == 'T' && check(i, j))
                    a[i][j] = k, flag = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == k)
                    map[i][j] = '.';
        k++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            if (a[i][j])
            {
                if (k > 10)
                {
                    if (a[i][j] < 10) printf("..%d", a[i][j]);
                    else printf(".%d", a[i][j]);
                }
                else
                {
                    printf(".%d", a[i][j]);
                }
            }
            else
            {
                if (k > 10) printf("...");
                else printf("..");
            }
        }
        printf("\n");
    }
    return 0;
}
