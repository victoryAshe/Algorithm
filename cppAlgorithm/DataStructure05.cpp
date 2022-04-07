// ���Ḯ��Ʈ �ǽ� 220407
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

	void insert_node(Node* pre, Node* new_node)
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

		if (head == NULL) return;
		else if (head->data == key)
		{
			head = head->link;
			return;
		}
		else
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

	//���� 1: ���� ����Ʈ ����� ���
	LinkedList linkedList = LinkedList();

	int num = 0, data = 0;
	cout << "������ ����� ����: ";
	cin >> num;
	cout << endl;

	for (int i = 0; i < num; i++)
	{
		cout << "������ ������: ";
		cin >> data;
		linkedList.insert_node(data);
	}
	cout << endl;
	linkedList.traverse();
	cout << endl;

	//���� 2: ���� ����Ʈ ��� ����
	cout << "���� ����Ʈ���� ������ ������: ";
	cin >> data;
	linkedList.remove_node(data);
	linkedList.traverse();

}
