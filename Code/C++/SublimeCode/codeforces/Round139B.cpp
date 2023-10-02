#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	bool flag = false;
	cin >> t;
	int a[t];
	string ss[t];
	for(int i = 0; i < t;i++){
		cin >> a[i] >> ss[i];
	}
	for(int i = 0; i < t;i++){
		flag = false;
		for(int j = 0; j < int(ss[i].length()-3);j++){
			for(int k = j+2;k < int(ss[i].length()-1);k++){
				if(ss[i][j] == ss[i][k] && ss[i][j+1] == ss[i][k+1]){
					cout << "YES" << '\n'; flag = true;
					break;
				}	
			}
			if(flag) break;
		}
		if(!flag) cout <<"NO" << '\n';
	}
	
	return 0;
}
