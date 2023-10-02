#include<iostream>
#include<string>
using namespace std;

int main(){
	string s1("0123456789abcdef");
	string s2;
	cout << s1 << endl;
    cout <<	s2.assign(s1) << endl;//默认拷贝
	
	cout << s2.assign(s1,6,5) << endl;//下表6开始，长度为3
	cout << s2.assign(s1,5,s1.npos) << endl;
	//npos为静态常量，表示字符串结尾
	cout << s2 << endl;
	//拷贝5个‘X’
	cout << s2.assign(5,'X') << endl;
	//追加
	cout << s2.append(5,'X') << endl;
	
	string::iterator itB = s1.begin();
	string::iterator itE = s1.end();
	//迭代器范围内拷贝
	cout << s2.assign(itB, itE-6);
	
	
	
	return 0;
}
