#include <bits/stdc++.h>
using namespace std;
double dist(int a,int b,int c,int d){
	return sqrt(pow(a-c,2)+pow(b-d, 2));
}
int main(){
	int n, x1, y1, x2, y2, cnt = 0;
	int a[60], b[60], c[60];
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = 0; i < n; i ++){
		if((dist(x1,y1,a[i],b[i]) < c[i]) ^ (dist(x2,y2,a[i],b[i]) < c[i]))
			cnt++;
	}
	cout << cnt;
	return 0;
}
