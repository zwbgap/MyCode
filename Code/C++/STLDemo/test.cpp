#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
#define N 11
void swap(int a, int b){
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << "a:" << a << "\n" << 
	"b:" << b << endl;
}


void OddTimesNum(int arr[], int n){
	int eor = 0;
	for(int cur = 0;cur < n; cur++){
		eor ^= arr[cur];
	}
	cout << "奇数次数字：" << eor << endl;
}
int climbStairs(int n) {
	if(n <= 2) return n;
	int dp[n];
	//int *dp = new int[n];
	dp[0] = 1;
	dp[1] = 2;
	for(int i = 2; i < n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	//delete []dp;
	return dp[n-1];
	
}

vector<int> twoNum(vector<int>&nums, int target){
	int i, j;
	for(i = 0; i < int(nums.size()-1);i++){
		for(j = i+1;j < int(nums.size());j++){
			if(nums[i]+nums[j]== target)
				return{i,j};
		}
	}
	return{};
}
void fib(int n){
	int a[n] = {0};
	a[0] = 1;
	a[1] = 1;
	int i;
	for(i = 2; i < n; i ++)
		a[i] = a[i-1] + a[i-2];
	cout <<i << endl;
	cout <<a[i-1] <<endl;
	cout << a[n-1] << endl;
}
int main(){
//	int a, b;
//	while(cin >> a >> b && a != -1){
//		swap(a, b);
//		cout << "a:" << a << "\n" << 
//		  "b:" << b << endl;
//	}
//    int arr[N];
//	for(int i=0;i<N;i++){
//		cin >> arr[i];
//	}
//	OddTimesNum(arr,N);

//  int m;
//	cin >> m;
//	cout << climbStairs(m);
//
//    vector<int> arr(5);
//	int target = 16;
//	for(int i=0;i<5;i++){
//		cin >> arr[i];
//	}
//	twoNum(arr,target);
    int x;
	cin >> x;
    fib(x);    

    return 0;
}
