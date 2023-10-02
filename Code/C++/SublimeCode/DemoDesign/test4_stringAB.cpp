#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minDist(string A, string B){
	int a_len = A.length();
	int b_len = B.length();
	int Dist[b_len+1][a_len+1];
	for(int j = 0; j <= a_len; j++)
		Dist[0][j] = j;//��ʼ����һ��
	for(int i = 0; i <= b_len; i++)
		Dist[i][0] = i;//��ʼ��һ��
	for(int i = 1; i <= b_len; i++){
		for(int j = 1; j <= a_len; j++){
			Dist[i][j] = min(min(Dist[i - 1][j] + 1, Dist[i][j - 1] + 1), (A[j - 1] == B[i - 1] ? Dist[i - 1][j - 1] : Dist[i - 1][j - 1] + 1));
		    //cout << Dist[i][j] << " ";
		}
	}
	return Dist[b_len][a_len];
}

int main(){
	string a, b;
	cout << "�������ַ���A��" << endl;
	cin >> a;
	cout << "�������ַ���B��" << endl;
	cin >> b;
	cout << "���ٴ�����" << minDist(a, b) << endl;
	return 0;

}