#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#define BOARD_SIZE 9
using namespace std;
//Compile Command: c++ -std=c++11 -o name
int valid_input(int board[BOARD_SIZE][BOARD_SIZE],int row, int col){
    bool valid=true;
    int num;
    do{
        num = rand() % 9;
        valid=true;
        for (int i=0;i<9;++i){
            if (board[row][i] == num || board[i][col] == num){
                valid= false;
                break;
            }
        }
    } while (!valid);
    return num;
}
bool valid_in_box(int board[BOARD_SIZE][BOARD_SIZE], int row,int col,int proposed_num){
    int start_of_box_row, start_of_box_col;
    /*Get the top left corner of your box
    row%3 is the left over of your row, so row-row%3 gets you to the top row
    Same idea for the column
    */
    start_of_box_row = row - row %3;
    start_of_box_col = col - col %3;
    for (int row =0;row<3;row++){
        for (int col=0;col<3;col++){
            if (board[row+start_of_box_row][col+start_of_box_col]==proposed_num){
                return false;
            }
        }
    }
}
    
int get_valid_column(int board[BOARD_SIZE][BOARD_SIZE], int row){
    int num;
    bool valid=true;
    do{
        num = rand() % 9;
        valid=true;
        if (board[row][num] != 0){
            valid= false;
            break;
        }
    } while (valid);
    return num;
}

int get_num_filled(int board[BOARD_SIZE][BOARD_SIZE]){
    int count =0;
    for (int i=0;i<9;++i){
        for (int j=0;j<9;++j){
            if (board[i][j]!=0){
                count+=1;
            }
        }
        }
    return count;
    }
    

void pretty_print_matrix(int board[BOARD_SIZE][BOARD_SIZE]){
    cout<<"___________________"<<endl;
    for (int i=0;i<9;++i){
        string line="|";
        for (int j=0;j<9;++j){           
            line += to_string(board[i][j]);
            if ((j+1) % 3==0){
                line +="|";
            }
            else{
                line += " ";
            }
            
        }
        cout << line <<endl;
        if ((i+1)%3==0){
            cout<<"___________________"<<endl;
        }
    }
}
int main(){
    int sudoku_board[BOARD_SIZE][BOARD_SIZE];
    for (int i=0;i<BOARD_SIZE;i++){
        for (int j=0;j<BOARD_SIZE;j++){
            sudoku_board[i][j]= 0;
        }
    }
    vector<int> rs, cs,vs;
    for (int i=0;i<25;i++){
        int r = rand() % 9;
        rs.push_back(r);
        int c= get_valid_column(sudoku_board,r); 
        cs.push_back(c);
        int num = valid_input(sudoku_board,r,c);
        vs.push_back(num);
        sudoku_board[r][c]= num;
    }
    for (size_t i=0;i<rs.size();++i){
        printf("Row: %d, Col %d ,Val %d\n",rs[i]+1,cs[i]+1,vs[i]);
    }
    int filled;
    filled = get_num_filled(sudoku_board);
    printf("Total Number Filled %d \n",filled);
    pretty_print_matrix(sudoku_board);
    

    return 0;
}

