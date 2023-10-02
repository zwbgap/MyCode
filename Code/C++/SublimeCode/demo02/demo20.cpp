#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	// vector<int> v(10);
	// //v[0] = 4;
	// v[0] = 4;
	// v[1] = 5;
	// cout << v[0] << endl;
	// cout << v[1] << endl;
	vector<int> v;
	// for(int i=0; i<10; i++){
	// 	v.push_back(i);
	// }
	v.push_back(5);
	// for(int i=0; i<10; i++){
	// 	cout << v[i] << " ";
	// }
	cout << v[0] << endl;
	cout << v.size() << endl;
	return 0;
}