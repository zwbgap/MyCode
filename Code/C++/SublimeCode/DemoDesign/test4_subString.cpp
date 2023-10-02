#include<iostream>
#include<cstring>
#define MAXLEN 100

using namespace std;

void LCS(char* x, char* y, int m, int n, int c[][MAXLEN], int b[][MAXLEN]){
	int i, j;
	for (int i = 0; i <= m; ++i)
		c[i][0] = 0;
	for (int j = 1; j <= n; ++j)
		c[0][j] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
	 	{
	 		if(x[i-1] == y[j-1]){
	 			c[i][j] = c[i-1][j-1] + 1;
	 			b[i][j] = 0;
	 		}
	 		else if(c[i-1][j] >= c[i][j-1]){
	 			c[i][j] = c[i-1][j];
	 			b[i][j] = 1;
	 		}
	 		else{
	 			c[i][j] = c[i][j-1];
	 			b[i][j] = -1;
	 		}
	 	}
	}
}

void Print(int b[][MAXLEN],char *x, int i, int j){
	if(i == 0 || j == 0)
		return;
	if(b[i][j] == 0){
		Print(b,x,i-1,j-1);
		cout << x[i-1];
	}
	else if(b[i][j] == 1)
		Print(b,x,i-1,j);
	else
		Print(b,x,i,j-1);	
}

int main(){
	char x[MAXLEN];
	char y[MAXLEN];
	int b[MAXLEN][MAXLEN];
	int c[MAXLEN][MAXLEN];
	int m, n;
	cout << "请输入第一个字符串：" << endl;
	cin >> x;
	cout << "请输入第二个字符串：" << endl;
	cin >> y;
	m = strlen(x);
	n = strlen(y);
	LCS(x, y, m, n, c, b);
	cout << "两个字符串的最大公共子序列是：" ;
	Print(b, x, m, n);
	return 0;
}