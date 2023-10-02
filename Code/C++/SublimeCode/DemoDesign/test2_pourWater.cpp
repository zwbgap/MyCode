#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//������
void outPut(vector<int> a_vec,vector<int> b_vec,int L){
	vector<int>::iterator ita, itb, it;
	for (it = b_vec.begin();it <b_vec.end();it++)
	{
		if(*it == L)
			break;
	}
	cout << "A" << "'\t" << "B" << endl;
    //�ж�it���Ҳ��ֳ���
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
    cout << "B��װ��" << L << "��ˮ��" << endl;
}

void Bucket_problem(){
	int A, B, L;
	vector<int> A1, B1;
	//int flag = 0;
	cout << "�ֱ���������A(С)������B(��)���ݻ���" << endl;
	cin >> A >> B;
	cout << "�����װˮ�������" << endl;
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
		cout << "��ʱA��װ��" << m << "��ˮ" << endl;
		return;  
	}
	if(L == M){
		cout << "A" << "\t" << "B" << endl;
		cout << "0" << "\t" << M << endl;
		cout << "��ʱB��װ��" << M << "��ˮ" << endl;
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