#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "ImprovedStack.h"
using namespace std;

//Split an expression into numbers, operators, and parentheses
vector<string> split(const string& compression);

//Evaluate the expression and return the result
int evaluateExpression(const string& expression);

//Perform an operation
void processAnOperation(
	Stack<int>& operandStack, Stack<char>& operatorStack);


int main(){
	string expression;
	cout << "Enter expression" << endl;
	getline(cin, expression);
	cout << "The result is " <<  endl;
	cout << expression << " = " << evaluateExpression(expression) << endl;

	return 0;
}

vector<string> split(const string& expression)
{
	vector<string> v; //A vector to store split items as strings
	string numberString;  //A numberic string

	for(unsigned i = 0; i < expression.length(); i++)
	{
		if(isdigit(expression[i]))
			numberString.append(1,expression[i]); //append a digit
		else
		{
			if(numberString.size() > 0)
			{
				v.push_back(numberString); //store the numberic string
				numberString.erase(); //Empty the numberic string
			}
			if(!isspace(expression[i]))
			{
				string s;
				s.append(1,expression[i]);
				v.push_back(s); //store an operator and parenttheses
			}
		}
	}
	//store the last numberic string
	if(numberString.size() > 0)
		v.push_back(numberString);
	
	return v;
}


//Evaluate an expression
int evaluateExpression(const string& expression)
{
	//Creat an operandStack to store operand
	Stack<int> operandStack;

	//Creat an operatorStack to store operators
	Stack<char> operatorStack;

	//Extract operands and operators
	vector<string> tokens = split(expression);

	for(unsigned i = 0; i < tokens.size(); i++){
		if(tokens[i][0] == '+' || tokens[i][0] == '-')
		{
			while(!operatorStack.empty() && (operatorStack.peek() == '+'
			 || operatorStack.peek() == '-' || operatorStack.peek() == '*'
			 || operatorStack.peek() == '/'))
			{
				processAnOperation(operandStack, operatorStack);
			}
			operatorStack.push(tokens[i][0]);
		}
		else if(tokens[i][0] == '*' || tokens[i][0] == '/')
		{
			while(!operatorStack.empty() && (operatorStack.peek() == '*'
				|| operatorStack.peek() == '/'))
			{
				processAnOperation(operandStack, operatorStack);
			}
			operatorStack.push(tokens[i][0]);
		}
		else if(tokens[i][0] == '(')
		{
			operatorStack.push('(');
		}
		else if(tokens[i][0] == ')')
		{
			while(operatorStack.peek() != '(')
			{
				processAnOperation(operandStack, operatorStack);
			}
			operatorStack.pop();
		}
		else
		{
			operandStack.push(atoi(tokens[i].c_str()));
		}
	}
	while(!operatorStack.empty())
	{
		processAnOperation(operandStack, operatorStack);
	}
	return operandStack.pop();
}

void processAnOperation(
	Stack<int>& operandStack, Stack<char>& operatorStack)
{
	char op = operatorStack.pop();
	int op1 = operandStack.pop();
	int op2 = operandStack.pop();
	if(op == '+')
		operandStack.push(op2 + op1);
	if(op == '-')
		operandStack.push(op2 - op1);
	if(op == '*')
		operandStack.push(op2 * op1);
	if(op == '/')
		operandStack.push(op2 / op1);
}
