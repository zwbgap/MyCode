#include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long x, n, cnt = 1;
	cin >> x >> n;
	while(n--){
		cnt =  cnt * x + cnt;
	}
	cout << cnt;
	return 0;
}
