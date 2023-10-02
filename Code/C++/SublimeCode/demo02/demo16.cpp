#include<iostream>
using namespace std;

int* reverse(int *list, int size);
void PrintArray(const int *list, int size);


int main(){
    int list[] = {1,2,3,4,5,6};
    int size = sizeof(list)/sizeof(list[0]);
    int* p = reverse(list,size);
    PrintArray(p,size);
	return 0;
}

int* reverse(int *list, int size){
	// for(int i = 0, j = size-1; i < j; i++,j--){
	// 	int temp = list[j];
	// 	list[j] = list[i];
	// 	list[i] = temp;
	// }
	for(int i = 0; i < size/2;i++){
		int temp = list[size-1-i];
		list[size-1-i] = list[i];
		list[i] = temp;
	}
	return list;
}
void PrintArray(const int* list, int size){
	for (int i = 0; i < size; ++i){
		cout << list[i] << '\t';
	}
	cout << endl;
}