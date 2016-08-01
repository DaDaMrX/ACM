//Pollard_Rho算法分解大数,时间复杂度O(n^(1/4))
//对n素因子分解,factor里存的是每个素因子及其幂指数
//判断n是否为素数时如果n比较小就用打的表判断,否则就用Miller-Robin
#define maxn 200000
typedef long long ll;
bool is_prime[maxn];
vector<int>prime;
map<ll,int>factor;
void get_prime()
{
	for(int i=0;i<maxn;i++)is_prime[i]=1;
	is_prime[0]=is_prime[1]=0;
	for(int i=2;i<maxn;i++)
		if(is_prime[i])
		{
			prime.push_back(i);
			for(int j=i;j<maxn;j+=i)is_prime[j]=0;
		}
}
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
ll mod_mul(ll a,ll b,ll p)
{
	ll ans=0ll;
	a%=p,b%=p;
	if(a>b) swap(a,b);
	while(b)
	{
		if(b&1) ans=(ans+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return ans;
}
ll mod_pow(ll a,ll b,ll p)
{
	ll ans=1ll;
	a%=p;
	while(b)
	{
		if(b&1) ans=mod_mul(ans,a,p);
		a=mod_mul(a,a,p);
		b>>=1;
	}
	return ans;
}
int Times=20;
bool witness(ll a,ll n)
{
	ll m=n-1;
	int j=0;
	while((m&1)==0)
	{
		j++;
		m>>=1;
	}
	ll x=mod_pow(a,m,n);
	if(x==1||x==n-1) return false;
	while(j--)
	{
		x=mod_mul(x,x,n);
		if(x==n-1) return false;
	}
	return true;
}
bool Miller_Rabin(ll n)//判断n是否为素数
{
	srand(time(0));
	if(n<2) return 0;
	if(n==2) return 1;
	if((n&1)==0) return 0;
	for(int i=0;i<Times;i++)
	{
		ll a=rand()%(n-1)+1;
		if(witness(a,n)) return false;
	}
	return true;
}
ll Pollard_Rho(ll n,int c)
{
	ll x=2,y=2,d=1;
	while(d==1)
	{
		x=mod_mul(x,x,n)+c;
		y=mod_mul(y,y,n)+c;
		y=mod_mul(y,y,n)+c;
		d=gcd((x-y>=0?x-y:y-x),n);
	}
	if(d==n) return Pollard_Rho(n,c+1);
	return d;
}
bool Is_Prime(ll n)
{
	if(n<maxn&&is_prime[n]||n>=maxn&&Miller_Rabin(n))return 1;
	return 0;
}
void Find_Factor(ll n)
{
    if(Is_Prime(n))
    {
        factor[n]++;
        return;
    }
    for(int i=0;i<prime.size()&&prime[i]<=n;i++)
    	if(n%prime[i]==0)
    	{
    		while(n%prime[i]==0)
    		{
    			factor[prime[i]]++;
    			n/=prime[i];
    		}
    	}
    if(n!=1)
    {
    	if(Is_Prime(n))
    		factor[n]++;
    	else
    	{
    		ll p=Pollard_Rho(n,1);
    		Find_Factor(p);
    		Find_Factor(n/p);
    	}
    }
}
int main()
{
	get_prime();
	factor.clear();
	Find_Factor(n);
}