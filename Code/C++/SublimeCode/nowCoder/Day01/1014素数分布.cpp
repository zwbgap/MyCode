#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
	for(int j = 2; j <= sqrt(n); j++){
		if(n % j == 0) return false;
	}
	return true;
}
int main(){
	int n, cnt = 0;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		cnt = 0;
		for(int k = 2; k <= a[i]; k++){
			if(isprime(k)) cnt++;
		}
		b[i] = cnt;
	}
	for(int j = 0; j < n; j++) cout << b[j] << "\n";
	
	return 0;
}
