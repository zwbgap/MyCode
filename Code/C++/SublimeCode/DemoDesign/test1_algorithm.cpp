#include<iostream> 
#include<vector> 
#include<algorithm> 
#include<ctime> 
using namespace std; 
vector<int> a; 
int main() 
{ 
	vector<int>::iterator it; 
	srand((unsigned)time(NULL)); //创建时间随机种子 
	for (int i = 0; i < 10; i++) 
	{ 
		a.push_back(rand() % 100); 
	} 
	cout << "已随机插入10个数为："; 
	for (it = a.begin(); it != a.end(); it++) 
	{ 
		cout << *it << " "; 
	} 
	sort(a.begin(), a.end());//升序排序； 
	cout << endl << "使用sort升序排序："; 
	for (it = a.begin(); it != a.end(); it++) 
	{ 
		cout << *it << " "; 
	} 
	sort(a.begin(), a.end(), greater<int>());//降序 
	cout << endl << "使用sort降序排序："; 
	for (it = a.begin(); it != a.end(); it++) 
	{ 
		cout << *it << " "; 
	} 
	int num_seek = rand() % 100; 
	//判断是否存在随机值 
	it = find(a.begin(), a.end(), num_seek); 
	cout << endl<< "查找随机数:" << num_seek; 
	if (it!=a.end())  
		cout << ",找到该随机数" << num_seek; 
	else 
		cout << ",容器中不存在该随机数" << endl; 
	cout << "容器中最小值为；" << *min_element(a.begin(), a.end());  
	cout << "容器中最大值为；" << *max_element(a.begin(), a.end()); 
	cout << endl; 
	return 0; 
}

