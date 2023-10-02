#include<bits/stdc++.h>
using namespace std;
int main(){
	string s, ss;
	cin >> s;
	ss = s;
	int N = s.length();
	for(int i = 1;i<N;i++){
		cin >> s; ss += s;
	}
	int a[N*N+10] = {0};
	for(int i = 1; i <= N*N;i++)
		a[i] = ss[i-1] - '0';
	cout << N << " ";
	int m = 1;
	for(int i = 1; i <= N*N-1;i++){
		if(a[i] == a[i+1]) m++;
		else if(a[i] != a[i+1]){
			cout << m << " "; m = 1;
		}
	}
	if(a[N*N] == a[N*N-1]) cout << m;
	else cout << 1;
	return 0;
}
