#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main(){
	string s("abcdefghijkl");
	cout << "s:" << s << endl;
    cout << "s.length:" << s.length() << endl;
	//data()
	const char* d = s.data();
	cout << "d:" << d << endl;
	cout <<"strlen(d):" << strlen(d) << endl;
	cout << "c_str:" << s.c_str() << endl;
	cout << s.c_str()[0] << endl;
	cout << "strlen(cs):" << strlen(s.c_str()) << endl;
	
	
	return 0;
}
