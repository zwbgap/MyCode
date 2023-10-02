#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int k, m, n, t;
	int i = 0, j = 0;
	cin >> k >> m >> n;
	t = m;
	ll a[m], b[m], cnt[m] = {0};
	bool flag = true;
	while(m--){
		cin >> a[i++] >> b[j++];		
		if(k < a[i-1]) cnt[i-1] = -1;
		else{  
			if(n/b[j-1]*a[i-1]<=k) {
				cnt[i-1] = i;
			}
		}
	}
	for(int c= 0;c<t;c++){
		if(cnt[c]>0) cout << cnt[c] << ' ';
		//if(cnt[c]<0)
	}
	
	return 0;
}
