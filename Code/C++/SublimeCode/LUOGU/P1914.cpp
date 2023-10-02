#include<iostream>
#include<string>
using namespace std;

int main(){
	int n; 
	cin >> n;
	string s; 
	cin >> s;
	for(int i = 0; i < int(s.length());i++){
		if(s[i]+n <= 'z') s[i] += n;
		else s[i] += n - 'z' + 'a' - 1;
		cout << s[i];
	}
    //cout << (1 ^ 0) ;
	return 0;
}
