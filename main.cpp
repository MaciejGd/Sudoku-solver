#include<iostream>
#include<string>
#include"sudoku.hpp"

using namespace std;

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
