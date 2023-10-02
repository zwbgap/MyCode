#include<iostream>
#include <list>
#include<ctime>
#include<algorithm>

using namespace std;

void DisplayList(list<int> &l){
    list<int>::iterator ite;//������
	for (ite = l.begin();ite != l.end();ite++)
        cout << *ite << '\t';
    cout << endl;
} 

int main(){
    list<int>::iterator ite;
    list<int> list;
    srand((unsigned)time(NULL));//�������������
    cout << "list����������룺" << endl;
    for (int i = 0; i < 10; ++i)
    {
    	list.push_back(rand() % 100);
    }
    cout << "size:" << list.size() << endl;
    cout << "elements:" << endl;
    DisplayList(list);
    
    //���������
    int num_insert = rand() % 100;
    cout << "List����ͷ�������������" << num_insert << endl;
    list.push_front(num_insert);
    cout << "�����List��Ԫ��Ϊ��" << endl;
    DisplayList(list);

    //���������
    int num_seek = rand() % 100;
    cout << "List�����в����������" << num_seek << endl;
    ite = find(list.begin(),list.end(),num_seek);
    if(ite != list.end())
        cout << "List�����д��ڣ�" << num_seek << endl;
    else{
        cout << "List�����в����ڣ�" << num_seek << ",�������β����" << endl;
        list.push_back(num_seek);
    }

    //����
    list.sort();
    cout << "�����㷨sort���������Ԫ��Ϊ��" << endl;
    DisplayList(list);

    //ɾ��β��Ԫ��
    cout << "ִ��ɾ��Listβ��Ԫ�أ�" << endl;
    list.pop_back();
    cout << "ɾ����List��Ԫ��Ϊ��" << endl;
    DisplayList(list);

    //���list
     //���vector
    cout << "ִ�����List��" << endl;
    list.clear();
    cout << "��ճɹ���" << endl;
    DisplayList(list);

	return 0;
}