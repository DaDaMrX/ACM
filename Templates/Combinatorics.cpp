//简单求组合数
ll C(int n, int m)
{
    ll ans = 1;
    m = min(m, n - m);
    int k = n - m;
    for (int i = 1; i <= m; i++)
        ans = ans * (i + k) / i;
    return ans;
}
