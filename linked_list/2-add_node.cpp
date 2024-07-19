#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(NULL) {}
    Node(int d) : data(d), next(NULL) {}
};
/*
Algorithm to add to start:
1. Create a new node
2. point the next of new node to head
3. point the head to new node
*/
void add_to_start(Node *(&head), int data) //Time Complexity: O(1)
{
    Node*n=new Node(data);
    n->next=head;
    head=n;
}
/*
Algorithm:
1.Create a new node
2. Traverse to end last node
3. Point the next of new node to next of last node
4. Point the next of last node to new node
*/
void add_to_end(Node* (&head),int data){
    Node* new_node= new Node;
    new_node->data=data;
    //Edge case: If head is NULL(Linked list is empty), new_node is head
    if(head==NULL){
        head=new_node;
        return;
    }
    Node* temp=head;
    //Traversing to last node
    while(temp->next!=NULL){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;


}

void print_list(Node *head)
{
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }

}
/*
Algorithm:
1. Create a new node
2. Check if the index provided by user is not greater than or equal to size of linked list(if it is out of bounds, return)
3. Create a temp variable and traverse the linked list until we reach index given by user
4. Point next of new node to next of previous node
5. Point next of previous to new node
*/
void add_to_middle(int data,int index,Node*(&head)){
    Node* new_node=new Node(data);
    Node* temp=head;
    int i;
    if(index>=size(head)){
        delete new_node;
        return;
    }
    while(i<index){
        temp=temp->next;
        i++;
    }
    new_node->next=temp->next;
    temp->next=new_node;

}
int size(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

int main()
{
    Node *head = NULL;
    int choice;
    while (choice != 0)
    {
        cout << "Enter your choice" << endl;
        cout << "1. Print list" << endl;
        cout << "2. Add to start" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            print_list(head);
            break;
        case 2:
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            add_to_start(head, data);
            break;
        }
        case 3:
        {
            int data;
            cout<<"Enter data: ";
            cin>>data;
            add_to_end(head,data);
            break;
        }
        }
    }
}