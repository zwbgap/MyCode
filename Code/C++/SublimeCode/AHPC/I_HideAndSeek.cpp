#include <bits/stdc++.h>
using namespace std;
#define N 2010
#define ll long long

int n, room[N];
struct node{
	int x, y;
	ll val;
} a[N*N];

//标记是否连通
int find(int x){
	if(room[x] == x) return x;
	return room[x] = find(room[x]);
}

//排序规则
bool cmp(node a, node b){
	return a.val < b.val;//权值从小到大排序
}

int main(){
	int num = 0, val;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			a[++num].x = i-1;
			a[num].y = j;
			cin >> val;
			a[num].val = val;
		}
	}
	for (int i = 0; i <= n; i++)
		room[i] = i;
	sort(a + 1, a + num + 1, cmp);//权重排序：由小到大
	cout << "顶点" << "顶点" << "权重" << endl;
	for (int i = 1; i <= num; i++)
		cout << a[i].x << "  " << a[i].y << "  " << a[i].val << endl;

	int sum = 0;//计数
	ll ans = 0;
	for (int i = 1; i <= num; i++){
		int u = find(a[i].x), v = find(a[i].y);
		if(u != v){
			cout << "i = " << i << ", x = " << a[i].x 
			     << ", y = " << a[i].y << ", u = " << u 
			     << ", v = " << v <<  ", val = " << a[i].val << endl;
			if(v > u) room[v] = u;
			else room[u] = v;
			sum ++;
			ans += a[i].val;
			if(sum == n) break;
		}
	}
	cout << "所需最少纪念币： ";
	cout << ans << endl;
	return 0;
}