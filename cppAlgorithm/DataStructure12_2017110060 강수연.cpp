// 22-1 자료구조 과제물 #12 큐의 구현 - 연결리스트
#include <iostream>
#include <string>
using namespace std;

typedef char element;

class QNode
{
public:
	element data;
	QNode* link;
};

QNode* front, * rear;

void init() { front = rear = NULL; }
int is_Empty() { return(front == NULL); }

void enQueue(element item)
{
	QNode* newNode = new QNode();
	newNode->data = item;
	newNode->link = NULL;
	
	if (front == NULL)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear -> link = newNode;
		rear = newNode;
	}
}

element deQueue()
{
	QNode* old = front;
	element item;
	if (is_Empty()) return 0; //또는 오류 처리
	else
	{
		item = front->data;
		front = front->link;
		if (front == NULL) rear == NULL;
		return item;
	}
}

void print()
{
	if (front == NULL)
	{
		cout << "큐에 노드가 없습니다." << endl;
		return;
	}
	QNode* temp = front;
	while (temp)
	{
		cout << temp->data;
		if (temp->link) cout << " -> ";
		temp = temp->link;
	}
	cout << endl;
}

void main()
{
	print();

	string s = "DataStructure";
	int i;
	for (i = 0; i < s.length(); i++)
		enQueue(s[i]);
	print();
	
	for (i = 0; i <= 3; i ++)
		deQueue();
	print();

	return;
}