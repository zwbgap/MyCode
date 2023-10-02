#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int>&v);

int main(){
	vector<int>v;
	v.insert(v.begin(),8);   print(v);
	int arr[3] = {1,2,3};
	fill(arr,arr+2,9);
	v.insert(v.end(),arr+1,arr+3);
	print(v);
	vector<int>::iterator it = v.end();
	v.insert(it,arr+1,arr+2);
	print(v);
	it = v.end();
	v.insert(it-1,2,75);
	print(v);
	v.erase(v.begin());
	print(v);
	v.erase(v.begin()+1,v.end());
	print(v);
	system("pause");
	return 0;
}
template<class T>
class show{
public:
	void operator()(T& t){
		cout << t << " ";
	}
};
void print(vector<int>& v){
	cout << "vector v:" << "\t";
	show<int>myShow;
	for_each(v.begin(),v.end(),myShow);
	cout << endl;
	cout << "v.size:\t\t" << v.size() << endl;
	cout << "v.capacity:\t" << v.capacity() << endl;
	cout << "\n";
	
}
