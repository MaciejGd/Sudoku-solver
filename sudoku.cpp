#include<cmath>
#include<iostream>
#include<fstream>


using namespace std;

//function for opening sudoku example from text file
void opening_example_from_file(int (&board)[9][9]){
    string example;
    cout<<"Choose which file you want to read: ";
    cin>>example;
    ifstream file("./"+example+".txt");
    
    if(!file.is_open()){
        cout<<"Wrong file name. Try again: ";
        opening_example_from_file(board);
    }
    if(file.is_open()){
        int row = 0;
        int col = 0;
        int num;

        while(file>>num){
            board[row][col] = num;
            col++;
            
            if(col == 9){
                col = 0;
                row++;
            }

            if(row == 9){
                break; 
            }
        }
        file.close();
    }
}

//printing board 
void print_board(int board[9][9]){
    for(int i = 0; i<9;i++){
        cout<<"+---+---+---+---+---+---+---+---+---+"<<endl;
        cout<<"| ";
        for(int j = 0; j<9 ; j++){
            if(board[i][j]==0){
                cout<<"  | ";
            }
            else{
                cout<<board[i][j]<<" | ";  
            }
            
        }
        cout<<endl;    
    }
    cout<<"+---+---+---+---+---+---+---+---+---+"<<endl;
}

//checking if number can be placed in tile
bool possible(int y, int x, int n, int board[9][9]){
    for(int i = 0; i<9; i++){
        if(board[y][i]==n){
            return false;
        }
        else if(board[i][x]==n){
            return false;
        }
    }
    int x0=floor(x/3)*3;
    int y0=floor(y/3)*3;

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(board[y0+i][x0+j]==n){
                return false;
            }
        }
    }

    return true;

}

//function solving sudoku using backtracking
bool solve(int (&board)[9][9]){
    for(int y = 0; y<9; y++){
        for(int x = 0; x<9; x++){
            if(board[y][x]==0){
                for(int i = 1; i<10;i++){
                    if (possible(y,x,i,board)){
                        board[y][x] = i;
                        
                        if(solve(board)){
                            return true;
                        }
                    }
                }
                board[y][x] = 0;
                return false; 
            }
        }
    }
    return true;

}



