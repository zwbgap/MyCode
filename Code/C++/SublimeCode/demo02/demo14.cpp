#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAgagram(string& s1, string& s2);
string sort(string& s);
bool isPalindrome(string& s);

int main(){
	string s1, s2;
	cout << "Enter data: " << endl;
	cin >> s1;
    // if(isAgagram(s1,s2))
    // 	cout << "true" << endl;
    // else
    // 	cout << "false" << endl;

    if(isPalindrome(s1)) cout << "true" << endl;
    else cout << "false" << endl;
	return 0;
}

// bool isAgagram(string& s1, string& s2){
// 	sort(s1.begin(), s1.end());
// 	sort(s2.begin(), s2.end());
// 	cout << s1 << '\n' << s2 << endl;
// 	return s1 == s2;

// }
bool isAgagram(string& s1, string& s2){
	if(s1.length()!=s2.length()) return false;
	int array[26] = {0};
	for(int i = 0 ; i < s1.length();i++){
		array[s1[i]-'a']++;
	}
	for(int j = 0; j < s2.length();j++){
		array[s2[j]-'a']--;
	}
	for(int k = 0; k < 26;k++){
		if(array[k] != 0)
			return false;
	}
	return true;
}

string sort(string& s){
	for(int i = 0; i < s.length()-1;i++){
		char minValue = s[i];
	 	int MinIndex = i;
		for(int j = i+1; j < s.length();j++){
			if(minValue > s[j]){
				minValue = s[j];
				MinIndex = j;
			}
		}
		if(MinIndex != i){
			swap(s[i],s[MinIndex]);
		}
	}	
	return s;
}

bool isPalindrome(string& s){
	string s1 = s;
	char ch;
	for(int i = 0;i < s.length()/2;i++){
		ch = s[s.length()-1-i];
		s[s.length()-1-i] = s[i];
		s[i] = ch; 
	}
	// cout << s << endl;
	// cout << s1 <<endl;
	return s == s1;
}