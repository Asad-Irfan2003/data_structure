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
/*
Problem: Given a string of parathesis, return true if it is valid(All opening paranthsis have a closing paranthesis)
Example 1: (()) (Valid)
Example 2: (() (Invalid)
Example 3: ))) (Invalid)

Algorithm:
1. Traverse the string
2. For each opening bracket, push the opening bracket
3. For each closing bracket, pop the opening bracket(If there is no opening bracket left, there are more closing brackets return false)
4. If there is any opening bracket left in the stack, return false because there are more opening bracket else return true
*/
bool valid_paranthesis(string str){
    stack<char> s;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(')
        s.push(str[i]);
        else if(str[i]==')')
        {
            if(s.is_empty()==true)
            return false;
            s.pop();
        }
    }
    if(s.is_empty()==false)
    return false;
    else return true;

}


int main(){

}