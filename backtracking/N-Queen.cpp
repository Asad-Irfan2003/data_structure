#include <iostream>
using namespace std;

//Case 1:No conflicts
/*
if row==n the algorithm is completed
store col value in row array
go to next row
*/

void print_board(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == j)
                cout << "Q";
            else
                cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

// Returns true if No queen can attack on the row and col passed
//formula for checking diagonals
//Let (i,j) and (k,l) represent two positions
//If they belong in same diagonal then abs(i-k)=abs(j-l)
bool is_safe(int *arr,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if((arr[i]==col)||(abs(i-row)==abs(arr[i]-col)))
        return false;
    }
    return true;
}

bool solve_problem(int *arr,int n,int row)
{
    //Base case
    if(row==n)//All Queen placements done
    {
        print_board(arr,n);
        return true; //Indicates no more backtracking required
    }
    for(int col=0;col<n;col++){
        if(is_safe(arr,row,col)==true)
        {
            arr[row]=col;
            if(solve_problem(arr,n,row+1))
            return true;
            arr[row]=-1;
        }
    }
    //Case 1: no conflict -> place queen in the row and column and move to next column
    //Case 2: Conflict and we can move to next column -> check queen for next column
    //Case 3: Conlict and no more columns to move forward -> Move to previous row
    return false;

}
void n_queen(int n)
{
    int *arr=new int[n]; //array for queen placement
    //index -> row
    //Value at index -> column
    //arr[2]=3  2nd row and 3rd column
    //Initialize array with -1 to show queen has not been placed
    for(int i=0;i<n;i++)
    {
        arr[i]=-1;
    }
    if(!solve_problem(arr,n,0)) //returns a solution
    cout<<"No solution found"<<endl;

}

int main()
{
    n_queen(3);
}

/*[][][]...[]
  [][][]...[]
  ...
  [][][]...[]
  N rows and N columns
  conflict -> When two queens can attack each other
  Queen movements- same row, same column and same diagonal
*/
