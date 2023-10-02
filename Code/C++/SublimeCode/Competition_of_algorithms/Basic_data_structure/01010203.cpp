//洛谷P1996,一维数组实现单向静态链表
//1 <= m,n <= 100
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int nodes[150]; 
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n-1; i++){
		nodes[i] = i+1;
	}
	nodes[n] = 1; //数组的值就是下一个数据的下标
	//循环链表完成
	int now = 1, prev = 1;
	while((n--) > 1){
		for(int i = 1; i < m; i++){
			prev = now;
			now = nodes[now];
		}
		cout << now << " ";
		nodes[prev] = nodes[now];
		now = nodes[prev];
	}
	cout << now << endl;
	return 0;
}
