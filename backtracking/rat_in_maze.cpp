#include <iostream>
using namespace std;
#define N 4
void print_matrix(int sol[N][N], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool is_safe(int Mat[N][N], int posX, int posY)
{
    return ((posX < N) && (posY < N) && Mat[posX][posY] != 0);
}

void find_sol(int Mat[N][N], int sol[N][N], int desX,int desY,int posX=0,int posY=0){
    sol[posX][posY] = 1;
    if (posX == desX && posY == desY)
    {
        print_matrix(sol, N, N);
        return;
    }
    if(is_safe(Mat,posX+1,posY))
    {
        find_sol(Mat,sol,posX+1,posY,desX,desY);
        sol[posX+1][posY]=0;
    }
    if(is_safe(Mat,posX,posY+1))
    {
        find_sol(Mat,sol,posX,posY+1,desX,desY);
        sol[posX][posY+1]=0;
    }
}

void rat_in_maze(int Mat[N][N])
{
    int sol[N][N] = {};
    int desX = N - 1;
    int desY = N - 1;
    find_sol(Mat,sol,desX,desY);
}
int main()
{
    int Mat[N][N] = {
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 1, 1, 1}};
    rat_in_maze(Mat);
}
