#include<iostream>
#include<cctype>
#include<string>
using namespace std;

void max_t(int a, int b, int& MAX){
	MAX = a > b ? a : b;
}

int hex2edc(const string& hex);
int hexcharTodecimal(char ch);
int main(){

    string hex;
	cout << "Please enter a hex:" << endl;
    cin >> hex;
    //hex2edc(hex);
    cout << "The decimal value for the hex " << hex 
         << " is: " << hex2edc(hex) << endl;
	// int x = 20, y = 100;
    // x = x ^ y;
    // y = x ^ y;
    // x = x ^ y;
    // cout << x  << '\n' << y <<endl;
    // int max = 0;
    // max_t(10,6,max);
    // cout << "MAX = " << max <<endl;

	return 0;
}

int hex2edc(const string& hex){
	int decimalvalue = 0;
	for(unsigned i = 0; i < hex.size();i++)
		decimalvalue = decimalvalue * 16 + hexcharTodecimal(hex[i]);
	return decimalvalue;
}
int hexcharTodecimal(char ch){
	ch = toupper(ch);
	if(ch >= 'A' && ch <= 'Z')
		return ch - 'A' + 10;
	else
		return ch - '0';
}