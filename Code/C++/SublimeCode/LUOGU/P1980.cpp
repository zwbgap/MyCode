#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, x, c,m = 0;
	cin >> n >> x;
	for(int i = 1; i <= n;i++){
		c = i;
		while(c){
			if(c%10 == x) m++;
			c /= 10;
		}
	}
	cout << m;
	
	return 0;
}
