#include <iostream>
#include <cmath>

using namespace std;

void get_Pi(int n);
bool is_prime(int number);

int main(){
    int n;
    // while(cin >> n && n){
    // 	get_Pi(n);
    // }
    while(cin >> n && n){
    	if(n < 2) cout << "error" << endl;
    	for(int i = 2; i <= n;i++){
    		if(is_prime(i) && is_prime(i+2)){
    			cout << "(" << i << ", " << i+2 << ")" << endl;
    		}

    	}
    }
    int size = 4;
    double myList[size];
	return 0;
}

void get_Pi(int n){
	double Pi = 0;
	for(unsigned i = 1; i <= n; i++){
		Pi += 4 * (pow(-1,(i+1))/(2*i-1));
	}
	cout << Pi << endl;
}

bool is_prime(int number){
	int m = int(sqrt(number))+1;
	for(int j = 2; j <= m;j++){
		if(number % j == 0) return false;
	}
	return true;
}