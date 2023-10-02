#include <iostream>
using namespace std;

/* 链表结点结构体 */
struct ListNode {
	int val;         // 结点值
	ListNode *next;  // 指向下一结点的指针（引用）
	ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};

//链表初始化
ListNode* InitListNode(int n){
	//初始化链表 1-2-3-4-5
	//初始化各个节点
	ListNode *list[n];
	for(int i = 0; i < n;i++){
		ListNode *list[i] = new ListNode(i+1);
		if(i == n-1) list[i]->next = NULL;
		list[i]->next = list[i+1];
	}
	
}

int main(){
	int n;
	cout << "初始化链表节点个数：\n";
	cin >> n;
	InitListNode(n);

	return 0;
}
