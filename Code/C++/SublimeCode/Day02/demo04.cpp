#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string fileName;
	cout << "Enter a fileName: " << endl;
	cin >> fileName;
	ifstream input(fileName.c_str()); 
	if(input.good())
		cout << fileName << " does not exist" << endl;
	else
		cout << fileName << " exists" << endl;

	return 0;
}