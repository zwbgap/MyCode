#include<iostream>
#include<string>
#include<sstream>
using namespace std;

bool replaceString(string& s, const string& oldSubStr,
  const string& newSubStr);
int main(){
	// string s1("Welcome to the c++!");
	// string s2("Welcomg");
	// cout << s1.compare(s2) << endl;
    // cout << s2.compare(s1) << endl;
    // cout << s1.find("l") << endl;
    // for(int i = s1.size()-1;i>=0;i--){
    // 	cout << s1[i];
    // }
    // cout << s1.c_str() << endl;
    
    // string s1, s2;
    // cin >> s1;
    // s2 = s1;
    // char ch;
    // for(int i = 0; i < s1.size()/2;i++){
    // 	ch = s1[i];
    // 	s1[i] = s1[s1.size()-1-i];
    // 	s1[s1.size()-1-i] = ch;
    // }
    // cout << s1 << endl;
    // if(s1.compare(s2)) cout << "flase" << endl;
    // else cout << "true" << endl;
    
    // string text =("Programming is the most fun thing!");
    // stringstream ss(text);
    // cout << "The words in the text are : " << endl;
    // string word;
    // while(!ss.eof()){
    // 	ss >> word;
    // 	cout << word << "\n";
    // }
    // 
    
    cout << "Enter string s, oldSubStr. newSubStr:" << endl;
    string s, oldSubStr, newSubStr;
    cin >> s >> oldSubStr >> newSubStr;
    bool isReplaced =  replaceString(s,oldSubStr,newSubStr);
    if(isReplaced) cout << s << endl;
    else cout << "no matches" << endl;
	return 0;
}

bool replaceString(string&s, const string& oldSubStr,
 const string& newSubStr){
 	bool isReplaced = false;
 	int currentPosition = 0;
    while(currentPosition < s.length()){
    	int position = s.find(oldSubStr, currentPosition);
    	if(position == string::npos) 
    		return isReplaced;
    	else{
    		s.replace(position,oldSubStr.length(),newSubStr);
    		currentPosition = position + newSubStr.length();
    		isReplaced = true;
    	}
    }
    return isReplaced;
}