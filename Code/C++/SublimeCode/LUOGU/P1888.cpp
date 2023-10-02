#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
inline ll gcd(ll a, ll b){
	int n;
	for(ll i = a; i > 0;i--){
		if(a%i==0 && b%i==0){
			n = i;
			break;
		}
	}
	return a/n;
}
int main(){
	ll a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	cout << gcd(a[0],a[2]) << '/' << gcd(a[2],a[0]);
	
	return 0;
}

