// 22-1 자료구조: 연결리스트 실습 220414_2: 다항식 덧셈
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
	void insert_node(Node* new_node);
	
};

void LinkedList::traverse()
{
	for (Node* temp = head; temp; temp = temp->link)
		cout << temp->coef<<"x^"<<temp->expon << "->";
	cout << endl;
}

void LinkedList::insert_node(Node* new_node)
{

}

Node* addMultinominal(Node* head1, Node* head2)
{
	Node* head3;


	return head3;
}

Node* A, * B;


int main()
{
	*A = Node(3, 12);
	*B = Node(8, 12);



	return 0;
}