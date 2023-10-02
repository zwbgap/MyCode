#include<iostream>
#include<algorithm>
#include<set>
//#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int n, m = 0;
	cin >> n;
	for(int i = 0; i < n;i++){
		cin >> a[i];
		m = a[i]>m?a[i]:m;
	}
	set<int>s(a,a+n);
	cout << m * 10 + n * 6 -(n-s.size()) * 5;
	return 0;
}
