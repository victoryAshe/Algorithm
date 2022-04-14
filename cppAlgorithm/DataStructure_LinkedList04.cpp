// 22-1 자료구조: 연결리스트 실습 220414_3: 원형 연결리스트

#include <iostream>
using namespace std;

class CNode 
{
public:
	int data;
	CNode* link = NULL;	
	
	CNode(int data, CNode* link)
	{
		this->data = data;
		this->link = link;
	}

	CNode(int data)
	{
		this->data = data;
	}

};

class LinkedList {
public:

	CNode* head = NULL;

	void traverse()
	{
		if (!head)
		{
			cout << "빈 리스트입니다." << endl;
			return;
		}
		else 
		{
			CNode* list = head;
			do 
			{
				cout << list->link->data << "->";
				list = list->link;
			} while (list != head);
		}
		cout << endl;
	}


	void insert_node_at_front(CNode* new_node)
	{
		if (!head)
		{
			new_node->link = new_node;
			head = new_node;
		}
		else 
		{
			new_node->link = head->link;
			head->link = new_node;
		}
	}

	void insert_node(CNode* pre, CNode* new_node)
	{
		if (!head)
		{
			new_node->link = new_node;
			head = new_node;
		}
		else if (!pre)
		{
			new_node->link = head->link;
			head->link = new_node;
		}
		else
		{
			new_node->link = pre->link;
			pre->link = new_node;
			if (head == pre) head = new_node;
		}
	}

	void insert_node(CNode *new_node)		// 선행 노드를 모르는 경우: 맨 뒤에 삽입
	{
		if (!head)
		{
			new_node->link = new_node;
			head = new_node;
		}
		else
		{
			new_node->link = head->link;
			head->link = new_node;
			head = new_node;
		}
	}

	void remove_node(int key)
	{
		if (!head)
		{
			cout << "빈 리스트는 지울 수 없습니다." << endl;
			return;
		}
		else if (head->link == head && head->data == key)head = NULL;	// 노드가 1개 && 값이 일치하는 경우
		else															// 그 외 일반적인 경우
		{
			CNode* list = head;
			do 
			{
				if (list->link->data == key)
				{
					CNode* removed = list->link;
					list->link = removed->link;
					if (head == removed) head = list;					// head 포인터 유지
					return;
				}
				list = list->link;
			} while (list != head);
		}
		cout << "입력한 값이 해당 연결 리스트에 없습니다." << endl;

	}

	CNode* search(int key)
	{
		CNode* temp = head;
		while (temp)
		{
			if (temp->data == key) return temp;
			temp = temp->link;
		}
		return temp;
	}

	CNode* reverse();
};

int main()
{
	// 원형 연결리스트 생성
	cout << "[원형 연결 리스트 생성]" << endl;
	LinkedList linkedList = LinkedList();
	int data = 10;
	for (int i = 1; i < 9; i++) linkedList.insert_node(new CNode(data * i));
	linkedList.traverse();
	cout << "헤드 포인터: " << linkedList.head->data << endl;
	cout << "헤드 포인터->link->data: " << linkedList.head->link->data << endl;
	cout << endl;

	// 노드 삭제
	cout << "[노드 삭제]" << endl;
	linkedList.remove_node(60);
	linkedList.traverse();
	cout << "헤드 포인터: " << linkedList.head->data << endl;
	cout << "헤드 포인터->link->data: " << linkedList.head->link->data << endl;	
	cout << endl;


}
