#include<iostream>
#include<climits>
using namespace std;
int main(){
	int n, a, b, c[3], m = INT_MAX;
	cin >> n;
	for(int i = 0; i < 3;i++){
		cin >> a >> b;
		c[i] = n / a * b;
		if(n%a != 0)
			c[i] += b;
		m = c[i]<m?c[i]:m;
	}
	cout << m;
	return 0;
 }
