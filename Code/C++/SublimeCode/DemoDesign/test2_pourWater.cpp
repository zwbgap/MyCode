#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//输出结果
void outPut(vector<int> a_vec,vector<int> b_vec,int L){
	vector<int>::iterator ita, itb, it;
	for (it = b_vec.begin();it <b_vec.end();it++)
	{
		if(*it == L)
			break;
	}
	cout << "A" << "'\t" << "B" << endl;
    //判断it左右部分长度
    if(b_vec.end() - it - 1 > it - b_vec.begin() + 1){
    	ita = a_vec.begin();
    	itb = b_vec.begin();
    	while(itb <= it){
    		cout << *ita << "'\t" << *itb << endl;
    		ita++; itb++;
    	}
    }
    else{
    	for (it = b_vec.end() -1;it > b_vec.begin();it--)
    	{
    		if(*it == L)
    			break;
    	}
    	ita = a_vec.end() - 1;
    	itb = b_vec.end() - 1;
    	while(itb > it){
    		cout << *ita << "'\t" << *itb << endl;
    		ita--; itb--;
    	}
    }
    cout << "B中装了" << L << "升水！" << endl;
}

void Bucket_problem(){
	int A, B, L;
	vector<int> A1, B1;
	//int flag = 0;
	cout << "分别输入容器A(小)和容器B(大)的容积：" << endl;
	cin >> A >> B;
	cout << "输入待装水的体积：" << endl;
	cin >> L;
	int M = max(A, B);
	int m = min(A, B);
	if(L > M){
		cout << "No Solution" << endl;
		return;
	}
	if(L == m){
		cout << "A" << "\t" << "B" << endl;
		cout << m << "\t" << "0" << endl;
		cout << "此时A中装了" << m << "升水" << endl;
		return;  
	}
	if(L == M){
		cout << "A" << "\t" << "B" << endl;
		cout << "0" << "\t" << M << endl;
		cout << "此时B中装了" << M << "升水" << endl;
		return;   
	}
	int a = 0, b = 0;
	a = m;
	while(true){
		if(b == M){
			b = 0;
			if(a == 0 && b == 0) break;
			A1.push_back(a);
			B1.push_back(b);
			swap(a,b);
			A1.push_back(a);
			B1.push_back(b);
			a = m;
			continue;
		}
		A1.push_back(a);
	    B1.push_back(b);
	    b += a;
	    if(b >= M){
	    	a = b -M;
	    	b = M;
	    	A1.push_back(a);
	        B1.push_back(b);
	    }
	    else{
	    	a = 0;
	    	A1.push_back(a);
	    	B1.push_back(b);
	    	a = m;
	    }
	}
	outPut(A1,B1,L);
}

int main(){
	Bucket_problem();
	return 0;
}