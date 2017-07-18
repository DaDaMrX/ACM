#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e3 + 10;

ll ta, tb, tw, tx, tc;

bool check(ll n){
    ll a=ta,b=tb,w=tw,x=tx,c=tc;
    c-=n;
    b-=x*n;
    ll num = abs(b/w);
    b+=num*w;
    if(b>=0);
    else num++;
    a-=num;
    if(c<=a) return true;
    else return false;
}

int main()
{
	scanf("%lld%lld%lld%lld%lld", &ta, &tb, &tw, &tx, &tc);
    ll l=0,r=2e14,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;

    }
	printf("%lld\n", ans);
	return 0;
}
