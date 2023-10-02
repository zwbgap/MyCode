#include <iostream>
#include<vector>
using namespace std;

int sum(const vector<vector<int> >& matrix){
	int total = 0;
	for(unsigned int i=0; i<matrix.size();i++){
		for(unsigned int j=0; j<matrix.size();j++){
			total += matrix[i][j];
		}
	}
	return total;
}

int main(){
	vector<vector<int> > matrix(4);
	int value;

	for(int i = 0; i < 4;i++){
		matrix[i] = vector<int>(3);
	}
	for(int i=0; i<4;i++){
		for(int j=0; j<3;j++){
			cin >> matrix[i][j];
		}
	}
    cout << sum(matrix) << endl; 

	return 0;
}