/************************************************************
Problem H. The Longest Good Substring (尺取)
************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e5 + 10;

int k;
char s[N];
int map[26];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
    scanf("%d%s", &k, s + 1);
    int len = strlen(s + 1);
    memset(map, 0, sizeof(map));
    int left = 1, right = 1, cnt = 0, ans = 0;
    while (true)
    {
        while (right <= len && cnt <= k)
        {
            map[s[right] - 'a']++;
            if (map[s[right] - 'a'] == 1) cnt++;
            right++;
        }
        ans = max(ans, right - left - 1);
        if (cnt <= k) break;

        right--;
        map[s[right] - 'a']--;
        if (map[s[right] - 'a'] == 0) cnt--;

        while (left <= right && cnt > k)
        {
            map[s[left] - 'a']--;
            if (map[s[left] - 'a'] == 0) cnt--;
            left++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
