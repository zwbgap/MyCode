#include <iostream>
#include <math.h>
#include <tchar.h>//UNICODE工程-wide-character,用于双字节字符串
using namespace std;
#define n 8//皇后的个数
int a[n] = { 0 };
int total = 0;
//判断此列是否能满足条件
bool is_play(int row) {
    for (int i = 0; i < row; i++)
        if ((abs(i - row) == abs(a[i] - a[row])) || (a[i] == a[row]))//在对角线或者同一列
            return false;
    return true;
}
void print() {//打印各种解决放置方式
    cout << "第" << total << "种方法,列位置为:";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void eightQueen(int queenCount) {
    if (queenCount == n) {
        total++;
        print();
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            a[queenCount] = i;
            if (is_play(queenCount))
                eightQueen(queenCount + 1);
        }
    }
}
int main()
{   
    cout << "\t行数：\t   " ;
    for (int i = 0; i < n; i++)
        cout << i<<" ";
    cout << endl;
    eightQueen(0);
    return 0;
}

