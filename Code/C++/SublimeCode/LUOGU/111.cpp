#include <iostream>
#include <string>

using namespace std;

void check(){
    bool a[10];
    for (int i = 0; i < 10; i++) 
        cout << a[i] << " ";
    cout << '\n';
}

void perm(string list, int a, int b)   //a表示第几个数， b表示长度
{
    if (a == b) {                     //a==b的时候，就已经交换完了
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
   // cout<< "请输入需要全排列的数:";
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
