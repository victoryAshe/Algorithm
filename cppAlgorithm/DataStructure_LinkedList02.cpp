// 22-1 자료구조: 연결리스트 실습 220414_1

#include<iostream>
using namespace std;

class Node {
public:

	int data; Node* link = NULL;

	Node(int data, Node* link)
	{
		this->data = data;
		this->link = link;
	}

	Node(int data)
	{
		this->data = data;
	}

};

class LinkedList {
public:

	Node* head = NULL;

	void traverse()
	{
		for (Node* temp = head; temp; temp = temp->link)
			cout << temp->data << "->";
		cout << endl;
	}


	void insert_node_at_front(Node* new_node)
	{
		new_node->link = head;
		head = new_node;
	}

	void insert_node(Node* pre, Node* new_node)
	{
		if (head == NULL) head = new_node;	// 공백 리스트인 경우
		else if (pre == NULL)				// pre가 NULL이면 첫번째 노드로 삽입
			insert_node_at_front(new_node);
		else								// pre 다음에 삽입
		{
			new_node->link = pre->link;
			pre->link = new_node;
		}
	}

	void insert_node(int value)		// 선행 노드를 모르는 경우: 맨 뒤에 삽입
	{
		Node* new_node = new Node(value);
		if (head == NULL) head = new_node;	// 공백 리스트인 경우
		else
		{
			Node* temp = head;
			while (temp->link) temp = temp->link;
			temp->link = new_node;
		}
	}

	void remove_node(int key)
	{
		Node* target = head;

		if (head == NULL)				// 삭제할 것이 없음
		{
			cout << "빈 리스트는 지울 수 없습니다." << endl;
			return;
		}
		else if (head->data == key)		// 삭제할 노드가 첫 노드인 경우
		{
			head = head->link;
			return;
		}
		else							// 나머지 경우
		{
			while (target->link)
			{
				if (target->link->data == key)
				{
					target->link = target->link->link;
					return;
				}
				target = target->link;
			}
		}
		cout << "입력한 값이 해당 연결 리스트에 없습니다." << endl;

	}

	Node* search(int key)
	{
		Node* temp = head;
		while (temp)
		{
			if (temp->data == key) return temp;
			temp = temp->link;
		}
		return temp;
	}

	Node* reverse();
};


Node* LinkedList::reverse()
{
	Node* p, * q, * r;				// 순회 포인터
	p = head;
	q = NULL;						// p: 현재 가리키는 노드, q: 이전 노드,  r = NULL
	while (p != NULL)
	{
		r = q; q = p; p = p->link;	// 뒤로 한 칸씩 이동
		q->link = r;				// p의 link 방향 바꾸기
	}
	head = q;						// q: 역순으로 된 리스트의 Head Pointer
	return head;


}


Node* concat(Node* head1, Node* head2)
{
	Node* ptr;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else
	{
		ptr = head1;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = head2;
		return head1;
	}
}

int main()
{
	// 연결리스트 생성
	cout << "[연결 리스트 생성]" << endl;
	LinkedList linkedList = LinkedList();
	int data = 10;
	for (int i = 1; i <= 10; i++) linkedList.insert_node(data * i);
	linkedList.traverse();
	cout << endl;
	
	// 리스트 역순 만들기
	cout << "[리스트 역순 만들기]" << endl;
	linkedList.reverse();
	linkedList.traverse();
	cout << endl;
	return 0;
}