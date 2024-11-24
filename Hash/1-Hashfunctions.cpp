#include <iostream>
#include <cmath>
#include <string>
using namespace std;
/*
*/
// ============================================================
// FOLDING HASH FUNCTION
// The folding hash function divides the key into equal-sized parts, 
// adds them together, and returns the sum modulo the table size.
// ============================================================

int foldingHash(int key, int tableSize) {
    int sum = 0;
    
    // Loop to break the key into smaller 3-digit chunks
    while (key > 0) {
        sum += key % 1000;  // Take last 3 digits of key
        key /= 1000;         // Remove last 3 digits
    }

    // Return sum modulo table size
    return sum % tableSize;
}

// ============================================================
// DIVISION HASH FUNCTION
// The division method computes the remainder when the key is 
// divided by the table size, and uses the remainder as the hash value.
// ============================================================

int divisionHash(int key, int tableSize) {
    return key % tableSize;  // Simple division hash: remainder after dividing by table size
}

// ============================================================
// MULTIPLICATION HASH FUNCTION
// The multiplication method multiplies the key by a constant 
// (usually a fraction of the golden ratio), extracts the fractional part,
// and multiplies it by the table size to get the hash value.
// ============================================================

int multiplicationHash(int key, int tableSize) {
    const double A = 0.6180339887;  // Golden ratio fraction (A ≈ 0.6180339887)
    
    // Multiply the key by A, and extract the fractional part
    double temp = key * A;
    
    // Multiply the fractional part by table size and return the integer part
    return static_cast<int>(tableSize * (temp - floor(temp)));
}

// ============================================================
// MIN SQUARE HASH FUNCTION
// The min square method squares the key, extracts the middle part 
// of the squared value, and returns the result modulo the table size.
// ============================================================

int minSquareHash(int key, int tableSize) {
    long long squared = (long long)key * key;  // Square the key
    
    // Convert the squared number to string to easily extract middle digits
    string squaredStr = to_string(squared);
    
    // Find the middle part of the string representation of the squared number
    int midStart = squaredStr.length() / 4;        // Start of middle part
    int midEnd = midStart + squaredStr.length() / 2;  // End of middle part
    
    // Extract the middle digits as a substring
    string middle = squaredStr.substr(midStart, midEnd - midStart);
    
    // Convert the middle part back to an integer and apply modulo
    int middleInt = stoi(middle);
    return middleInt % tableSize;
}

// ============================================================
// MAIN FUNCTION FOR DEMONSTRATION
// This function demonstrates the use of each hash function.
// ============================================================

int main() {
    // Sample key and table size for testing the hash functions
    int key = 123456;
    int tableSize = 10;
    
    // Test Folding Hash
    cout << "Folding Hash: " << foldingHash(key, tableSize) << endl;
    
    // Test Division Hash
    cout << "Division Hash: " << divisionHash(key, tableSize) << endl;
    
    // Test Multiplication Hash
    cout << "Multiplication Hash: " << multiplicationHash(key, tableSize) << endl;
    
    // Test Min Square Hash
    cout << "Min Square Hash: " << minSquareHash(key, tableSize) << endl;
    
    return 0;
}
