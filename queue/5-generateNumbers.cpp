#include <iostream>
#include <vector>
using namespace std;
template <typename T>
struct QNode
{
    T data;
    QNode<T> *next;
    QNode() : data(0), next(NULL) {}
    QNode(T val) : data(val), next(NULL) {}
};
template <typename T>
class queue
{
    QNode<T> *head;
    QNode<T> *tail;

public:
    queue() : head(NULL), tail(NULL) {}
    bool is_empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    void enqueue(T data)
    {
        QNode<T> *new_node = new QNode<T>(data);
        if (is_empty() == true)
        {
            tail = new_node;
            head = new_node;
            return;
        }
        tail->next = new_node;
        tail = new_node;
    }
    void dequeue()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        QNode<T> *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
            tail = NULL;
    }
    T front()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        return head->data;
    }
    T rear()
    {
        if (is_empty() == true)
            throw runtime_error("queue underflow");
        return tail->data;
    }
};

vector<int> generate_number(int* digits,int size,int N){
    int num=size;
    vector<int> sol;
    queue<int> q;
    //Push all digits into queue and solution vector
    for(int i=0;i<size;i++){
        q.enqueue(digits[i]);
        sol.push_back(digits[i]);
    }
    //Dequeue each element
    //Add each number as a digit in that number, creating a new number
    //Add that number to queue and solution array
    // Do that until the numbers generated are equal to number required
    while(num<N){
        int temp=q.front();
        q.dequeue();
        for(int i=0;i<size;i++){
            int new_num=(temp*10)+digits[i];
            q.enqueue(new_num);
            sol.push_back(new_num);
            num++;
            if(num==N)
            break;
        }
    }  
    //Add remaining numbers in queue to array and return
    while(q.is_empty()==false){
        sol.push_back(q.front());
        q.dequeue();
    }
    return sol;

}
int main(){
    int arr[4]={2,3,7,9};
    int size=4;
    int N=50;
    vector<int> sol=generate_number(arr,size,N);
    for(int i=0;i<sol.size();i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
}
