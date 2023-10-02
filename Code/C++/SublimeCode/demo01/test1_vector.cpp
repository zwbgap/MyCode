#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

/*(1) 练习 vector 和 list 的使用。
   定义一个空的 vector，元素类型为 int，生成 10 个随机数插入到 
   vector 中，用迭代器遍历 vector 并输出其中的元素值。在 vector 
   头部插入一个随机数，用迭代器遍历 vector并输出其中的元素值。用
   泛型算法 find 查找某个随机数，如果找到便输出，否则将此数插入 
   vector 尾部。用泛型算法 sort 将 vector 排序，用迭代器遍历 vector 
   并输出其中的元素值。删除 vector 尾部的元素，用迭代器遍历 vector 
   并输出其中的元素值。将 vector 清空*/

void DisplayVector(vector<int> &vec){
	vector<int>::iterator it;//迭代器
	//vector<int> vec;
	for (it = vec.begin(); it != vec.end(); it++)
    	cout << *it << "\t";//迭代器输出
    cout << endl;
}

int main(){
	vector<int>::iterator it;//迭代器
	vector<int> vec;
	srand((unsigned)time(NULL));//创建时间种子
    for (int i = 0; i < 10; ++i)
    {
    	vec.push_back(rand() % 100);
    }
    cout << "size:" << vec.size() << endl;
    cout << "elements：" << endl;
    DisplayVector(vec);

    //头部插入随机数
    cout << "在vector头部插入一个随机数：";
    int num_insert = rand() % 100;
    cout << num_insert << endl;
    it = vec.begin();
    vec.insert(it,num_insert);
    cout << "插入后vector中的元素为：" << endl;
    DisplayVector(vec);

    //查找
    int num_seek = rand() % 100;
    cout << "查找随机数：" << num_seek << endl;
    it = find(vec.begin(),vec.end(),num_seek);
    if(it != vec.end())
    	cout << "已查找到:" << num_seek <<  endl;
    else{
    	cout << "未查找到:" << num_seek << ",将其插入vector尾部。" << endl;
    	vec.push_back(num_seek); //元素插入到尾部
    }
    DisplayVector(vec);

    //进行排序
    sort(vec.begin(),vec.end());
    cout << "泛型算法sort排序：" << endl;
    DisplayVector(vec);

    //删除排序后vector尾部的元素
    it = vec.end() - 1;
    cout << "执行删除vector尾部元素：" << *it << endl;
    vec.pop_back();
    cout << "删除后vector中元素为：" << endl;
    DisplayVector(vec);

    //清空vector
    cout << "执行清空vector。" << endl;
    vec.clear();
    cout << "清空成功！" << endl;
    //DisplayVector(vec);
	return 0;
}