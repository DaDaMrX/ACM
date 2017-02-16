//CodeForces Gym 101173A Appearance Analysis
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 150;

char s[N][N];
int n, m;

vector<string> vec;
set<vector<string> > st;

char t[N][N];
void rotate4()
{
	int n = vec.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			t[j][n - 1 - i] = vec[i][j];
	vec.clear();
	for (int i = 0; i < n; i++)
		vec.push_back(string(t[i]));
}
void rotate2()
{
	int n = vec.size(), m = vec[0].size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			t[n - 1 - i][m - 1 - j] = vec[i][j];
	vec.clear();
	for (int i = 0; i < n; i++)
		vec.push_back(string(t[i]));
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	int a = 1, b = 1;
	while (s[a][1] != '#') a++;
	while (s[1][b] != '#') b++;

	st.clear();
	int ans = 0;
	for (int x = 1; x < n; x += a)
		for (int y = 1; y < m; y += b)
		{
			vec.clear();
			for (int i = x; i <= x + a - 2; i++)
			{
				string str = "";
				for (int j = y; j <= y + b - 2; j++) str += s[i][j];
				vec.push_back(str);
			}

			int time = a == b ? 4 : 2;
			int k;
			for (k = 1; k <= time; k++)
			{
				if (find(st.begin(), st.end(), vec) != st.end()) break;
				if (a == b) rotate4();
				else rotate2();
			}
			if (k > time) st.insert(vec), ans++;
		}

	printf("%d\n", ans);
	return 0;
}
