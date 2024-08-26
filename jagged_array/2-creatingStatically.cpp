/*
Creating jagged array statically
1. Create 'N' 1D arrays for each row of the jagged array
2. Create an array of pointers with each index pointing to the 1D arrays previously created
*/
#include <iostream>
using namespace std;
int main(){
    //1. Create N 1D array for each row of jagged array
    int row1[2]={1,2};
    int row2[3]={3,4,5};
    int row3[4]={6,7,8,9};
    int sizes[3]={2,3,4}; //This is used to keep track for each row size( Useful for traversal )
    //2. Create an array of pointers with each index pointing to 1D array previously created
    int* arr[3]={row1,row2,row3};
    for (int i=0;i<3;i++){
        for (int j=0;j<sizes[i];j++){
            cout<<arr[i][j]<<" ";
        }
    }

}