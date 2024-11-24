#include <iostream>
#include <cmath>

using namespace std;

// Define a simple HashTable class
class HashTable {
private:
    int* table;           // Pointer to dynamically allocated array for hash table
    int tableSize;

public:
    // Constructor to initialize the table size and the table itself
    HashTable(int size) {
        tableSize = size;
        table = new int[tableSize];  // Dynamically allocate memory for table
        for (int i = 0; i < tableSize; i++) {
            table[i] = -1;  // Initialize all entries to -1 (empty)
        }
    }

    // Destructor to free the dynamically allocated memory
    ~HashTable() {
        delete[] table;  // Free the dynamically allocated memory
    }

    // Hash function: Simple division method
    int hash(int key) {
        return key % tableSize;  // Return the index based on key % tableSize
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hash(key);
        
        // If the slot is already filled, just replace the existing value
        // This simple version does not handle collisions, so no checking
        // for collisions or chaining is done.
        if (table[index] == -1) {  // If the spot is empty, insert the key
            table[index] = key;
        } else {
            cout << "Collision detected for key " << key << " at index " << index << endl;
        }
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hash(key);

        // If the key at the computed index is the same as the searched key
        if (table[index] == key) {
            return true;  // Key found
        }

        return false;  // Key not found
    }

    // Delete a key from the hash table
    void deleteKey(int key) {
        int index = hash(key);

        // Check if the key is present at the calculated index
        if (table[index] == key) {
            table[index] = -1;  // Set to -1 to mark it as empty
            cout << "Key " << key << " deleted successfully." << endl;
        } else {
            cout << "Key " << key << " not found." << endl;
        }
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i] != -1) {  // -1 means empty slot
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    // Create a hash table of size 10
    HashTable ht(10);

    // Insert some keys
    ht.insert(23);
    ht.insert(33);
    ht.insert(43);
    ht.insert(53);

    // Display the hash table
    cout << "Hash Table after insertion:" << endl;
    ht.display();

    // Search for keys
    cout << "Searching for 33: " << (ht.search(33) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    // Delete a key
    ht.deleteKey(33);
    ht.deleteKey(99);

    // Display the hash table after deletion
    cout << "Hash Table after deletion:" << endl;
    ht.display();

    return 0;
}
