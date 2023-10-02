//Max Sum hdu 1003
//给定序列，求最大子序列和
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int main(){
	int t; cin >> t;       //测试用例个数
	int a[25], b[25], c[25];
	for(int k = 1; k <= t;k++){
		int n; cin >> n;
		int maxsum = -INF;  //最大子序和，初始化一个极小负数
		int start = 1, end = 1, p = 1; //起点，终点，扫描位置
		int sum = 0;
		for(int i = 1; i <= n; i++){
			int a;
			cin >> a; sum += a;
			if(sum > maxsum) {
				maxsum = sum; start = p; end = i;
			}
			if(sum < 0){//抛弃负数，重新开始
				sum = 0;
				p = i+1;
			}
		}
		a[k] = maxsum; b[k] = start; c[k] = end;
	}
	for(int k =1; k <= t;k++){
		cout << "Case " << k << "：\n" << a[k] << " "
		     << b[k] << " " << c[k] << "\n";
		if(k!=t) cout << endl;
	}
	return 0;
}