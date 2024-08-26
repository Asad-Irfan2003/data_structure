/*
Creating jagged array dynamically
1. Create two variables
    a) rows, to store number of rows in array
    b) sizes array to store size of each row
2. Create an array of pointers of size row
3. For each row, create a jagged array with the size of each row in the sizes array

*/
#include <iostream>
using namespace std;
#define N 3
int main()
{
    int row = N;
    int sizes[N] = {2, 3, 4};
    int **arr = new int *[N];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[sizes[i]];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}