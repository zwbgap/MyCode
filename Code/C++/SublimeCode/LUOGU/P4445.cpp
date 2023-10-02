#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[10001], d = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		d += max(a[i], a[i+1]);
	}
	cout << d;

}