#include <iostream>
using namespace std;

void insertion_sort(int *arr, int size)
{

    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    insertion_sort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
