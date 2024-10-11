#include <iostream>
using namespace std;


int partition(int *arr,int l,int r)
{
    int pivot=arr[r];
    int index=l-1;
    for(int i=l;i<r;i++)
    {
        if(arr[i]<pivot)
        {
            index++;
            swap(arr[i],arr[index]);
        }
    }
    swap(arr[index+1],arr[r]);
    return index+1;
}

void quick_sort(int *arr,int l,int r)
{
    if(l>=r)
    return;
    int pivotIndex=partition(arr,l,r);
    quick_sort(arr,l,pivotIndex-1);
    quick_sort(arr,pivotIndex+1,r);
}
int main()
{
    int arr[5]={5,4,3,2,1};
    quick_sort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
}
