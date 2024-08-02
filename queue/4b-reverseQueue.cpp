#include <iostream>
using namespace std;
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
Algorithm(for recursive approach):
1. Dequeue an element from queue and store it in a temp variable
2. Recursively call the function
3. Enqueue the element back
*/
void reverse_queue(queue<int> &q)
{
    if (q.is_empty() == true)
        return;
    int fr = q.front();
    q.dequeue();
    reverse_queue(q);
    q.enqueue(fr);
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
}