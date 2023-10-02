#include<iostream>
#include<string>
using namespace std;

template<typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack&);
	~Stack();
	bool empty() const;
	T peek() const;
	void push(T value);
	T pop();
	int getSize() const;

private:
	T* elements;
	int size;
	int capacity;
	void ensureCapacity();
};

template<typename T>
Stack<T>::Stack():size(0), capacity(16)
{
	elements = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& stack)
{
	elements = new T[stack.capacity];
	size = stack.szie;
	capacity = stack.capacity;
	for (int i = 0; i < size; ++i)
		elements[i] = stack.elements[i];
}

template<typename T>
Stack<T>::~Stack()
{
	delete [] elements;
}

template<typename T>
bool Stack<T>::empty() const
{
	return size == 0;
}

template<typename T>
T Stack<T>::peek() const
{
	return elements[size-1];
}

template<typename T>
void Stack<T>::push(T value)
{
	ensureCapacity();
	elements[size++] = value;
}

template<typename T>
void Stack<T>::ensureCapacity()
{
	if(size >= capacity){
		T* old = elements;
		capacity = 2 * size;
		elements = new T[2 * size];
		for (int i = 0; i < size;i++)
			elements[i] = old[i];
		delete [] old;
	}
}

template<typename T>
T Stack<T>::pop()
{
	return elements[--size];
}

template<typename T>
int Stack<T>::getSize() const
{
	return size;
}

template<typename T>
void PrintStack(Stack<T>& stack)
{
	while(!stack.empty())
		cout << stack.pop() << " ";
	cout << endl;
}

int main(){
	Stack<int> intStack;
	for(int i = 0; i < 10;i++){
		intStack.push(i);
	}
	// while(!intStack.empty()){
	// 	cout << intStack.pop() << " ";
	// }
	// cout << endl;
    PrintStack(intStack);
    

	Stack<string> stringStack;
	stringStack.push("London");
	stringStack.push("Denver");
	stringStack.push("Chicago");

	// while(!stringStack.empty())
	// 	cout << stringStack.pop() << " ";
	// cout << endl;
	PrintStack(stringStack);

	return 0;
}
