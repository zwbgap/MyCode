#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x; 
	cin >> n;
	int a[5005] = {0};
	for(int i = 0; i < n; i++){
		cin >> x;
		if(a[x] == 1) continue;
		else {
			a[x] = 1;
			cout << x <<" ";
		}
		
	}
	return 0;
}
