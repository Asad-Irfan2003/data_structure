#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(NULL) {}
    Node(int val) : data(val), next(NULL) {}
};
/*
Two pointers are used:
->One to point at start of linked list(Front)
->One to point at end of linked list(Rear)
*/
class queue
{
    Node *head;
    Node *tail;

public:
    queue() : head(NULL), tail(NULL) {}
    /*
    is_empty
    Algoirthm:
        ->Return true if head==NULL
    */
    bool is_empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    /*
    Enqueue()
    Algorithm:
        ->Create new node
        Case 1: queue is empty
            *)Point rear to new_node
            *)Point front to new_node
        Case 2: Queue is not empty
        ->Point next of rear to new_node
        ->Point rear to new_node

    */
    void enqueue(int data)
    {
        Node *new_node = new Node(data);
        if (is_empty() == true)
        {
            tail = new_node;
            head = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }
    int rear()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        return tail->data;
    }
    void dequeue()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        Node *temp = head;
        head = head->next;
        delete temp;
        if (is_empty() == true)
            tail = NULL;
    }
    int front()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        return tail->data;
    }
};