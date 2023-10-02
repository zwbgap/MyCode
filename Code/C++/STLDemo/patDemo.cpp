#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n],b[n],c[n]= {0};
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
		
	}
		
	for(int j = 0; j < n;j++){
		if(a[j] + b[j] > c[j])
			cout << "Case #" << j << ": true" << endl;
		else
			cout << "Case #" << j << ": false" << endl;
	}
	return 0;
}
