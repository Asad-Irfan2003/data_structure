#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(NULL) {}
    Node(int d) : data(d), next(NULL) {}
};
class linked_list
{
    Node *head;

public:
    linked_list() : head(NULL) {}
    void add_to_start(int data)
    {
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
    void add_to_end(int data)
    {
        Node *new_node = new Node(data);
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    void add_to_middle(int data, int index)
    {
        if (index > size())
        {
            return;
        }
        if (index == 0)
        {
            add_to_start(data);
            return;
        }
        Node *new_node = new Node(data);
        Node *temp = head;
        int i = 1;
        while (i < index)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void delete_at_start()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void delete_at_end()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head->next;
        Node *prev = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            prev = prev->next;
        }
        prev->next = temp->next;
        delete temp;
    }
    void delete_at_middle(int index)
    {
        if (index >= size())
            return;
        if (index == 0)
        {
            delete_at_start();
            return;
        }
        int i = 1;
        Node *temp = head->next;
        Node *prev = head;
        while (i<index)
        {
            temp = temp->next;
            prev = prev->next;
            i++;
        }
        prev->next = temp->next;
        delete temp;
    }
    int size()
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
};

int main()
{
    linked_list l;
    l.add_to_start(1);
    l.add_to_start(2);
    l.add_to_start(3);
    l.print();
    l.add_to_end(4);
    l.add_to_end(5);
    l.print();
    l.add_to_middle(6, 0);
    l.add_to_middle(7, 5);
    l.print();
    l.delete_at_start();
    l.print();
    l.delete_at_end();
    l.print();
    l.delete_at_middle(0);
    l.print();
    l.delete_at_middle(3);
    l.print();
    l.delete_at_middle(1);
    l.print();
}
