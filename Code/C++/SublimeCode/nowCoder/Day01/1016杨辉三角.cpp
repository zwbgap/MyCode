#include <bits/stdc++.h>
using namespace std;
int main(){	
	int n; cin >> n;
	vector<vector<int> > res(n);
	for(int i = 0; i < n;i++){
		res[i].resize(i+1);
		res[i][0] = res[i][i] = 1;
		for(int j = 1; j < i;j++){
			res[i][j] = res[i-1][j-1] + res[i-1][j];
		}
	}
	for(int i = 0; i < n;i++){
		vector<int>::iterator it = res[i].begin();
		while(it != res[i].end()){
			cout << *it << " ";
			it++;
		}
		cout << " \n";
	}
	return 0;
}
