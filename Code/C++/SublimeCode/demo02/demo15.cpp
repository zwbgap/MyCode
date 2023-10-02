#include<iostream>

using namespace std;
void f(int i, int j, int *k);
int main(){
	// string s("ABCD");
	// string* p = &s;
	// cout << p << endl;
	// cout << *p << endl;
	// cout << (*p)[0] << endl;
	 
	int list[6] = {1,9,3,4,5,6};
	int* p = list;
	// for(int i = 0; i < 6; i++){
	// 	cout << "address: " << (list + i)
	// 	   << "\tvalue: " << *(list + i)
	// 	   << "\tvalue: " << list[i]
	// 	   << "\tvalue: " << *(p+i)
	// 	   << "\tvalue: " << p[i] << endl;
	// 	   }
	
	// cout << p << endl;
	// cout << *p <<endl;
	// cout << *p++ << endl;
	// cout << *p <<endl;
	// cout << *(p++) << endl;
	// cout << p++ << endl;
	// cout << *(p++) << endl;
	// cout << *p << endl;
	// cout << (*p)++ << endl;
	// cout << *p <<endl;
    
    // char*  pCity = "Dallas";
    // cout << pCity[0] << endl;
    // char* cities[] = {"Dallas", "Atlanta", "Houston"};

    // cout << cities[0] << endl;
    // cout << cities[0][0] << endl;
    

    int i = 1, j = 1, k = 1;
    f(i,j,&k);
    cout << i << '\n' << j << '\n' << k << endl;
	return 0;
}
void f(int i, int j, int* k){
	i++;
	j++;
	(*k)++;
}