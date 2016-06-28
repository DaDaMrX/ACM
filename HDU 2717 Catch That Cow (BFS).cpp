#include <cstdio>  
#include <cstring>  
#include <queue>  
using namespace std;  
#define N 100010  
queue<int> q;  
int step[N];  
int bfs(int n, int k)  
{  
    while (!q.empty()) q.pop();  
    q.push(n); step[n] = 0;  
    while (q.front() != k)  
    {  
        int from = q.front(); q.pop();  
        int to = from - 1;  
        if (to >= 0 && step[to] == -1)  
        {  
            q.push(to);  
            step[to] = step[from] + 1;  
        }  
        to = from + 1;  
        if (to < N && step[to] == -1)  
        {  
            q.push(to);  
            step[to] = step[from] + 1;  
        }  
        to = from * 2;  
        if (to < N && step[to] == -1)  
        {  
            q.push(to);  
            step[to] = step[from] + 1;  
        }  
    }  
    return step[k];  
}  
int main()  
{  
    int n, k;  
    while (~scanf("%d%d", &n, &k))  
    {  
        memset(step, -1, sizeof(step));  
        int ans = bfs(n, k);  
        printf("%d\n", ans);  
    }  
    return 0;  
}
