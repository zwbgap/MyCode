#include <bits/stdc++.h>
using namespace std;
long long a[50] = {0,1,1};
long long fib(int n){
	if(n == 0) return 0;
	if(!a[n]) a[n] = fib(n-1) + fib(n-2);
	return a[n];
}
int main(){
	int n; cin >> n;
	cout <<fib(n) << ".00";
	return 0;
}
