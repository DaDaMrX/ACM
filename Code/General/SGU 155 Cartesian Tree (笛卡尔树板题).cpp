#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 5e4 + 10;

struct node
{
    int i, f, l, r;
    int key, val;
} t[N];
int n;

int st[N], top;

bool cmp(node &a, node &b)
{
    return a.key < b.key;
}
void build()
{
    for (int i = 1; i <= n; i++) t[i].f = t[i].l = t[i].r = 0, t[i].i = i;
    sort(t + 1, t + n + 1, cmp);
    top = 0;
    st[++top] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top > 0 && t[i].val < t[st[top]].val) top--;
        if (top)
        {
            t[i].f = st[top];
            t[i].l = t[st[top]].r;
            t[t[st[top]].r].f = t[i].i;
            t[st[top]].r = i;
        }
        else
        {
            t[st[1]].f = i;
            t[i].l = st[1];
        }
        st[++top] = i;
    }
}

int o[N];
bool cmp2(int a, int b)
{
    return t[a].i < t[b].i;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &t[i].key, &t[i].val);
    build();
    for (int i = 1; i <= n; i++) o[i] = i;
    sort(o + 1, o + n + 1, cmp2);
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d %d %d\n", t[t[o[i]].f].i, t[t[o[i]].l].i, t[t[o[i]].r].i);
    return 0;
}