//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int N = 60;

int main()
{
	int n;
	cin >> n;
	string s[N], SS[N];
	for (int i = 0; i < n; ++i){
		cin >> s[i];
		SS[i] = s[i] + s[i];
	}
	//int len = s[0].length();//字符串长度相等
	int ans = 0x1fffffff, k, temp;//设置ans较大的初始值
	for (int i = 0; i < n; ++i){
		temp = 0;
		for (int j = 0; j < n; ++j){
			if(j == i) continue;
			k = SS[j].find(s[i]);
			if(k == -1){
				cout << "-1" << endl;
				return 0;
			}
			cout << k << endl;
			temp += k;
		}
		ans = min(ans, temp);
	}
	cout << ans << endl;
	return 0;
}