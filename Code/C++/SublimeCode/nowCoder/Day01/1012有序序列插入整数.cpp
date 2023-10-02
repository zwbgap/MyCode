#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, tar;
	cin >> n;
	int a[55] = {0};
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> tar;
	for(int j = n-1; j >= 0;j--){
		if(a[j] > tar){
			a[j+1] = a[j];
			a[j] = tar;
		}
	}
	for(int j = 0; j <= n;j++){
		cout << a[j] << " ";
	}	
	return 0;
}
