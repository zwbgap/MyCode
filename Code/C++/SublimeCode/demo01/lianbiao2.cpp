#include <iostream>
using namespace std;

#define ElementType int 
typedef struct DNode{
	ElementType data;
	struct DNode *prior, *next;
}DNode, *DLinklist;

//Init DLinklist
bool InitDLinkList(DLinklist &L){
	L = (DNode *)malloc(sizeof(DNode));
	if(L == NULL) return false;
	L->prior = L;
	L->next = L;
	return true;
}

//IsEmpty
bool isEmpty(DLinklist &L){
	return L->next == L;
}

//isTail
bool isTail(DLinklist &L, DNode *p){
	return p->next == L;
}
void testDLinkList(){
	DLinklist L;
	InitDLinkList(L);
}

int main(){
	//DLinklist L;
	testDLinkList();
}
