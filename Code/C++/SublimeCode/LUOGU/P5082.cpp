#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	double a, b;
	scanf("%d",&n);
	double sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {scanf("%lf",&a);  sum1 += a; }
	for (int i = 0; i < n; i++) { scanf("%lf",&b);  sum2 += b; }
	cout << fixed << (sum1*3-sum2*2) / (sum1-sum2);
	
	return 0;
}
