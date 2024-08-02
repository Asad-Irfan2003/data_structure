#include <iostream>
using namespace std;

// Array implementation problem
//->Front or rear reaches end of array
// Solution: Increase front in circular manner
// front=(front+1)%capacity
// rear=(rear+1)%capacity
class queue
{
    int *arr;     // Array to hold elements in queue
    int head;     // Points to first element
    int tail;     // Points to last element
    int capacity; // Stores maximum size of queue
    int size;     // Number of elements currently in queue
public:
    queue(int cap) : arr(new int[cap]), capacity(capacity), head(0), tail(-1), size(0) {}

    /*
    is_full()
    Algorithm:
        ->Return true if size==capacity
        ->else return falase
    */
    bool is_full()
    {
        if (size == capacity)
            return true;
        else
            return false;
    }

    /*
    is_empty()
    Algorithm:
        ->Return true if size=0
        ->else return false
    */
    bool is_empty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    /*
    enqueue()
    Algorithm:
        ->Check if queue is full
        ->If full throw queue overflow exception
        ->Increment rear by 1
        ->Add data
    */
    void enqueue(int data)
    {
        if (is_full() == true)
            throw runtime_error("queue overflow");
        tail = (tail + 1) % capacity;
        arr[tail] = data;
    }
    /*
    dequeue()
    Algorithm:
     ->Check if queue is empty
     ->If empty throw underflow exception
     ->Increment front by 1
    */
    void dequeue()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        head = (head + 1) % capacity;
    }
    /*front()
    Algorithm:
        ->Check if queue is empty
        ->If empty throw underflow exception
        ->Else return arr[head]
    */
    int front()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        return arr[head];
    }
    /*
    rear()
    Algorithm:
         ->Check if queue is empty
         ->If empty throw queue underflow exception
         ->Else return arr[tail]
    */
    int rear()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        return arr[tail];
    }
};