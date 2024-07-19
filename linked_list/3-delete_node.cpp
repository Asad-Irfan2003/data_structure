#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node():data(0),next(NULL){}
    Node(int val):data(val),next(NULL){}
};
int size(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
/*
Deleting first node
Algorithm:
1. Store the address of first node to a temp pointer
2. Move the head forward by 1
3. delete the node pointed by head
*/
void delete_at_start(Node*(&head)){
    if(head==NULL) //Linked List is empty
    return;
    Node* temp=head;
    head=head->next;
    delete temp;
}
/*
Deleting last node
Algorithm:
1. Use two pointers: One to point at last node and one to point at node before last node
2. Traverse both pointers until they point to last node and seconf last node
3. Point next to previous node to next of last node
4. Delete last node
*/

void delete_at_end(Node*(&head)){
    if(head==NULL){ //Linked List is empty
        return;
    }
    if(head->next==NULL){ //If there is only one node to delete
        delete head;
        head=NULL;
        return;
    }
    Node* temp=head->next; //This will point to last node
    Node* prev=head; //This will point to second last node
    while(temp->next!=NULL){
        temp=temp->next;
        prev=prev->next;
    }
    prev->next=temp->next; //Point second last node to next of last node
    delete temp; //Delete the last node
}
void delete_at_middle(int index,Node*(&head)){
    if(index>=size(head)){ //Index is out of bounds
        return;
    }
    if(index==0){ //Delete the first node
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    //Delete the middle node
    Node* temp=head->next; //This will point at node to delete
    Node* prev=head; //The will point at node before node to delete
    int i=1;
    while(i<index){
        temp=temp->next;
        prev=prev->next;
        i++;
    }
    prev->next=temp->next;
    delete temp;

}


void add_to_start(Node*(&head),int data){
    Node* new_node=new Node(data);
    new_node->next=head;
    head=new_node;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head=NULL;
    add_to_start(head,10);
    add_to_start(head,20);
    add_to_start(head,30);
    print(head);
    delete_at_end(head); //10 Deleted
    print(head);
    delete_at_end(head); //20 Deleted
    print(head);
    delete_at_end(head); //30 Deleted
    print(head);
    cout<<endl;
    add_to_start(head,1);
    add_to_start(head,2);
    add_to_start(head,3);
    add_to_start(head,4);
    add_to_start(head,5);
    print(head);
    delete_at_middle(1,head);
    print(head);
    delete_at_middle(0,head);
    print(head);
    delete_at_middle(2,head);
    print(head);
}
