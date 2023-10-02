#include<bits/stdc++.h>
using namespace std;
#define N 10005
int main(){
	int n;
	cin >> n;
	int a[N], b[N];
	for(int i = 0; i < n;i++) cin >> a[i];
	for(int j = 0; j < n;j++){
		if(a[j] <= 10) b[j] = a[j];
		else if(a[j] < 100) b[j] = a[j] / 10 + 9;
		else if(a[j] < 1000) b[j] = a[j] / 100 + 18;
		else if(a[j] < 10000) b[j] = a[j] / 1000 + 27;
		else if(a[j] < 100000) b[j] = a[j] / 10000 + 36;
		else b[j] = a[j] / 100000 + 45;
			
	}
	for(int i = 0; i < n; i++) cout << b[i] << "\n";
	return 0;
	
}
