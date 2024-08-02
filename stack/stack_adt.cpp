#include <iostream>
using namespace std;
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
            throw runtime_error("stack Underflow");
        }
        SNode<T> *temp = top;
        top = top->next;
        delete temp;
    }
    int peek()
    {
        if (is_empty() == true)
            throw runtime_error("stack Underflow");
        return top->data;
    }
};
