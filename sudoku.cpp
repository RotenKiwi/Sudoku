#include <iostream>
using namespace std;

int sudoku[9][9]={
    {0,1,0,0,7,6,0,0,0},
    {0,0,5,3,9,0,0,0,2},
    {0,0,0,2,0,5,0,6,0},
    {1,0,3,0,0,0,6,4,0},
    {6,4,0,0,0,0,0,5,9},
    {0,2,9,0,0,0,8,0,1},
    {0,9,0,1,0,7,0,0,0},
    {2,0,0,0,4,9,1,0,0},
    {0,0,0,5,2,0,0,9,0}
};

bool InCol(int col, int n){
    for(int row=0; row<9;row++)
        if(sudoku[row][col]==n)
            return true;
        return false;}
        
bool InRow(int row, int n){
    for(int col=0; col<9; col++)
        if(sudoku[row][col]==n)
            return true;
        return false;}

bool InBox(int fRow,int fCol, int n){
    for(int row=0; row<3; row++)
        for(int col=0; col<3; col++)
            if(sudoku[row+fRow][col+fCol]==n)
                return true;
    return false;}

void printAns(){
    for (int row = 0; row < 9; row++){
      for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << sudoku[row][col] <<" ";}
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<9; i++)
            cout << "---";}
      cout << endl;}}

bool Empty(int &row, int &col){ 
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (sudoku[row][col] == 0) 
            return true;
   return false;}

bool isNum(int row, int col, int n){
    return !InRow(row, n) && !InCol(col, n) && !InBox(row-row%3, col-col%3, n);}

bool solve(){
    int row, col;
    if(!Empty(row, col))
        return true;
    for(int n=1; n<10; n++){
        if(isNum(row, col, n)){
            sudoku[row][col]=n;
        if(solve())
        return true;
        sudoku[row][col]=0;}}
    return false;}

int main(){
    if(solve()==true)
    printAns();
    else
    cout<<"No Solution Exists";
}
