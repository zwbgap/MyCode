#include<iostream>
using namespace std;
#define N 10

void selectionSort(int arr[],int n){
	if(arr == NULL || n < 2){
		cout << "error";
		return;
	}
	for(int i = 0; i < n; i++){
		int minIndex = i;
		for(int j=i+1;j<n;j++){
			minIndex = arr[minIndex] > arr[j] ? j:minIndex;
		}
		swap(arr[i],arr[minIndex]);
	}
	for(int i = 0;i < N;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main(){
	int arr[N];
	for(int i = 0;i < N;i++){
		cin >> arr[i];
	}
	selectionSort(arr,N);
}
