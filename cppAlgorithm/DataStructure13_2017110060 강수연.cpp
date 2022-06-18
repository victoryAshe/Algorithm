// 22-1 자료구조 과제 #13. 원형 큐의 구현
#include <iostream>
using namespace std;

#define MAX_Q_SIZE 100
typedef int element;
element cQueue[MAX_Q_SIZE];
int front, rear;

void init()
{
	front = rear = 0;
}

bool is_Empty()
{
	return front == rear;
}

bool is_full()
{
	return front == (rear + 1) % MAX_Q_SIZE;
}

void enQueue(element item)
{
	if (is_full())
	{
		cout << "Error: Queue overflow" << endl;
	}
	else
	{
		rear = (rear + 1) % MAX_Q_SIZE;
		cQueue[rear] = item;
	}
}

element deQueue()
{
	if (is_Empty())
	{
		cout << "Error: Queue underflow" << endl;
	}
	else
	{
		front = (front + 1) % MAX_Q_SIZE;
		int x =  cQueue[front];
		cQueue[front] = NULL;
		return x;
	}
}

element peek()
{
	if (is_Empty())
	{
		cout << "Error: Queue has no element" << endl;
		exit(1);
	}
	else return cQueue[front+1];
}

void print()
{
	if (is_Empty())
	{
		cout << "Error: Queue has no element" << endl;
		return;
	}
	
	cout << "cQueue: ";
	for (int p = (front + 1) % MAX_Q_SIZE; p != (rear + 1) % MAX_Q_SIZE; p = (p + 1) % MAX_Q_SIZE)
		cout << cQueue[p] << " ";
	cout << endl;
}

void main()
{
	print();
	
	int i;
	for (i = 1; i <= 10; i++)
		enQueue(i * 10);
	print();
	
	for (i = 0; i < 3; i++) cout << deQueue() << "를 삭제했습니다." << endl;
	print();

	cout << "현재 제일 앞의 요소는 " << peek() << "입니다." << endl;
}