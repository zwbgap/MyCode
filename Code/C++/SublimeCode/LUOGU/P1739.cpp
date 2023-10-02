#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int j = 0;
	for(int i = 0;s[i] != '@';i++){
		if((j == 0)&&(s[i] = ')')){cout << "NO"; return 0;}
		if(s[i] == '(') j++;
		if(s[i] == ')') j--;
		if(j < 0){cout << "NO"; return 0;}
		if(s[i]== '@'){if(!j) cout << "YES";
			else cout << "NO";}
	}	
	return 0;
}


