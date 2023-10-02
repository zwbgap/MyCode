//P1886 STL deque
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N];
deque<int> q; //队列中的数据实际上是元素在原序列中的位置
int main(){
	int n, m;
	scanf("%d%d",&n, &m);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	//输出最小值
	for(int i = 1; i <= n; i++){
		while(!q.empty() && a[q.back()] > a[i]) q.pop_back();    //去尾
		q.push_back(i);
		if(i >= m){
			while(!q.empty() && q.front() <= i-m) q.pop_front();  //删头
			printf("%d ", a[q.front()]);
		}
	}
	printf("\n");
	//输出最大值
	while(!q.empty()) q.pop_front(); //清空初始化
	for(int i = 1; i <= n; i++){
		while(!q.empty() && a[q.back()] < a[i]) q.pop_back();    //去尾
		q.push_back(i);
		if(i >= m){
			while(!q.empty() && q.front() <= i-m) q.pop_front();  //删头
			printf("%d ", a[q.front()]);
		}
	}
	
	return 0;
}
