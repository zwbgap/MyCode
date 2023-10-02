//Max Sum hdu 1003
//给定序列，求最大子序列和
#include <bits/stdc++.h>
using namespace std;
int dp[100005]; //dp[i]: 以第i个数结尾的最大值
int main(){
	int t; cin >> t;
	for(int k =1; k <= n;k++){
		int n; cin >> n;
		for(int i = 1; i <= n; i++) cin >> dp[i];
		int start = 1, end = 1, p = 1;
		int maxsum = dp[1];
		for(int j = 2; j <= 2;j++){
			if(dp[i-1]+dp[i] >= dp[i])
				dp[i] = dp[i-1] + dp[i];
			else p = i;
			if(dp[i] >maxsum){
				maxsum = dp[i];
				start = p; end = j;
			}
		cout << "Case " << k << ":\n" << maxsum << " "
		     << start << " " << end << "\n";
		if(k != t) cout << endl;
	}	
	return 0;
}