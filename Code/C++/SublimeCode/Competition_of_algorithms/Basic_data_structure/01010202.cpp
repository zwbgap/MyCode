//洛谷P1996,结构体数组实现双向静态链表
//1 <= m,n <= 100
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 105;
struct node{               //双向链表
	int id;                //节点编号
	int preid, nextid;     //节点指针,前指针,后指针
}nodes[N];
int main(){
	int n, m;
	cin >> n >> m;
	nodes[0].nextid = 1;
	for(int i = 1; i <= n; i++){
		nodes[i].id = i;
		nodes[i].preid = i-1;
		nodes[i].nextid = i+1;
	}
	nodes[n].nextid = 1; //尾->头
	nodes[1].preid = n;  //头->尾
	//双向链表(数组)建立完成
	int now = 1;         //从第一个节点开始
	while((n--) > 1){
		for(int i = 1; i < m; i++){
			now = nodes[now].nextid;
		}
		cout << nodes[now].id << " ";
		int prev = nodes[now].preid, next = nodes[now].nextid;
		nodes[prev].nextid = nodes[now].nextid;   //删除now
		nodes[next].preid = nodes[now].preid;
		now = next;                           //初始化now，重新开始
	}
	cout << nodes[now].id << endl;
	return 0;
}
