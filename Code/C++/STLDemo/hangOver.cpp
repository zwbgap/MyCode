#include<iostream>
using namespace std;

//纸牌放置最远距离所需数量
//1/2+1/3+1/4....1/(n+1)=c
int main(){
	float c;
	while(cin >>c && c){
		float i = 0,s = 0;
		//cin >> c;
		while(s < c){
			s += 1.00/(i+2);
			i++;
		}
		cout << "cards:" << i << endl;
		
	}
	return 0;
}
