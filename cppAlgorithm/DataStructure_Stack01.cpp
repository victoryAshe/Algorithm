// 22-1 자료구조: 연결리스트 실습 220421_2: 스택
#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 100;
int stack[MAX_STACK_SIZE];
int top = -1;

bool is_empty_stack()
{
	//if (top == -1) return true;
	//else return false;
	return (top == -1);
}

bool is_full()
{
	//if (top == MAX_STACK_SIZE - 1) return true;
	//else return false;
	return (top == MAX_STACK_SIZE - 1);
}

void push(int value)
{
	if (is_full())
	{
		cout << "ERROR: Stack Overflow" << endl;
		exit(1);
	}
	else
	{
		stack[++top] = value;
	}
}

int pop()
{
	if (is_empty_stack())
	{
		cout << "ERROR: Stack Underflow" << endl;
		exit(1);
	}
	else
	{
		//int x = stack[top];
		//top--;
		//return x;
		return stack[top--];
	}
}

void print_stack()
{

}

void main()
{
	push(10);
	push(20);
	pop();
}