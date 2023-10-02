#include <iostream>
using namespace std;

#define MaxSize 10
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;
//初始化栈
void Initstack(SqStack &S){
	S.top = -1;
}
//判断栈空
bool StackEmpty(SqStack &S){
	return S.top == -1;
}
//新元素入栈
bool Push(SqStack &S, ElemType x){
	if(S.top == MaxSize-1) return false;
	//S.top += 1;
	S.data[++S.top] = x;
	return true;
}
//出栈操作
int Pop(SqStack &S, ElemType &x){
	if(S.top == -1) return 0;
	x = S.data[S.top--];
	return x;
}
//读栈顶元素
bool GetTop(SqStack &S, ElemType &x){
	if(S.top == -1) return false;
	x = S.data[S.top];
	return true;
}
//创建栈
void CreateStack(SqStack &S){
	for(int i = 0; i < MaxSize;i++){
		Push(S,i);	
		//S.data[++S.top] = i;
	}
	for(int j = 0; j < MaxSize;j++){
		cout << S.data[j] << " ";
	}
	cout << "\n";
	
	return;
}


void testStack(){
	SqStack S;
	int x;
	Initstack(S);
	CreateStack(S);
	//GetTop(S, x);
	for(int i = 0; i < MaxSize;i++){
		Pop(S, x);
		cout << x << " ";
	}
	cout << '\n';
	return;
}

int main(){
	// int n;
	// cin >> n;
	testStack();
	return 0;
}
