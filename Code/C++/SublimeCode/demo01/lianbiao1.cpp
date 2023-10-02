#include <iostream>
using namespace std;
#define ElementType int

typedef struct LNode{
	ElementType data;
	struct LNode *next;
}LNode, *Linklist;
//Init LinkList
bool InitLinklist(Linklist &L){
	L = (LNode*)malloc(sizeof(LNode));
	if(L== NULL) return false;
	L->next = NULL;
	return true;
}
//judge empty
bool Empty(Linklist &L){
	return L->next == NULL;
}
//Insert
bool InsertLNode(Linklist &L, int i, ElementType e){
	if(i < 1) return false;
	LNode *p;
	int j = 0;
	p = L;
	while(p != NULL && j <i-1){
		p = p->next;
		j++;
	}
	if(p == NULL) return false;
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = L->next;
	L->next = s;
	return true;
}
//Insert Next to bulid List
bool InsertNextLNode(LNode *p, ElementType e){
	if(p == NULL) return false;
	LNode *s = (LNode*)malloc(sizeof(LNode));
	if(s == NULL) return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//build_tail
Linklist List_TailInsert(Linklist &L){
	int x;
	L = (Linklist)malloc(sizeof(LNode));
	LNode *s, *r= L;
	cin >> x;
	while(x != -1){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
}
//build_Head
Linklist list_HeadInsert(Linklist &L){
	LNode *s;
	int x;
	L = (Linklist)malloc(sizeof(LNode));
	L->next = NULL;
	cin >> x;
	while(x != -1){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

typedef struct DNode{
	ElementType date;
	struct DNode *prior, *next;
}DNode,*DLinklist;

bool InitDLinkList(DLinklist &L){
	L = (DNode*)malloc(sizeof(DNode));
	if(L == NULL) return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}

bool Empty(DLinklist &L){
	return L->next == NULL;
}
//Insert
bool InsertNextDNode(DNode *p, DNode *s){
	//p insert s
	if(p == NULL || s == NULL) return false;
	s->next = p->next;
	if(p->next != NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool DeleteNextDNode(DNode *p){
	//delete p later
	if(p == NULL) return false;
	DNode *q = p->next;
	if(p == NULL) return false;
	p->next = q->next;
	if(q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}

void DestoryDLinklist(DLinklist &L){
	while(L->next != NULL)
		DeleteNextDNode(L);
	free(L);
	L = NULL;
}


void testDLinklist(){
	DLinklist L;
	//³õÊ¼»¯Ë«Á´±í
	InitDLinkList(L);
}

int main(){
	testDLinklist();
	return 0;
}
