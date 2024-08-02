#include <iostream>
using namespace std;

/*Stack ADT*/
template <typename T>
struct SNode
{
    T data;
    SNode<T> *next;
    SNode() : data(0), next(NULL) {}
    SNode(T data) : data(data), next(NULL) {}
};
template <typename T>
class stack
{
    SNode<T> *top;

public:
    stack() : top(NULL) {}
    bool is_empty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    void push(T data)
    {
        SNode<T> *new_node = new SNode<T>(data);
        new_node->next = top;
        top = new_node;
    }
    void pop()
    {
        if (is_empty() == true)
        {
            throw "Stack Underflow";
        }
        SNode<T> *temp = top;
        top = top->next;
        delete temp;
    }
    int peek()
    {
        if (is_empty() == true)
            throw "Stack Underflow";
        return top->data;
    }
};

/*Queue ADT*/
template <typename T>
struct QNode
{
    T data;
    QNode<T> *next;
    QNode() : data(0), next(NULL) {}
    QNode(T val) : data(val), next(NULL) {}
};
template <typename T>
class queue
{
    QNode<T> *head;
    QNode<T> *tail;

public:
    queue() : head(NULL), tail(NULL) {}
    bool is_empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    void enqueue(T data)
    {
        QNode<T> *new_node = new QNode<T>(data);
        if (is_empty() == true)
        {
            tail = new_node;
            head = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }
    void dequeue()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        QNode<T> *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
            tail = NULL;
    }
    T front()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        return head->data;
    }
    T rear()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        return tail->data;
    }
};
/*
Problem:
Given a queue, reverse all the elements in the queue
*/

/*
Algorithm(Iterative method):
1. dequeue all the elements from queue and push to stack stack until queue is empty
2. pop all elements from stack and enqueue them into queue
*/

void reverse_queue(queue<int> &q)
{
    stack<int> s;
    while (q.is_empty() == false)
    {
        s.push(q.front());
        q.dequeue();
    }
    while (s.is_empty() == false)
    {
        q.enqueue(s.peek());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    for (int i = 0; i < 10; i++)
    {
        q.enqueue(i);
    }
    reverse_queue(q);
    for (int i = 0; i < 10; i++)
    {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;
}