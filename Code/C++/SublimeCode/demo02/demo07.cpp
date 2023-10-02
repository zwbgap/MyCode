#include <iostream>
#include <ctime>
using namespace std;
const int NUMBER_OF_LETTERS = 26;
const int NUMBER_OF_RANDOM_LETTERS = 100;
void creatArray(char []);
void displayArray(const char []);
void countLetters(const char [],int []);
void displayCounts(const int[]);

int main(){
    char chars[NUMBER_OF_RANDOM_LETTERS];
    creatArray(chars);
    cout << "The lowercase letters are: " << endl;
    displayArray(chars);
    int counts[NUMBER_OF_LETTERS];
    countLetters(chars,counts);
    cout << "\nThe occurrences of the letters are: " << endl;
    displayCounts(counts);
    cout << '\n';
    return 0;
}
void creatArray(char ch[]){
    srand(time(0));
    for (int i = 0; i < NUMBER_OF_RANDOM_LETTERS; ++i)
        ch[i] = static_cast<char>('a'+rand()%('z'-'a'+1));
}
void displayArray(const char ch[]){
    for(int i = 0; i < NUMBER_OF_RANDOM_LETTERS;i++){
        if((i+1)%20 == 0)
            cout << ch[i] << " " << endl;
        else
            cout << ch[i] << " ";
    }
}
void countLetters(const char ch[],int counts[]){
    for(int i = 0; i < NUMBER_OF_LETTERS;i++)
        counts[i] = 0;
    for(int i = 0; i < NUMBER_OF_RANDOM_LETTERS;i++)
        counts[ch[i]-'a']++;

}
void displayCounts(const int counts[]){
    for(int i = 0; i < NUMBER_OF_LETTERS;i++){
        if((i+1)%10)
            cout << static_cast<char>(i+'a') << ":" << counts[i] << " ";
        else
            cout << static_cast<char>(i+'a') << ":" << counts[i] << endl;
    }
}