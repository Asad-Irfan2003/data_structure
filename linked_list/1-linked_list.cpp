#include <iostream>
using namespace std;

//Basic structure of node
/*
Linked List:
    ->Linear Data Structure
    ->Elemenets are not stored in contiguous location
    ->Elements are linked using pointers
    ->It is a series of connected nodes, where each node stores
      data and address of next node

Uses of Linked List:
    ->Size of memory used can be allocated or de-allocated at runtime
    ->Insertion and deletion of elements is faster as no shifting is required
    ->Efficient in memory usage since size can be increased/decreased as per requirement
    ->Used to implement stack, queues, graph, hashmaps etc

Disadvantages:
    ->Random access is not possible, traversal is required to access a specific node
    ->They require extra memory for storing pointers unlike arrays

*/
template<typename T>
struct node
{
    T data; //To store data
    node<T> *next; //To store address of next node
};
template <typename T>
void traverse(node<T>* head){
    while(head!=NULL){
        cout<<head->data<<"";
        head=head->next;
    }
    cout<<endl;

}

int main()
{
    node<int> *head = new node<int>;
    head->data = 1;
    node<int> *second = new node<int>;
    second->data = 2;
    node<int> *third = new node<int>;
    third->data = 3;
    head->next = second;
    second->next = third;
    third->next = NULL;
    traverse(head);
}
