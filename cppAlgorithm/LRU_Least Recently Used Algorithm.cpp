// LRU_Least Recently Used 알고리즘: https://dailylifeofdeveloper.tistory.com/355
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
    Node* prev; Node* next;
    string city;
    Node(string city)
    {
        this->city = city;
    }
};

// 이중 연결 리스트
class DoublyLinkedList
{
public:
    Node* head = NULL;
    Node* tail = NULL;
    int cacheSize;
    int len()
    {
        int length = 0;
        Node* node = head->next;
        while (node->next)
        {
            length++;
            node = node->next;
        }
        return length;
    };

    int runtime = 0;

    DoublyLinkedList(int cacheSize)
    {
        this->cacheSize = cacheSize;
        head = new Node("");    tail = new Node("");
        head->next = tail;      tail->prev = head;
    }

    void removeNode_front(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void removeNode_tail()
    {
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
    }

    void insert_node_front(string data)
    {
        Node* node = new Node(data);
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }

    void LRU(string data)
    {
        Node* node = head->next;
        while (node->next)
        {
            if (node->city == data)
            {
                cacheHit(node, data);
                return;
            }
            node = node->next;
        }
        cacheMiss(data);
    }
    void cacheHit(Node* node, string data)  // Cahce에 data가 존재하는 경우
    {
        removeNode_front(node);
        insert_node_front(data);
        runtime++;
    }
    void cacheMiss(string data)             // Cache에 data가 존재하지 않는 경우
    {
        // 연결리스트의 맨 앞에 data를 추가
        // if cacheSize < 원소 개수 : tail에 가까운 원소를 제거
        insert_node_front(data);
        if (len() > cacheSize)
            removeNode_tail();
        runtime += 5;
    }
};
