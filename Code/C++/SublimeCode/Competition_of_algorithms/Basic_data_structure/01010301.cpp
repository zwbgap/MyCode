//P1996  STL list
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	list<int> node;
	for(int i = 1; i <= n; i++){
		node.push_back(i);//建立链表
	};
	list<int>::iterator it = node.begin();
	while(node.size() > 1){
		for(int i = 1; i < m; i++){
			it++;
			if(it == node.end()) it = node.begin();
		}
		cout << *it << " ";
		list<int>::iterator next = ++it;
		if(next == node.end()) next = node.begin();
		node.erase(--it);  //删除节点，size自动减1
		it = next;
	}
	cout << *it << endl;
	return 0;
}
