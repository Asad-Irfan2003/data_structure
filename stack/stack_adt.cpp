#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node() : data(0), next(NULL) {}
    Node(T data) : data(data), next(NULL) {}
};
template <typename T>
class stack
{
    Node<T> *top;

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
        Node<T> *new_node = new Node<T>(data);
        new_node->next = top;
        top = new_node;
    }
    void pop()
    {
        if (is_empty() == true)
        {
            throw "Stack Underflow";
        }
        Node<T> *temp = top;
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