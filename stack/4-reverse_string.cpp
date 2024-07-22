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
// Problem: Given a string , return the string in reverse
/*
Sample input: "Zoha"
Sample output: "ahoZ"
*/
// Approach 1: Sliding window approach
string reverse_str(string str)
{
    string new_str;
    for (int i = str.length(); i >= 0; i--)
    {
        new_str += str[i];
    }
    return new_str;
}

// Approach 2: Stack Approach
/*
1. Push the string into the stack (Character by character)
2. Pop the stack and concatenate each top element with a new string
*/
string reverse_str_stack(string str)
{
    stack<char> s;
    // Push the string into the stack
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    str = "";
    // Pop the stack and concatenate each top element with new string
    while (s.is_empty() == false)
    {
        str += s.peek();
        s.pop();
    }
    return str;
}

int main()
{
    string str = "Zoha";
    string rev_str = reverse_str_stack(str);
    cout << rev_str << endl;
}
