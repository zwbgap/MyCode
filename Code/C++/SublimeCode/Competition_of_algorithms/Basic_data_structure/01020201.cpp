//洛谷P1540 手写循环队列
#include <bits/stdc++.h>
#define N 1003  //队列大小
#define endl "\n"
using namespace std;  
int Hash[1003] = {0};  //哈希表检查内存中单词
struct myqueue{
	int data[N];  //分配静态空间
	/*
	int *data;  //动态分配 */
	int head, rear;  //队头队尾
	bool init(){     //初始化
		/*动态分配：
		Q.data = (int *)malloc(N * sizeof(int));
		if(!Q.data) return false;*/
		head = rear = 0;
		return true;
	}
	int size(){return (rear - head + N) % N;} //返回队列长度
	bool empty(){return size()==0;}           //判断队列是否为空
	bool push(int e){
		if((rear +1) % N == head) return false; //队列满
		data[rear] = e;
		rear = (rear + 1) % N; //rear指向下一个空的位置
		return true;
	}
	bool pop(int &e){  //弹出，即删除队头元素 并返回
		if(head == rear) return false; //队列空
		e = data[head];
		head = (head + 1) % N;
		return true;
	}
	int front(){return data[head];}
}Q;
int main(){
	Q.init();
	int m, n;
	cin >> m >> n;
	int cnt = 0;
	while(n--){
		int word;
		cin >> word;
		if(!Hash[word]){
			cnt++;
			Q.push(word);
			Hash[word] = 1;
			while(Q.size() > m){
				int tmp;
				Q.pop(tmp);
				Hash[tmp] = 0;
			}
			
		}
	}
	cout << cnt << endl;
	return 0;
}
