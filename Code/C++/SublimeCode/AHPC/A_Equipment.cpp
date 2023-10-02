#include <bits/stdc++.h>
using namespace std;

/*int equip(int n, int k){
	if(n < k + 2)
		return n+1;
	return equip(n-1,k) + equip(n-k-1,k);7
}*/
long long dp[100000];
long long equip(int n, int k){
	if(dp[n]) 
		return dp[n];
	if(n < k + 2) 
		return n + 1;
	return dp[n] = equip(n-1, k) + equip(n-k-1,k);
}

int main(){
	int n, k;
	cin >> n >> k;
	memset(dp,0,sizeof(dp));
	cout << equip(n, k) << endl;
	//cout << dp[n] << endl;
//	cout << (dp[n]%5000011) << endl;
	return 0;
}
