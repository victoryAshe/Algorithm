// 22-1 자료구조 과제물 #7. 다항식 덧셈
#include<iostream>
using namespace std;

class Node {
public:
	int coef;
	int expon;
	Node* link = NULL;

	Node(int coef, int expon)
	{
		this->coef = coef;
		this->expon = expon;
	}

	Node(int coef, int expon, Node* link)
	{
		this->coef = coef;
		this->expon = expon;
		this->link = link;
	}
};

class LinkedList
{
public:
	Node* head = NULL;
	
	void traverse();
	void insert_node(int coef, int expon);
	
};

void LinkedList:: traverse()
{
	for (Node* temp = head; temp; temp = temp->link)
	{
		if(temp->link)
			cout << temp->coef << " x^" << temp->expon << " -> ";
		else
			cout << temp->coef << " x^" << temp->expon;
	}
		
	cout << endl;
}

void LinkedList::insert_node(int coef, int expon)
{
	Node* new_node = new Node(coef, expon);
	if (head == NULL) head = new_node;	// 공백 리스트인 경우
	else
	{
		Node* temp = head;
		while (temp->link) temp = temp->link;
		temp->link = new_node;
	}
}


LinkedList addMultinominal(Node* head1, Node* head2)
{
	LinkedList C = LinkedList();
	Node* p = head1, * q = head2;

	while (p && q)
	{
		if (p->expon == q->expon)
		{
			if (p->coef + q->coef != 0)
				C.insert_node(p->coef + q->coef, p->expon);
			p = p->link; q = q->link;
		}
		else if (p->expon < q->expon)
		{
			C.insert_node(q->coef, q->expon);
			q = q->link;
		}
		else
		{
			C.insert_node(p->coef, p->expon);
			p = p->link;
		}
	}

	// TODO: A와 B 중 하나의 순회가 끝났을 경우의 예외 처리
	while (p != NULL)
	{
		C.insert_node(p->coef, p->expon);
		p = p->link;
	}

	while (q != NULL)
	{
		C.insert_node(q->coef, q->expon);
		q = q->link;
	}

	return C;
}

Node* A, * B;

int main()
{
	// TODO: 다항식 A, B 구성
	A = new Node(3, 12);
	B = new Node(8, 12);

	LinkedList eA = LinkedList();	
	LinkedList eB = LinkedList();
	eA.head = A;	eB.head = B;
	eA.insert_node(2, 8);	eA.insert_node(1, 0);
	eB.insert_node(-3, 10);	eB.insert_node(10, 6);

	cout << "[다항식 A, B 구성]" << endl;
	cout << "A: ";	eA.traverse();	
	cout << "B: ";	eB.traverse();
	cout << endl;

	// TODO: 다항식 덧셈 수행
	LinkedList C = addMultinominal(eA.head, eB.head);
	cout << "[다항식 덧셈 수행]" << endl;
	cout << "C: ";	C.traverse();
	cout << endl;

	return 0;
}