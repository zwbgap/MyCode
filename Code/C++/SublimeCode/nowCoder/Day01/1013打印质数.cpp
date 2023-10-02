#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
	for(int j = 2; j <= sqrt(n); j++){
		if(n % j == 0) return false;
	}
	return true;
}
int main(){
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		if(isprime(i)) cout << i << " ";
	}
	return 0;
}
