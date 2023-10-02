#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
	int a[27] = 
	{1,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	string s;
	int cnt = 0;
	getline(cin, s);
	for(int i = 0; i < int(s.length());i++){
		if(s[i]>='a'&&s[i]<='z')cnt += a[s[i]-'a'+1];
		if(s[i] == ' ') cnt+=a[0];
	}
	cout << cnt;
	return 0;
}
