#include<stdio.h>
void arrin(int a[], int n);
void arrout(int a[], int n);
void sort(int a[], int n);
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	arrin(a, n);
	arrout(a, n);
	sort(a, n);
	arrin(a, n);
	return 0;
}
void arrin(int a[], int n){
	int i = 0;
	while(1){
		scanf("%d", &a[i++]);
		if(i >= n){
			printf("数组越界，重新输入：");
			arrin(a, n);
		}
	}
}
void arrout(int a[], int n){
	for(int i = 0; i < n;i++){
		printf("%d", a[i]);
	}
}
void sort(int a[], int n){
	for(int i = 0; i < n-1;i++){
		for(int j = 0; j < n-i-1; j++){
			if(a[j] < a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
