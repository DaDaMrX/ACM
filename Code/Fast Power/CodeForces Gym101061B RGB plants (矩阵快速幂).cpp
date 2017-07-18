// CodeForces Gym101061B RGB plants (矩阵快速幂)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 4;
const int mod = 1e9 + 7;

struct Matrix
{
    ll a[4][4];
};

Matrix operator*(Matrix& M1, Matrix& M2)
{
    Matrix A;
    memset(A.a, 0, sizeof(A.a));
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                A.a[i][j] = (A.a[i][j] + M1.a[i][k] * M2.a[k][j] % mod) % mod;
    return A;
}

Matrix power(Matrix a, ll n)
{
	Matrix ans;
    ans.a[1][1] = 1; ans.a[1][2] = 0; ans.a[1][3] = 0; 
    ans.a[2][1] = 0; ans.a[2][2] = 1; ans.a[2][3] = 0; 
    ans.a[3][1] = 0; ans.a[3][2] = 0; ans.a[3][3] = 1; 
	while (n)
	{
		if (n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}

int main()
{
    Matrix M;
    M.a[1][1] = 1; M.a[1][2] = 4; M.a[1][3] = 7;
    M.a[2][1] = 2; M.a[2][2] = 5; M.a[2][3] = 8;
    M.a[3][1] = 3; M.a[3][2] = 6; M.a[3][3] = 9;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        Matrix A = power(M, n - 1);
        ll ans = 0;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                ans = (ans + A.a[i][j]) % mod;
        printf("%I64d\n", ans);
    }
    return 0;
}
