int head[N], d[N], s, t, no, dis[N][N], vis[N], pre[N];
struct Node
{
	int u, v, flow, next, cost;
	Node(){};
	Node(int x, int y, int z, int w,int c) : u(x), v(y), next(z), flow(w),cost(c) {};
} p[M];
void add(int x, int y, int z,int c)
{
	p[no] = Node(x, y, head[x], z,c); head[x] = no++;
	p[no] = Node(y, x, head[y], 0,-c); head[y] = no++;
}
void init()
{
	memset(head, -1, sizeof(head));
	no = 0;
}
queue<int>q;
bool spfa()
{
    int i, x, y;
    while (!q.empty()) q.pop();
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    d[s] = 0; vis[s] = true; q.push(s);
    while(!q.empty())
    {
        x = q.front(); q.pop(); vis[x] = false;
        for(i = head[x]; i != -1; i = p[i].next)
        {
            if(p[i].flow && d[y = p[i].v] > d[x] + p[i].cost)
            {
                d[y] = d[x] + p[i].cost; pre[y] = i;
                if(vis[y])  continue;
                vis[y] = true;  q.push(y);
            }  
        } 
    }
    return d[t] != d[t + 1];
}
int mcmf()
{
    int mincost = 0, maxflow = 0, minflow, i;
    while(spfa())
    {
        minflow =INF;
        for(i = pre[t]; i != -1; i = pre[p[i].u])
            minflow = min(minflow, p[i].flow);
        for(i = pre[t]; i != -1; i = pre[p[i].u])
        {
            p[i].flow -= minflow;
            p[i ^ 1].flow += minflow;
        }
        mincost += d[t] * minflow; maxflow += minflow;
    }
    return mincost;
}