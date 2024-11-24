#include <iostream>
#include <stdexcept>
using namespace std;

#define HASHTABLE_SIZE 10

// HashTable ADT with Open Addressing and all three probing methods
class HashTable {
private:
    int* table;
    bool* deleted;  // To track deleted elements for reuse in open addressing
    int count;       // Number of elements in the hash table

    // Primary hash function
    int hash(int key) {
        return key % HASHTABLE_SIZE;
    }

    // Linear Probing: Check next slot sequentially
    int linear_probe(int key, int i) {
        return (hash(key) + i) % HASHTABLE_SIZE;
    }

    // Quadratic Probing: Check next slot with a quadratic function
    int quadratic_probe(int key, int i) {
        return (hash(key) + i * i) % HASHTABLE_SIZE;
    }

    // Double Hashing: Use a second hash function to determine step size
    int double_hash(int key, int i) {
        int hash2 = 1 + (key % (HASHTABLE_SIZE - 1));  // Second hash function
        return (hash(key) + i * hash2) % HASHTABLE_SIZE;
    }

public:
    // Constructor: Initialize the hash table
    HashTable() {
        table = new int[HASHTABLE_SIZE];
        deleted = new bool[HASHTABLE_SIZE];
        count = 0;

        // Initialize all table slots to -1 (indicating empty) and deleted flags to false
        for (int i = 0; i < HASHTABLE_SIZE; i++) {
            table[i] = -1;
            deleted[i] = false;
        }
    }

    // Destructor: Free memory used by the hash table
    ~HashTable() {
        delete[] table;
        delete[] deleted;
    }

    // Insert a key into the hash table using the specified probing method
    void insert(int key, int probe_type = 0) {
        if (count == HASHTABLE_SIZE) {
            throw runtime_error("Hash Table is full");
        }

        int i = 0;
        int idx;
        while (i < HASHTABLE_SIZE) {
            if (probe_type == 0) {
                idx = linear_probe(key, i);
            } else if (probe_type == 1) {
                idx = quadratic_probe(key, i);
            } else if (probe_type == 2) {
                idx = double_hash(key, i);
            } else {
                throw runtime_error("Invalid probe type");
            }

            // If slot is empty or previously deleted, insert the key
            if (table[idx] == -1 || deleted[idx]) {
                table[idx] = key;
                deleted[idx] = false;
                count++;
                return;
            }

            i++;
        }

        throw runtime_error("Unable to insert, table is full");
    }

    // Remove a key from the hash table
    void remove(int key) {
        int i = 0;
        int idx;
        while (i < HASHTABLE_SIZE) {
            idx = hash(key) + i;  // Start with the primary hash function
            idx %= HASHTABLE_SIZE;

            if (table[idx] == key) {
                table[idx] = -1;
                deleted[idx] = true;
                count--;
                return;
            }

            if (table[idx] == -1) {  // Key not found
                throw runtime_error("Key not found in hash table");
            }

            i++;
        }
        throw runtime_error("Unable to delete, key not found");
    }

    // Search for a key in the hash table
    bool search(int key) {
        int i = 0;
        int idx;
        while (i < HASHTABLE_SIZE) {
            idx = hash(key) + i;  // Start with the primary hash function
            idx %= HASHTABLE_SIZE;

            if (table[idx] == key) {
                return true;  // Found the key
            }

            if (table[idx] == -1) {  // Key not found
                return false;
            }

            i++;
        }
        return false;
    }

    // Print the hash table
    void print() const {
        for (int i = 0; i < HASHTABLE_SIZE; i++) {
            if (table[i] == -1) {
                cout << "Index " << i << ": EMPTY" << endl;
            } else {
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable ht;

    // Insert some keys using different probing techniques
    ht.insert(22, 0); // Linear Probing
    ht.insert(28, 1); // Quadratic Probing
    ht.insert(1, 2);  // Double Hashing
    ht.insert(26, 0); // Linear Probing
    ht.insert(13, 1); // Quadratic Probing
    ht.insert(5, 2);  // Double Hashing

    // Print the hash table after insertions
    cout << "Hash Table after insertions:" << endl;
    ht.print();

    // Search for some keys
    cout << "\nSearching for 28: " << (ht.search(28) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (ht.search(100) ? "Found" : "Not Found") << endl;

    // Remove a key
    cout << "\nRemoving key 28:" << endl;
    ht.remove(28);

    // Print the hash table after deletion
    cout << "\nHash Table after deletion:" << endl;
    ht.print();

    return 0;
}
