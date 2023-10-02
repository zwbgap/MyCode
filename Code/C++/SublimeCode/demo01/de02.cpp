#include<iostream>
#include<math.h>
using namespace std;
int prime(int n);
int main()
{
	int i, n;
	for(i = 4; i <= 2000;i++) {
		for(n = 2; n < i;n++){
			if(prime(n) && prime(i-n)){
				cout << i << "=" << n << "+" << i-n <<'\n';
				break;
			}
			if(n == i)
				cout << "error" << '\n';
		}
	}
	return 0;
}

int prime(int i){
	int j;
	if(i < 1) return 0;
	if(i == 2) return 1;
	for(j = 2; j <= (int)(sqrt((double)i)+1);j++){
		if(!(i%j)) return 0;
	}
	return 1;
}
