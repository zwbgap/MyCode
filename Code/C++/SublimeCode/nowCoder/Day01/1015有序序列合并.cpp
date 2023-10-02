#include <bits/stdc++.h>
using namespace std;

int main(){
	int n1, n2;
	cin >> n1 >> n2;
	int a[n1], b[n2];
	vector<int> res;
	int p = 0, q = 0;
	for(int i = 0; i < n1;i++) cin >> a[i];
	for(int j = 0; j < n2;j++) cin >> b[j];
	while(p < n1 || q < n2){
		if(a[p] <= b[q]) 
			res.push_back(p == n1 ? b[q++] : a[p++]);
		else res.push_back(q == n2 ? a[p++] :b[q++]);
	}	
	vector<int>::iterator it = res.begin();
	while(it != res.end()){
		cout << *it << " ";
		it++;
	}
	return 0;
}
