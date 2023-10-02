#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <random>
using namespace std;
/*初始化数组*/
int *arr = new int[5];
int *nums = new int[5] {1,3,2,5,4};

/*随机返回数组元素*/
int randomAccess(int* nums, int size){
	srand((unsigned)time(NULL));  
	//区间[0,size)中随机抽取数字
	int randomIndex = rand() % size;
	//获取并返回随机元素
	int randomNum = nums[randomIndex];
	return randomNum;
}

/*扩展数组长度*/
int *extend(int* nums, int size, int enlarge){
	//初始一个扩展长度后的数组
	int *res = new int[size + enlarge];
	//原数组内容复制
	for(int i = 0; i < size; i++)
		res[i] = nums[i];
	//释放内存
	delete[] nums;
	return res;
}

/* 在数组的索引 index 处插入元素 num */
void insert(int* nums, int size, int num, int index) {
	// 把索引 index 以及之后的所有元素向后移动一位
	for (int i = size - 1; i > index; i--) {
		nums[i] = nums[i - 1];
	}
	// 将 num 赋给 index 处元素
	nums[index] = num;
}

/* 删除索引 index 处元素 */
void remove(int* nums, int size, int index) {
	// 把索引 index 之后的所有元素向前移动一位
	for (int i = index; i < size - 1; i++) {
		nums[i] = nums[i + 1];
	}
}

/* 遍历数组 */
void traverse(int* nums, int size) {
	int count = 0;
	// 通过索引遍历数组
	for (int i = 0; i < size; i++) {
		count++;
	}
}  

/* 在数组中查找指定元素 */
int find(int* nums, int size, int target) {
	for (int i = 0; i < size; i++) {
		if (nums[i] == target)
			return i;
	}
	return -1;
}


int main(){
	//cout << arr << '\n' <<  nums;
	cout << randomAccess(nums, 5);
	return 0;
}

