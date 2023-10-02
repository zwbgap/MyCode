//动态单向链表
//约瑟夫环 
//input: 10 3  output: 3 6 9 2 7 1 8 5 10 4
#include <bits/stdc++.h>
using namespace std;
struct node{      //定义链表节点
	int data;     //节点数据
	node * next;  //单向链表只需要next指针，指向下一个节点
};
int main(){
	int n, m;
	cin >> n >> m;
	node * head, * p, * now, *prev; //定义变量
	head = new node; head->data = 1; head->next = NULL; //分配头结点，数据置1
	now = head;   //当前指针为头指针
	for(int i = 2; i <= n; i++){
		p = new node; p->data = i; p->next = NULL; //p为动态创建新节点
		now->next = p;
		now = p;
	}
	now->next = head; 
	//循环单向链表建立完成
	now = head,  prev = head;
	while((n--) > 1){
		for(int i = 1; i < m; i++){//遍历到m前一个
			prev = now; //记录位置，用于跳过第m个节点
			now = now->next;
		}
		cout << now->data << " ";
		prev->next = now->next;
		delete now;
		now = prev->next;
	}
	cout << now->data << endl;
	delete now;
	
	return 0;
}
