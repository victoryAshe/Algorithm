// 22-1 자료구조: 연결리스트 실습 220421: 이중 연결리스트

#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* llink = NULL;
	Node* rlink = NULL;
	Node(int data, Node* llink, Node* rlink)
	{
		this->data = data;
		this->llink = llink;
		this->rlink = rlink;
	}

	Node(int data)
	{
		this->data = data;
	}

};

class LinkedList {
public:

	Node* head = NULL;

	void dinsert_node(Node* pre, Node* new_node); // 선행 노드를 아는 경우
	void dinsert_node(Node* new_node);					// 첫 노드로 삽입하는 경우
	void dinsert_node_back(Node* new_node);			// 맨 뒤에 삽입
	void dremove_node(int key);
	void Ltraverse();
	void Rtraverse();

};

void LinkedList::dinsert_node(Node* pre, Node* new_node)
{
	// new_node를 pre의 오른쪽에 삽입
	new_node->llink = pre;
	new_node->rlink = pre->rlink;
	pre->rlink->llink = new_node;
	pre->rlink = new_node;
}

void LinkedList::dinsert_node(Node* new_node)
{
	// 리스트의 첫 노드로 삽입 == 헤드 노드 다음에 넣기
	new_node->llink = head;
	new_node->rlink = head->rlink;
	head->rlink->llink = new_node;
	head->rlink = new_node;
}

void LinkedList::dinsert_node_back(Node* new_node)
{
	new_node->rlink = head;
	new_node->rlink = head->llink;
	head->llink->rlink = new_node;
	head->llink = new_node;
}

void LinkedList::Ltraverse()
{
	Node* list;
	if (head == head->rlink)cout << "빈 리스트입니다." << endl;
	for (list = head->llink; list != head; list = list->llink)
	{
		cout << list->data;
		if (list != head->rlink)
			cout << " -> ";
	}
	cout << endl;
}

void LinkedList::Rtraverse()
{
	Node* list;
	if (head == head->llink)cout << "빈 리스트입니다." << endl;
	for (list = head->rlink; list != head; list = list->rlink)
	{
		cout << list->data;
		if (list != head->llink)
			cout << " -> ";
	}
	cout << endl;
}

void LinkedList::dremove_node(int key)
{
	for(Node* list = head->rlink; list!=head; list = list->rlink)
		if (list->data == key)
		{
			list->llink->rlink = list->rlink;
			list->rlink->llink = list->llink;
			cout << key << "값의 노드가 삭제되었습니다." << endl;
			return;
		}
	cout << key << "값을 가진 노드가 없습니다." << endl;
}

int main()
{
	// 이중 연결리스트 생성
	cout << "[이중 연결 리스트 생성 및 출력]" << endl;
	LinkedList linkedList = LinkedList();
	Node* Head = new Node(NULL);
	Head->llink = Head->rlink = Head;
	linkedList.head = Head;

	for (int i = 1; i < 9; i++) linkedList.dinsert_node(new Node(10 * i));
	linkedList.Ltraverse();
	cout << endl;

	cout << "[역순 출력]" << endl;
	linkedList.Rtraverse();
	cout << endl;

	// 노드 삭제
	cout << "[노드 삭제]" << endl;
	linkedList.dremove_node(60);
	linkedList.Ltraverse();
	linkedList.Rtraverse();
	cout << endl;

	cout << "[모든 노드 삭제]" << endl;
	for (int i = 1; i < 9; i++)linkedList.dremove_node(10* i);
	cout << endl;

	cout << "[리스트가 비었는지 확인]" << endl;
	linkedList.Ltraverse();
	cout << endl;


}
