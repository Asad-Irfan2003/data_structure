#include <iostream>
using namespace std;

void bubble_sort(int *arr, int size)
{
    bool swapped;
    do {
        swapped=false;
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1])
            {
                swapped=true;
                swap(arr[j],arr[j+1]);
            }
        }

    }while(swapped);
}
void swap(int &val1, int &val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int size = 5;
    bubble_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
