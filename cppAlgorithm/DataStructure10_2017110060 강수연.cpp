//22-1 자료구조 과제물 #10. 후위표기식 변환 + 계산
#include <string>
#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 100

class Stack {
public:
	double data[MAX_STACK_SIZE];
	int top; // Stack Pointer
	Stack() { top = -1; } //생성자 함수
	bool is_Empty(){ return(top == -1); }

	bool is_full(){ return (top == (MAX_STACK_SIZE - 1)); }

	void push(double item) // 삽입 함수
	{
		if (is_full())
		{
			cout << "Error: Stack Overflow" << endl;
			return;
		}
		else data[++top] = item;
	}

	double pop()	// 삭제 함수
	{
		if (is_Empty())
		{
			cout << "Error: Stack Underflow" << endl;
			exit(1);
		}
		else return data[top--];
	}

	double peek()	//peek 함수(* 삭제는 하지 않고 반환만 하는 함수)
	{
		if (is_Empty())
		{
			cout << "Error: Stack has no element" << endl;
			exit(1);
		}
		else return data[top];
	}

};	// end of Class Stack



// 객체의 우선순위 계산
inline int precedence(char op)
{
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// 중위 표기 수식-> 후위표기 수식 함수
string infix2Postfix(FILE* fp = stdin)
{
	string postfix = "";
	char c, op; double val; Stack stack; 
	while ((c = getc(fp)) != '\n')  // 엔터 문자 입력 전까지
	{
		if (c >= '0' && c <= '9')
		{
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			postfix += to_string(val); postfix += " ";
		}
		else if (c == '(') stack.push(c);
		else if (c == ')')
		{
			while (!stack.is_Empty())
			{
				op = stack.pop();
				if (op == '(') break;
				else postfix += op; postfix += " ";
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			while (!stack.is_Empty())
			{
				op = stack.peek();
				if (precedence(c) <= precedence(op))
				{
					postfix += op; postfix += " ";
					stack.pop();
				}
				else break;
			}
			stack.push(c);
		}
	}
	while (!stack.is_Empty())
	{
		postfix += (char)stack.pop(); postfix += " ";
	}
	postfix += "\n";
	cout << "Postifx: " << postfix ;
	return postfix;
}

void calcPostfix(string postfix)
{
	char c; Stack stack;
	int i; string num = "";
	for(i = 0 ; i<postfix.length(); i++)
	{
		char c = postfix[i];
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			
			double val2 = stack.pop();
			double val1 = stack.pop();
			switch (c) {
			case '+': stack.push(val1 + val2); break;
			case '-': stack.push(val1 - val2); break;
			case '*': stack.push(val1 * val2); break;
			case '/': stack.push(val1 / val2); break;
			}
		}
		else if ((c >= '0' && c <= '9')|| c=='.')
			num += c;
		else if (c == ' ' && num!="")
		{
			stack.push(stod(num)); num = "";
		}
	}
	cout<< "Calc Result: "<< stack.pop() << endl;
}



void main()
{
	cout << "수식 입력 (Infix) = ";
	string postfix = infix2Postfix();
	calcPostfix(postfix);
	return;
}