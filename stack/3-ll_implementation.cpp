#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
};
/*
Linked List implementation:
    ->Top is Head
    ->Push is add_to_start
    ->Pop is delete_from_start
    ->If stack is empty, linked list is empty(top==NULL)

*/
class stack
{
    Node *top;

public:
    stack() : top(NULL) {}

    // In Linked List Approach,if top is NULL, stack is empty(return true)
    bool is_empty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    // In linked list approach, pushing to stack is same as adding to start in linked list
    void push(int data)
    {
        Node *new_node = new Node(data);
        new_node->next = top;
        top = new_node;
    }
    // in Linked List approach, popping from stack is same as removing first element from linked list
    void pop()
    {
        if (is_empty() == true)
        {
            throw "Stack Underflow";
        }
        Node *temp = top;
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

int main()
{
    stack s;
    for (int i = 0; i < 100; i++)
        s.push(i);

    for (int i = 0; i < 100; i++)
    {
        cout << s.peek() << " ";
        s.pop();
    }
}