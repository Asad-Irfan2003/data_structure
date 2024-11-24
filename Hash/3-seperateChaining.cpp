#include <iostream>
#include <stdexcept>
using namespace std;

#define HASHTABLE_SIZE 10

// Node structure for linked list (used for handling collisions)
struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

// HashTable ADT
class HashTable {
private:
    Node** table;

    // Hash function: simple modulus-based hashing for integers
    int hash(int key) {
        return key % HASHTABLE_SIZE;
    }

    // Insert a key into the linked list (handles collisions)
    void insert(Node*& head, int key) {
        Node* new_node = new Node(key);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    // Delete a key by value from the linked list
    void delete_by_val(Node*& head, int key) {
        if (head == nullptr) {
            throw runtime_error("Linked list is empty");
        }
        if (head->key == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = head;
        Node* temp = head->next;
        while (temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            throw runtime_error("Key not found in linked list");
        }
        prev->next = temp->next;
        delete temp;
    }

public:
    // Constructor: Initialize the hash table
    HashTable() {
        table = new Node*[HASHTABLE_SIZE];
        for (int i = 0; i < HASHTABLE_SIZE; i++) {
            table[i] = nullptr;  // Initialize all slots to nullptr (empty)
        }
    }

    // Destructor: Free memory used by the hash table
    ~HashTable() {
        for (int i = 0; i < HASHTABLE_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insert a key into the hash table
    void insert(int key) {
        int hashIndex = hash(key);
        insert(table[hashIndex], key);
    }

    // Remove a key from the hash table
    void remove(int key) {
        int hashIndex = hash(key);
        try {
            delete_by_val(table[hashIndex], key);
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    // Print the hash table (for debugging/visualization)
    void print() const {
        for (int i = 0; i < HASHTABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;

    // Insert some keys into the hash table
    int keys[] = {22, 28, 1, 26, 13, 5, 17, 10, 3};
    for (int key : keys) {
        ht.insert(key);
    }

    // Print the hash table after insertion
    cout << "Hash Table after insertion:" << endl;
    ht.print();

    // Remove a few keys from the hash table
    cout << "\nRemoving key 22:" << endl;
    ht.remove(22);

    cout << "\nRemoving key 1:" << endl;
    ht.remove(1);

    // Print the hash table after deletion
    cout << "\nHash Table after deletion:" << endl;
    ht.print();

    return 0;
}
