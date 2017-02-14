#include <bits/stdc++.h>
using namespace std;
bool have[30];
int main(int argc, char const *argv[]) {
	//freopen("input.txt","r",stdin);
	string str; cin>>str;
	memset(have,0,sizeof(have));
	have[0] =1;
	bool can = true;
	for(int i=0; i<str.length(); i++) {
		if(have[(int)(str[i]-'a')]==true) {
			have[(int)(str[i]-'a')+1]= true;
		}
		else {
			can = false;
			break;
		}
	}
	if(can)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}