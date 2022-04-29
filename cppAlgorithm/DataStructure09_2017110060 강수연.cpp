// 22-1 자료구조 과제물 #9. 스택의 구현
#include<iostream>
using namespace std;

#define MAX_STACK_SIZE 100
typedef int element;

class Stack {
public:
	element data[MAX_STACK_SIZE];
	int top; // Stack Pointer

	Stack() { top = -1; } //생성자 함수

	bool is_empty()
	{
		return(top == -1);
	}

	bool is_full()
	{
		return (top == (MAX_STACK_SIZE - 1));
	}

	void push(element item) // 삽입 함수
	{
		if (is_full())
		{
			cout << "Error: Stack Overflow" << endl;
			return;
		}
		else
		{
			cout << item << " was added." << endl;
			data[++top] = item;
		}
	}

	element pop()	// 삭제 함수
	{
		if (is_empty())
		{
			cout << "Error: Stack Underflow" << endl;
			exit(1);
		}
		else
		{
			cout << data[top] << " was deleted." << endl;
			return data[top--];
		}
	}

	element peek()	//peek 함수(* 삭제는 하지 않고 반환만 하는 함수)
	{
		if (is_empty())
		{
			cout << "Error: Stack has no element" << endl;
			exit(1);
		}
		else return data[top];
	}

	void print()
	{
		int j;
		cout << "Stack: ";
		if (is_empty())
		{
			cout << "Stack has no element." << endl;
			return;
		}
		for (j = 0; j <= top; j++)
			cout << data[j] << " ";
		cout << endl;
	}
};	// end of Class Stack

void main()
{
	Stack stack = Stack();
	stack.print();
	cout << endl;

	cout << "[push 구현]" << endl;
	int i;
	for (i = 1; i <= 10; i++)
		stack.push(i * 10);
	stack.print();
	cout << endl;

	cout << "[pop 구현]" << endl;
	for (i = 0; i < 5; i++)
		stack.pop();
	stack.print();
	cout << endl;

	for (i = 0; i < 5; i++)
		stack.pop();
	stack.print();
	cout << endl;

}