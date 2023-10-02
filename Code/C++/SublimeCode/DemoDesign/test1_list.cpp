#include<iostream>
#include <list>
#include<ctime>
#include<algorithm>

using namespace std;

void DisplayList(list<int> &l){
    list<int>::iterator ite;//迭代器
	for (ite = l.begin();ite != l.end();ite++)
        cout << *ite << '\t';
    cout << endl;
} 

int main(){
    list<int>::iterator ite;
    list<int> list;
    srand((unsigned)time(NULL));//创建随机数种子
    cout << "list容器随机插入：" << endl;
    for (int i = 0; i < 10; ++i)
    {
    	list.push_back(rand() % 100);
    }
    cout << "size:" << list.size() << endl;
    cout << "elements:" << endl;
    DisplayList(list);
    
    //插入随机数
    int num_insert = rand() % 100;
    cout << "List容器头部插入随机数：" << num_insert << endl;
    list.push_front(num_insert);
    cout << "插入后List中元素为：" << endl;
    DisplayList(list);

    //查找随机数
    int num_seek = rand() % 100;
    cout << "List容器中查找随机数：" << num_seek << endl;
    ite = find(list.begin(),list.end(),num_seek);
    if(ite != list.end())
        cout << "List容器中存在：" << num_seek << endl;
    else{
        cout << "List容器中不存在：" << num_seek << ",将其插入尾部。" << endl;
        list.push_back(num_seek);
    }

    //排序
    list.sort();
    cout << "泛型算法sort函数排序后元素为：" << endl;
    DisplayList(list);

    //删除尾部元素
    cout << "执行删除List尾部元素：" << endl;
    list.pop_back();
    cout << "删除后List中元素为：" << endl;
    DisplayList(list);

    //清空list
     //清空vector
    cout << "执行清空List。" << endl;
    list.clear();
    cout << "清空成功！" << endl;
    DisplayList(list);

	return 0;
}