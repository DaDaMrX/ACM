//Problem I What’s on the Grille
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 12;

int n;
char a[N][N], m[N][N], s[N * N];

bool fill(int& index)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (m[i][j] == '.')
            {
                if (a[i][j] && a[i][j] != m[i][j]) return false;
                a[i][j] = s[index++];
            }
    return true;
}

char t[N][N];
void rotate()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t[j][n - 1 - i] = m[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = t[i][j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", m[i]);
    scanf("%s", s);
    memset(a, 0, sizeof(a));

    int t, ia = 0, ja = 0, index = 0;
    for (t = 1; t <= 4; t++)
    {
        if (!fill(index)) break;
        rotate();
    }

    if (t <= 4)
    {
        printf("invalid grille\n");
        return 0;
    }

     for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!a[i][j])
            {
                printf("invalid grille\n");
                return 0;
            }

    for (int i = 0; i < n; i++) printf("%s", a[i]);
    printf("\n");
    return 0;
}
