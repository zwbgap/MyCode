#include<iostream>
using namespace std;
#define N 10
void bubbleSort(int *arr, int n){
	if(arr == NULL || n < 2){
		cout << "error" << endl;
		return;
	}
	for(int i = n-1; i > 0; i--){
		for(int j = 0; j < i;j++){
			if(arr[j] >arr[j+1])
				swap(arr[j],arr[j+1]);
		}
	}
	for(int i = 0; i < n;i++)
		cout << arr[i] << " ";
	cout <<endl;
	
}

int main(){
	int arr[N];
	int flag;
	while(cin >> flag && flag){
		for(int i = 0; i < N;i++)
			cin >> arr[i];
		bubbleSort(arr,N);
	}
	
	return 0;
}
