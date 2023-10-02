#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	// ofstream output;
	// output.open("demo.txt");
	// output << "Jone" << " " << "T" << " "
	// << "Smith" << " " << 90 << endl;
	// output << "Eric" << " " << "K" << " "
	// << "Jones" << " " << 85 << endl;
	// output.close();
	// cout << "Done" << endl;
	
	ifstream input("demo.txt");
	string firstName;
	char mi;
	string lastName;
	int score;
	input >> firstName >> mi >> lastName >> score;
	cout << firstName << " " << mi << " " << lastName << " " << score << endl;
	input >> firstName >> mi >> lastName >> score;
	cout << firstName << " " << mi << " " << lastName << " " << score << endl;

    cout << "Done" << endl;
	return 0;
}