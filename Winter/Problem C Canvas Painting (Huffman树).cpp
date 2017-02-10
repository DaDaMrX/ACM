//Problem C Canvas Painting (Huffman树)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e6 + 10;

priority_queue<ll, vector<ll>, greater<ll> > pq;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        while (!pq.empty()) pq.pop();
        for (int i = 1; i <= n; i++)
        {
            ll a;
            scanf("%I64d", &a);
            pq.push(a);
        }
        ll ans = 0;
        for (int i = 1; i < n; i++)
        {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ll sum = a + b;
            ans += sum;
            pq.push(sum);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
