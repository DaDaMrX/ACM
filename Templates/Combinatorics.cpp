//筛组合数
ll C[N][N];
void init(int n, int mod)
{
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= mod) C[i][j] -= mod;
        }
    }
}

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

// Catalan数
ll cat[N];
void catalan(int n)
{
    memset(cat, 0, sizeof(cat));
    cat[0] = cat[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            cat[i] = (cat[i] + cat[j] * cat[i - j - 1] % mod) % mod;
}
