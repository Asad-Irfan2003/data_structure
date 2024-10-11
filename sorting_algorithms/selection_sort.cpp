#include <iostream>
using namespace std;

void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                swap(min, arr[j]);
            }
        }
        arr[i] = min;
    }
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
    selection_sort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}
