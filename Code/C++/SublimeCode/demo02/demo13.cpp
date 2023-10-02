#include<iostream>
using namespace std;

class StackOfIntergers{
public:
	StackOfIntergers();
	bool isEmpty() const;
	int peek() const;
	void push_back(int value);
	int pop_back();
    int getSize() const; 
private:
	int elements[100];
	int size;
};

int main(){
	StackOfIntergers stack;
	
    for(int i = 0; i < 100; i++)
    	stack.push_back(i);
    while(!stack.isEmpty())
    	cout << stack.pop_back() << " ";
    cout << endl;
	return 0;
}
StackOfIntergers::StackOfIntergers(){
	size = 0;
}
bool StackOfIntergers::isEmpty() const{
	return size == 0;
}
int StackOfIntergers::peek() const{
	return elements[size-1];
}
void StackOfIntergers::push_back(int value){
	elements[size++] = value;
}
int StackOfIntergers::pop_back(){
	return elements[--size];
}
int StackOfIntergers::getSize() const{
	return size;
}