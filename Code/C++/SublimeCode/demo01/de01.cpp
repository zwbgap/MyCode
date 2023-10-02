#include <bits/stdc++.h> 
using namespace std;
int aa[3000],bb[3000],tota,totb; 
int main()
{
	string a,b; 
	cin>>a>>b;
	int maxn=0,minn=2000; 
	for(int i=0;i<=2359;i++) 
	{
		if((a[0]=='?'||(int)(a[0]-'0')==i/1000)&&(a[1]=='?'||(int)(a[1]-
		'0')==i/100%10)&&(a[3]=='?'||(int)(a[3]-'0')==i/10%10)&&(a[4]=='?'||(int) 
		(a[4]-'0')==i%10))
			aa[++tota]=i;
		if((b[0]=='?'||(int)(b[0]-'0')==i/1000)&&(b[1]=='?'||(int)(b[1]-
		'0')==i/100%10)&&(b[3]=='?'||(int)(b[3]-'0')==i/10%10)&&(b[4]=='?'||(int) 
		(b[4]-'0')==i%10))
			bb[++totb]=i; 
	}
	for(int i=1;i<=tota;i++) 
		for(int j=1;j<=totb;j++) 
		{
			if(bb[j]>aa[i]) 
			{
				int res=bb[j]/100*60+bb[j]%100-aa[i]/100*60-aa[i]%100; 
				maxn=max(maxn,res);
				minn=min(minn,res); 
			}
		}
	cout<<minn<<' '<<maxn; 
	return 0;
}
