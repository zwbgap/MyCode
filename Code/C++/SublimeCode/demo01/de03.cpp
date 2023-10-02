#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int a[3] = {0};
	cin >> s;
	for(int i = 0; i < int(s.length())-1;i++){
		if(s[i] == '='){
			if(s[i+1] >= '0' && s[i+1] <= '9')
				a[int(s[i-2])-97] = int(s[i+1]-'0');
			else
				a[int(s[i-2]-97)] = a[int(s[i+1]-97)];
		}
	}
	cout << a[0] << " " << a[1] << " " << a[2];
	return 0;
}

