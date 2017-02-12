int btoi(char s[])
{
	int len = strlen(s);
	int ans = 0;
	for (int i = 0; i < len; i++) 
	{
		ans <<= 1;
		if (s[i] == '1') ans += 1;
	}
	return ans;
}