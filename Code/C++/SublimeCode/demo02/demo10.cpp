#include <iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int array[n],new_array[n];
	for(int i = 0; i < n; i++){
		cin >> array[i];
	}
	sort(array,array + n);
	for(int i = 0; i < n; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	int j = 0, k =0;
	for(int i = 1; i < n; i++){
		if(array[i] != array[i-1])
			new_array[j++] = array[i-1];
	}
	new_array[j++] = array[n-1];
	while(j--) cout << new_array[k++] << " ";
	cout << endl;
	
	return 0;
}