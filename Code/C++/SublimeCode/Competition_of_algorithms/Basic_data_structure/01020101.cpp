//洛谷P1540 STL queue
//机器翻译
//共 22 行。每行中两个数之间用一个空格隔开。
//第一行为两个正整数 M,NM,N，代表内存容量和文章的长度。
//第二行为 NN 个非负整数，按照文章的顺序，每个数（大小不超过 1000）代表一个英文单词。
//文章中两个单词是同一个单词，当且仅当它们对应的非负整数相同。
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int Hash[1003] = {0};   //哈希检查内存中是否有单词
queue<int> mem;         //队列模拟内存
int main(){
	int m, n;
	cin >> m >> n;
	int cnt = 0;   //计数器 为查字典的次数
	while(n--){
		int word;  //代表英文字母
		cin >> word;
		if(!Hash[word]){
			cnt++;
			mem.push(word);
			Hash[word] = 1;
			while(int(mem.size()) > m){ //内存已满
				Hash[mem.front()] = 0;
				mem.pop();
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
