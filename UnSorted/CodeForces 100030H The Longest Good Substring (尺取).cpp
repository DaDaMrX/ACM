/************************************************************
CodeForces 100030H The Longest Good Substring (尺取)
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%s", &k, s + 1);
    int len = strlen(s + 1);
    memset(map, 0, sizeof(map));
    int left = 1, right = 1, cnt = 0, ans = 1, left_index = 1;
    while (true)
    {
        while (right <= len)
        {
			if (cnt == k && map[s[right] - 'a'] == 0) break;
            map[s[right] - 'a']++;
            if (map[s[right] - 'a'] == 1) cnt++;
            right++;
        }

		if (right - left > ans)
		{
			ans = right - left;
			left_index = left;
		}

		if (right > len) break;

        while (left <= right && cnt == k)
        {
            map[s[left] - 'a']--;
            if (map[s[left] - 'a'] == 0) cnt--;
			left++;
        }
    }
    printf("%d %d\n", left_index, left_index + ans - 1);
    return 0;
}
