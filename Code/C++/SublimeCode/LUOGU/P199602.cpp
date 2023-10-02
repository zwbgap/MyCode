//结构体数组实现静态链表
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 105;
struct node{
	int id, nextid;
	//int data;
}nodes[N];
int main(){
	int n, m;
	cin >> n >> m;
	nodes[0].nextid = 1;
	for(int i = 1; i <= n; i++){
		nodes[i].id = i;
		nodes[i].nextid = i+1;
	}
	nodes[n].nextid = 1;
	int now = 1, prev = 1;
	while((n--)>1){
		for(int i = 1; i < m; i++){
			prev = now;
			now = nodes[now].nextid;
		}
		cout << nodes[now].id << endl;
		nodes[prev].nextid = nodes[now].nextid;
		now = nodes[prev].nextid;
	}
	cout << nodes[now].id << endl;

	return 0;
}