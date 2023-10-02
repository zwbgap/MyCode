#include<stdio.h>
#include<math.h>
int prime(int n);
int main(){
	int cnt = 0;//计数器初始化为0
	for(int i = 10; i <= 15;i++){
		if(prime(i) == 1){//返回值为1则该数为质数
			cnt++;//计数器+1
		} 
	}
	printf("%d", cnt);
	return 0;
}
int prime(int n){
	for(int i = 2; i < sqrt(n);i++){
		if(n % i == 0) return 0;//n有因子，不为质数，返回0	
	}
	return 1;//循环完未发现因子则返回1
}

