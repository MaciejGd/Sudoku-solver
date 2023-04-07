#include<iostream>
#include<string>
#include"sudoku.hpp"

using namespace std;

bool possible(int y,int x, int n, int board[9][9]);
bool solve(int (&board)[9][9]);
void print_board(int board[9][9]);
void opening_example_from_file(int (&board)[9][9]);
void uzupelnij(int (&board)[9][9]);

int main(){

    //grid of numbers
    int board[9][9];

    opening_example_from_file(board);
    print_board(board);
    solve(board);
    print_board(board);
    system("PAUSE");
    return 0;
}