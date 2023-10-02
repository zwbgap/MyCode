#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
T1 maxValue(const T1& a, const T2& b){
	return a > b ? a : b;
}

int main(){
	//string s1 = "ABC", s2 = "NBC";
	cout << maxValue(1.4,2) << endl;
    cout << maxValue(3.5,6.1) << endl;
    cout << maxValue('F','L') << endl;
    cout << maxValue(string("ABC"),string("NBC")) << endl;
    //cout << maxValue("ABC","NBC") << endl;
    //cout << maxValue(s1,s2) << endl;

	return 0;
}