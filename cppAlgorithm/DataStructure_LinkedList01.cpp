// 22-1 �ڷᱸ��: ���Ḯ��Ʈ �ǽ� 220407

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
		if (head == NULL) head = new_node;	// ���� ����Ʈ�� ���
		else if (pre == NULL)				// pre�� NULL�̸� ù��° ���� ����
			insert_node_at_front(new_node);
		else								// pre ������ ����
		{
			new_node->link = pre->link;
			pre->link = new_node;
		}
	}

	void insert_node(int value)		// ���� ��带 �𸣴� ���: �� �ڿ� ����
	{
		Node* new_node = new Node(value);
		if (head == NULL) head = new_node;	// ���� ����Ʈ�� ���
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

		if (head == NULL)				// ������ ���� ����
		{
			cout << "�� ����Ʈ�� ���� �� �����ϴ�." << endl;
			return;		
		}
		else if (head->data == key)		// ������ ��尡 ù ����� ���
		{
			head = head->link;
			return;
		}
		else							// ������ ���
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
		cout << "�Է��� ���� �ش� ���� ����Ʈ�� �����ϴ�." << endl;

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
	
	cout << "[���� ����Ʈ ����]" << endl;
	Node* p1 = new Node(11, new Node(12));
	linkedList.head = p1;

	linkedList.traverse();
	cout << endl;

	cout << "[��� ����: �߰�]" << endl;
	Node* p3 = new Node(13);
	linkedList.insert_node(p1, p3);
	linkedList.traverse();
	cout << endl;

	cout << "[��� ����: �� ��]" << endl;
	linkedList.insert_node(14);
	linkedList.traverse();
	cout << endl;	
	
	cout << "[��� ����: �� ��]" << endl;
	Node* p5 = new Node(15);
	linkedList.insert_node_at_front(p5);
	linkedList.traverse();
	cout << endl;

	cout << "[��� ����]" << endl;
	int data;
	cout << "���� ����Ʈ���� ������ ������: ";
	cin >> data;
	linkedList.remove_node(data);
	linkedList.traverse();
	cout << endl;
}
