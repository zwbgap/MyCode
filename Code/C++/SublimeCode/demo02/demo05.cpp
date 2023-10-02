#include<iostream>
#include<stack>
using namespace std;

int get_pentagonal_number(int n); // 定义五角数(3n-1)/2
int reverse(int number); //逆序
bool isPalindrome(int number); //回文
void displaySorted(double x, double y, double z); //升序

int main(){
	// int n = 100;
	// for(unsigned i = 1; i <= n; i++){
	// 	cout << get_pentagonal_number(i) << "\t";
	// 	if(i % 10 == 0) cout << endl;
	// }
	// 
	// int number;
	// while(cin >> number){
	// 	cout << isPalindrome(number) << endl;
	// }
	// 
	int a, b, c;
	cin >> a >> b >>c;

	displaySorted(a, b, c);
	return 0;
}

int get_pentagonal_number(int n){
	return n*(3*n-1)/2;
}
int reverse(int number){
	int reverse_num = 0,num = 0;
	while(number){
		num=number % 10;
		reverse_num = reverse_num * 10 + num;
		number /= 10;
	}
	//cout << reverse_num << endl;
	return reverse_num;
}
bool isPalindrome(int number){
	if(number == reverse(number))
		return true;
	return false;
}
void displaySorted(double a, double b, double c){
	double t;
	if(a > b){
		t=a;  a=b;  b=t;
	}
	if(a > c){
		t=a;  a=c;  c=t;
	}
	if(b > c){
		t=b;  b=c;  c=t; 
	}
	cout << a << '\t' << b << '\t' << c << endl;
}