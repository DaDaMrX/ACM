// CodeForces Gym101061I Playing with strings
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;

char s[N];
int cnt[30];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; i++) cnt[s[i] - 'a']++;
        scanf("%s", s);
        len = strlen(s);
        for (int i = 0; i < len; i++) cnt[s[i] - 'a']--;
        int ans = 0;
        for (int i = 0; i < 26; i++) ans += abs(cnt[i]);
        printf("%d\n", ans);
    }
    return 0;
}
