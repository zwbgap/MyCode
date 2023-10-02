#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;
#define InitSize 30
#define ElemType int

typedef struct{
	ElemType data[InitSize];
	int length; 
	int MaxSize;
}SqlList;

//初始化数组
bool InitArray(SqlList &L, int n){
	//SqlList *L = new SqlList;
	L.MaxSize = 30;
    L.length = 0;
	for(int i = 0;i < n;i++){
		L.data[i] = rand() % 100;
		L.length++;
		cout << L.data[i] << "  ";
	}
	cout << "\n";
	return true;
} 
//输出数组
bool ListOutput(SqlList &L){
	for(int i = 0;i < L.length;i++){
		cout << L.data[i] << "  ";
	}
	cout << "\n";
	return true;
}

//插入操作
bool ListInsert(SqlList &L,int i,ElemType e){
	if(i < 1 || i > L.length-1) 
		return false;
	if(L.length > L.MaxSize)
		return false;
	for(int j = L.length;j>=i;j--){
		L.data[j] = L.data[j-1];
	}
	L.data[i] = e;
	L.length++;
	return true;
}

//删除操作
bool ListDelete(SqlList &L, int i, ElemType &e){
	if(i < 1 || i > L.length-1)
		return false;
	e = L.data[i-1];
	for(int j = i;j <L.length;j++){
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}
//按值查找---顺序查找
//查找第一个值等于e的元素并返回其次序
int LocateElem(SqlList L,ElemType e){
	for(int i = 0;i < L.length;i++)
		if(L.data[i] == e)
			return i+1;
	return 0;
	
}

//删除最小值，并用最后的元素补充
bool Del_Min(SqlList &L, ElemType &val){
	//删除顺序表L中最小值元素节点，并通过引用型参数返回其值
	if(L.length == 0) 
		return false;
	val = L.data[0];
	int pos = 0;    //假定0号元素值最小
	for(int i = 1;i < L.length;i++){
		if(L.data[i] < val){
			val = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length-1];
	L.length--;
	return true;
 }
//逆置
void ListReverse(SqlList &L){
	ElemType temp;
	for(int i = 0; i < L.length/2;i++){
		temp = L.data[i];
		L.data[i] = L.data[L.length-1-i];
		L.data[L.length-1-i] = temp;
	}
	return;
}
//删除线性表中所有值为x的数据元素
void DelElemType(SqlList &L,ElemType x){
	//用k记录L中不等于x的元素的个数，扫描时将不等于x的值
	//移动到下标为k的位置，并更新k值
//	int k = 0, i;
//	for(i = 0;i < L.length;i++){
//		if(L.data[i] != x){
//			L.data[k] = L.data[i];
//			k++;
//		}
//	}
//	L.length = k;
	
	//算法2: k记录等于x的元素个数，
	//并将不等于x的元素前移k个位置
	int k = 0, i = 0;
	while(i < L.length){
		if(L.data[i] == x)
			k++;
		else
			L.data[i-k] = L.data[i];
		i++;
	}
	L.length -= k;
}
//顺序表排序
void ListSort(SqlList &L){
	int MinNum, pos = 0;
	for(int i = 0; i < L.length;i++){
		MinNum = L.data[i];
		for(int j = i+1; j < L.length;j++){
			if(MinNum > L.data[j]){
				MinNum = L.data[j];
				pos = j;
			}
		}
		int tmp = L.data[i];
		L.data[i] = MinNum;
		L.data[pos] = tmp;
	}
}
//删除有序顺序表中一段元素
bool Del_S_t(SqlList &L, ElemType S, ElemType T){
	//删除有序顺序表中S到T范围之间得值
	int i = 0, j = 0;
	if(S >= T || L.length == 0)
		return false;
	for(i = 0; i < L.length && L.data[i]<S;i++);
	if(i >= L.length)
		return false;
	for(j = i; j < L.length && L.data[j] < T;j++);
	for(;j < L.length;i++,j++){
		L.data[i] = L.data[j];
	}
	L.length = i;
	return true;
}

//删除顺序表中S到T之间的元素，非有序顺序表
bool Del_S_T2(SqlList &L, ElemType S, ElemType T){
	int i, k = 0;
	if(S >= T || L.length == 0)
		return  false;
	for(i = 0; i <L.length;i++){
		if(L.data[i] >= S && L.data[i] <= T)
			k++;
		else
			L.data[i-k] = L.data[i];
	}
	L.length -= k;
	return true;
}

//有序顺序表中删除重复的元素
bool Del_Same(SqlList &L){
	if(L.length == 0)
		return false;
	int i, j;
	for(i = 0,j = 1;j < L.length;j++){
		if(L.data[i] != L.data[j])
			L.data[++i] = L.data[j];
	}
	L.length = i+1;
	return true;
}

//合并两个有序顺序表
bool MergeList(SqlList A, SqlList B, SqlList &C){
	if(A.length + B.length > C.MaxSize)
		return false;
	int i = 0, j = 0, k = 0;
	while(i < A.length && j < B.length){
		if(A.data[i] < B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while(i < A.length)
		C.data[k++] = A.data[i++];
	while(j < B.length)
		C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}

//最小时间查找值为x的元素，若找到与后继元素互换。若未找到，则插入保持有序
void SearchExchangeInsert(SqlList &L, ElemType e){
	int low = 0, high = L.length-1, mid;
	while(low < high){
		mid = (low + high) / 2;
		if(L.data[mid] == e) break;
		else if(L.data[mid] < e) low = mid + 1;
		else high = mid - 1;
	}
	if(L.data[mid] == e && mid != L.length-1){
		int temp = L.data[mid];
		L.data[mid] = L.data[mid+1];
		L.data[mid+1] = temp;
	}
	int i;
	if(low > high){
		for(i = L.length-1; i > high;i--)
			L.data[i+1] = L.data[i];
	}
	L.data[i+1] = e;
	L.length++;
}

//顺序表分为两部分并交换顺序
//算法思想：将两部分分别逆置，再将整体进行逆置

//有范围逆置
void Reverse(SqlList &L, int from, int to){
	int i, temp;
	for(i = 0; i < (to-from+1)/2;i++){
		temp = L.data[from+i];
		L.data[from+i] = L.data[to-i];
		L.data[to-i] = temp;
	}
}
void Converse(SqlList &L,int n, int p){
	Reverse(L,0,p-1);
	Reverse(L,p,n-1);
	Reverse(L,0,n-1);
}
int main(){
	cout << "数组初始化:\n";
	SqlList L;
	InitArray(L,15);
	cout << L.length << "\n";
	if(ListInsert(L,9,588)) ListOutput(L);
	ElemType val;
	if(Del_Min(L,val)) ListOutput(L);
	cout << val << "\n";
	ListReverse(L);
	ListOutput(L); 
	DelElemType(L,5);
	ListOutput(L);
	
//	ListSort(L);
//	ListOutput(L);
	
	//Del_S_t(L,40,50);
	Del_S_T2(L,40,50);
	ListOutput(L);
	
	
	SqlList L1;
	InitArray(L1,6);
	ListSort(L1);
	SqlList L2;
	InitArray(L2,8);
	ListSort(L2);
	
	MergeList(L1,L2,L);
	ListOutput(L);
	
	SearchExchangeInsert(L,21);
	ListOutput(L);
	cout << "--------\n";

	Converse(L,15,10);
	ListOutput(L);
	return 0;
}
