#include<iostream>
using namespace std;
#define n 10
void selectSort(double [], int);

int main(){
    int m;
    cin >> m;
    double list[m] = {0};
    while(n--){
    	cin >> list[j++];
    }
    
    selectSort(list,m);
    for(int i = 0; i < m;i++)
    	cout << list[i] << " ";
	return 0;
}

void selectSort(double list[], int listSize){
	for(int i = 0; i < listSize-1;i++){
		double currentMin = list[i];
		int currentMinIndex = i;
		for(int j = i + 1; j < listSize;j++){
			if(currentMin > list[j]){
				currentMin = list[j];
				currentMinIndex = j;
			}
		}
		if(currentMinIndex != i){
			list[currentMinIndex] = list[i];
			list[i] = currentMin;
		}
	}
}