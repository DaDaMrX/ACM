int sg[N];
int dfs(int x)
{
	if (sg[x] != -1) return sg[x];
	bool vis[15];
	memset(vis, false, sizeof(vis));
	for (int i = 0; i <= k; i++)
	{
		if (i > x) break;
		vis[dfs(x - i)] = true;
	}
	int i = 0;
	while (vis[i]) i++;
	return sg[x] = i;
}

void sprague_grundy()//打表求SG[x]模板
{
    int i,j;
    sg[0]=0;
    for (i=1;i<H;i++){
        memset(mex,0,sizeof(mex));
        j=1;
        while (j<=k && i>=s[j]){ 
            mex[sg[i-s[j]]]=1;
            j++;
        }
        j=0;
        while (mex[j]) j++;
        sg[i]=j;
    }
}
