#include <iostream>
#include <math.h>
#include <tchar.h>//UNICODE����-wide-character,����˫�ֽ��ַ���
using namespace std;
#define n 8//�ʺ�ĸ���
int a[n] = { 0 };
int total = 0;
//�жϴ����Ƿ�����������
bool is_play(int row) {
    for (int i = 0; i < row; i++)
        if ((abs(i - row) == abs(a[i] - a[row])) || (a[i] == a[row]))//�ڶԽ��߻���ͬһ��
            return false;
    return true;
}
void print() {//��ӡ���ֽ�����÷�ʽ
    cout << "��" << total << "�ַ���,��λ��Ϊ:";
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
    cout << "\t������\t   " ;
    for (int i = 0; i < n; i++)
        cout << i<<" ";
    cout << endl;
    eightQueen(0);
    return 0;
}

