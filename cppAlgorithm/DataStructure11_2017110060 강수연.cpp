// 22-1 자료구조 과제물 #11. 큐의 구현 - 배열 방식
#include <iostream>
using namespace std;


#define MAX_Q_SIZE 100
typedef int element;
element Queue[MAX_Q_SIZE];
int front, rear;

void init() { front = rear = -1; }
int is_Empty() { return (front == rear); }
int is_full() { return (rear == (MAX_Q_SIZE - 1)); }

//삽입
void enQueue(element item)
{
	if (is_full())
	{
		cout << "큐 포화 에러" << endl;
		return;
	}
	else Queue[++rear] = item;
}

//삭제
element deQueue()
{
	if (is_Empty())
	{
		cout << "큐 공백 에러" << endl;
		exit(1);
	}
	else return Queue[++front];
}

//peek
element peek()
{
	if (is_Empty())
	{
		cout << "큐 공백 에러" << endl;
		exit(1);
	}
	else return Queue[front];
}

void print()
{
	if (is_Empty())
	{
		cout << "큐에 데이터가 없습니다." << endl;
		return;
	}

	int i = front;
	cout << "[Queue]: ";
	while (i < rear + 1)
		cout << Queue[i++] << " ";
	cout << endl;
}

void main()
{
	print();

	int i;
	for (i = 1; i <= 10; i++)
		enQueue(i * 10);
	print();

	for (i = 0; i <= 3; i ++)
		deQueue();
	print();

	return;
}