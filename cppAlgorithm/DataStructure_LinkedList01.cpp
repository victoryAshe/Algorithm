// 22-1 자료구조: 연결리스트 실습 220407

#include<iostream>
using namespace std;

class Node {
public:

	int data; Node *link = NULL;

	Node(int data, Node *link)
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
		/*
		Node* temp = head;
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->link;
		}
		*/
		
		for (Node* temp = head; temp; temp = temp->link)
			cout << temp->data << "->";
		cout << endl;
	}
	

	void insert_node_at_front(Node* new_node)
	{
		new_node->link = head;
		head = new_node;
	}

	void insert_node(Node *pre, Node *new_node)
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

};

int main()
{
	LinkedList linkedList = LinkedList();
	
	cout << "[연결 리스트 생성]" << endl;
	Node* p1 = new Node(11, new Node(12));
	linkedList.head = p1;

	linkedList.traverse();
	cout << endl;

	cout << "[노드 삽입: 중간]" << endl;
	Node* p3 = new Node(13);
	linkedList.insert_node(p1, p3);
	linkedList.traverse();
	cout << endl;

	cout << "[노드 삽입: 맨 뒤]" << endl;
	linkedList.insert_node(14);
	linkedList.traverse();
	cout << endl;	
	
	cout << "[노드 삽입: 맨 앞]" << endl;
	Node* p5 = new Node(15);
	linkedList.insert_node_at_front(p5);
	linkedList.traverse();
	cout << endl;

	cout << "[노드 삭제]" << endl;
	int data;
	cout << "연결 리스트에서 삭제할 데이터: ";
	cin >> data;
	linkedList.remove_node(data);
	linkedList.traverse();
	cout << endl;
}
