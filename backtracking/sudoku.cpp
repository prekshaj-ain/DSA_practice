#include<iostream>
using namespace std;
bool isSafe(int** a,int size,int row,int col,int num){
    // to check is the num is already present in that column
    for(int i=0;i<size;i++){
        if(a[i][col] == num){
            return false;
        }
    }
    // to check is the num is already present in that row
    for(int i=0;i<size;i++){
        if(a[row][i] == num){
            return false;
        }
    }
    // check id num is present in 3x3 matrix
    int startRow = row - row%3;
    int startCol = col - col%3;
    for(int i=0;i<3;i++){
        for(int j =0;j<3;j++){
            if(a[startRow + i][startCol +j] == num )
            {
                return false;
            }
        }
    }
    return true;

}
bool sudoku(int **grid){
    int row = -1;
    int col = -1;
    bool isEmpty = true;
    //find what is the first place which is assigned to 0(empty)
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]== 0){
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if(!isEmpty){
            break;
        }
    }
    //no empty spaces left
    if(isEmpty){
        return true;
    }
    for(int num=1;num<=9;num++){
        if(isSafe(grid,9,row,col,num)){
            grid[row][col] = num;
            if(sudoku(grid)){
                return true;
            }
            grid[row][col] = 0;

        }
    }
    return false;
}

int main(){
    int** arr = new int*[9];
    for(int i=0;i<9;i++){
        arr[i] = new int[9]; 
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >>arr[i][j];
        }
    }
    if(sudoku(arr))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
