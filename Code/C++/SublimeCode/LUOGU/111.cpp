#include <iostream>
#include <string>

using namespace std;

void check(){
    bool a[10];
    for (int i = 0; i < 10; i++) 
        cout << a[i] << " ";
    cout << '\n';
}

void perm(string list, int a, int b)   //a��ʾ�ڼ������� b��ʾ����
{
    if (a == b) {                     //a==b��ʱ�򣬾��Ѿ���������
        cout << list << "   ";
    } else {
        for (int i = a; i < b; i++) {
            swap(list[i], list[a]);
            perm(list, a + 1, b);
            swap(list[i], list[a]);
        }
    }
}

int main() {
   // string a;
   // cout<< "��������Ҫȫ���е���:";
   // getline(cin,a);
   // perm(a, 0, a.length());
   // return 0;
   
   //check();
//   bool a = 0, b = 3;
//   
//   cout << (a ^ b);
   int a = 9;
   double b = 8.0;
   double c = a+b;
   cout << a + b;
   cout << c;
   cout << sizeof(c);
}
