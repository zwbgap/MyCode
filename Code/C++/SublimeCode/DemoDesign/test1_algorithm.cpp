#include<iostream> 
#include<vector> 
#include<algorithm> 
#include<ctime> 
using namespace std; 
vector<int> a; 
int main() 
{ 
	vector<int>::iterator it; 
	srand((unsigned)time(NULL)); //����ʱ��������� 
	for (int i = 0; i < 10; i++) 
	{ 
		a.push_back(rand() % 100); 
	} 
	cout << "���������10����Ϊ��"; 
	for (it = a.begin(); it != a.end(); it++) 
	{ 
		cout << *it << " "; 
	} 
	sort(a.begin(), a.end());//�������� 
	cout << endl << "ʹ��sort��������"; 
	for (it = a.begin(); it != a.end(); it++) 
	{ 
		cout << *it << " "; 
	} 
	sort(a.begin(), a.end(), greater<int>());//���� 
	cout << endl << "ʹ��sort��������"; 
	for (it = a.begin(); it != a.end(); it++) 
	{ 
		cout << *it << " "; 
	} 
	int num_seek = rand() % 100; 
	//�ж��Ƿ�������ֵ 
	it = find(a.begin(), a.end(), num_seek); 
	cout << endl<< "���������:" << num_seek; 
	if (it!=a.end())  
		cout << ",�ҵ��������" << num_seek; 
	else 
		cout << ",�����в����ڸ������" << endl; 
	cout << "��������СֵΪ��" << *min_element(a.begin(), a.end());  
	cout << "���������ֵΪ��" << *max_element(a.begin(), a.end()); 
	cout << endl; 
	return 0; 
}

