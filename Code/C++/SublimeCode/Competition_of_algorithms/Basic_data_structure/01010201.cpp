//洛谷P1996,结构体数组实现单向静态链表
//1 <= m,n <= 100
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 105;    //定义静态链表空间大小
struct node{
	int id, nextid;   //单向指针
}nodes[N];            //定义在全局的静态分配
int main(){
	int n, m;
	cin >> n >> m;
	nodes[0].nextid = 1;
	for(int i = 1; i <= n; i++){
		nodes[i].id = i;
		nodes[i].nextid = i+1;
	}
	nodes[n].nextid = 1;  //有效数据下标为1-n
	//循环静态链表(数组)完成
	int now = 1, prev = 1;
	while((n--) > 1){
		for(int i =1; i < m; i++){
			prev = now;
			now = nodes[now].nextid;
		}
		cout << nodes[now].id << " ";
		nodes[prev].nextid = nodes[now].nextid; 
		//跳过now节点,即删除, 注意原数组中还在,遍历的表中因下标原因而不再遍历
		now = nodes[now].nextid;
	}
	cout << nodes[now].id << endl;
	return 0;
}
