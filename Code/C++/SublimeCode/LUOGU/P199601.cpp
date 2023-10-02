#include <bits/stdc++.h>
using namespace std;
//约瑟夫环动态列表
struct node{
	int data;
	node * next;
};
int main(){
	int n, m;
	cin >> n >> m;
	node *head, *p, *now, *prev;
	head = new node; head->data = 1;head->next = NULL;
	now = head; 
	for(int i = 2; i <= n;i++){
		p = new node; p->data = i; p->next = NULL;
		now->next = p;
		now = p;
	}
	now->next = head;

	now = head; prev = head;
	while((n--)>1){
		for(int i = 1; i < m; i++){
			prev = now;
			now = now->next;
		}
		cout << now->data << "\n";
		prev->next = now->next;
		delete now;
		now = prev->next;
	}
	cout << now->data << '\n';
	delete now;
	return 0;
	

}