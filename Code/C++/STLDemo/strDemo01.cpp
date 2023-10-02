#include<bits/stdc++.h>
//#include<iostream>
//#include<string>
using namespace std;
int main(){
	string str("0123456789");
	str.reserve(12);  //重新分配空间，保留字符数
	cout << "str=" << str << endl;
	//str.resize(8); //修改字符串  多去少补‘a’
	//cout << "str=" << str << endl;
	
	cout << "size=" << str.size() << endl;
	cout << "length=" << str.length() << endl;
	cout << "MAX_size=" << str.max_size() << endl; 
	//capacity与size和length都有关
	cout << "capacity=" << str.capacity() << endl; //初值15，每次+16？
	
	
	if(!str.empty()) str.clear();//判空与清空
	cout << "str=" << str << endl;
	
	
	cout << "---------" << endl;
	string s1("string");
	char c;
	c = s1[s1.length()-2];
	cout << c << endl;
	cout << s1[s1.length()-1] << "\n";
	//cout << s1[50] << endl;//触发断言
	cout << s1.at(50) << endl;//触发异常
	
	return 0;
}
