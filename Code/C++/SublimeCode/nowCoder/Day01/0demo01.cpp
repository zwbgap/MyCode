#include <bits/stdc++.h>
using namespace std;

int main(){	
	int n, k; cin >> n >> k;
	vector<int> res;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		res.push_back(a);
	}
	for(int i = 0; i < n; i++){
		cout << res[i];
	} 
	int len = res.size();
	for(int i = 0; i < len-1; i++){
		for(int j = i+1; (j<=i+k&&j<n);j++){
			if((res[i] == res[j]))
				cout << "true";
		}
	}
	cout << "false";
	return 0;
}
