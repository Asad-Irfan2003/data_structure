#include <iostream>
using namespace std;

/*
->A dynamically allocated array will be used for implementation
->We will use two variables, one to store the size and one to store the index of top element in stack
*/
class stack
{
    int *arr;
    int top;  // This will store the index of top element of stack(Initially top is -1 to show stack is empty)
    int size; // This will be max size of stack

    public:
    // Default constructor for stack
    stack(int size) : arr(new int[size]), top(-1), size(size) {}

    /*
    Algorithm for is_full(Array)
    1. If value of top is equal to size then return true(indicating stack is full)
    2. else return false
    */
    bool is_full()
    {
        if (top == size)
            return true;
        else
            return false;
    }

    /*
    Algorithm for is_empty(Array)
    1. If value of top is -1 then return true(Top value is -1 when stack is empty)
    2. Else return false
    */
    bool is_empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    /*Algorithm for Push(Array)
    1. Check if stack is not full(If full then print stack overflow error)
    2. Increment top by 1
    3. Add the data to array with top as index
    */
    void push(int data)
    {
        if (is_full() == true)
        {
            //Stack is full
            throw "Stack Overflow";

        }
        top++; //Increment top by 1
        arr[top]=data; //Add data to array with top as index
    }

    /*
    Algorithm for pop(Array)
    1. Check if stack is not empty(If empty then print stack underflow error)
    2. Decrement top by 1
    */
    void pop(){
        if(is_empty()==true){
            //Stack is empty
            throw "Stack Underflow";
        }
        top--;
    }
    /*
    Algorithm for accessing top element of stack(Top or Peek)
    1. Check if stack is not empty(If empty print stack underflow error)
    2. Return the value of array with top as index
    */
    int peek(){
        if(is_empty()==true){
            //Stack is empty
            throw "Stack Underflow";
        }
        return arr[top];
    }
};

int main(){
    stack s(100);
    //Pushing 1 to 100 in stack and printing all the elements in it from top to bottom
    for(int i=0;i<100;i++){
        s.push(i);
    }
    for(int i=0;i<100;i++){
        cout<<s.peek()<<" ";
        s.pop();
    }
}