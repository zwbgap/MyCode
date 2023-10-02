#include<iostream>
#include <cstring>
using namespace std;
int main(){
    // char ch[30] = "nihaocity";
    // //ch = "new york";
    // strcpy(ch,"NEW YORK");
    // cout << ch << endl;
    // char s1[7] = "abc";
    // char s2[4] = "abg";
    // cout << strcmp(s2,s1) << endl;
    // char s1[] = "65.8";
    // char s2[] = "39.6";
    // cout << atoi(s1) + atoi(s2) << endl;
    // cout << atof(s1) + atof(s2) << endl;
	char s1[] = "abc";
	char s2[] = "efg";
	//cout << (s1[0] > s2[0]) << endl;
	cout << strcmp(s1,s2) << endl;
	cout << strlen(s1) << endl;
	cout <<strlen(s2) << endl;
	return 0;
}