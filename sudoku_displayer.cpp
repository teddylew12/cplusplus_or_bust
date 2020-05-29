#include <array>
#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#define boardSize 9
using namespace std;
//Compile Command: c++ -std=c++11 -o name
int valid_input(vector<int> &board, int row, int col)
{
    bool valid;
    int num;
    do
    {
        valid = true;
        num = rand() % 9;
        if (numInRow(board, row, num) || numInCol(board, col, num) || numInBox(board, row, col, num))
        {
            valid = false;
        }
    } while (!valid);
    return num;
}
bool numInRow(vector<int> &board, int row, int proposedNum)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[row * boardSize + i] == proposedNum)
        {
            return true;
        }
    }
    return false;
}
bool numInCol(vector<int> &board, int col, int proposedNum)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[i * boardSize + col] == proposedNum)
        {
            return true;
        }
    }
    return false;
}
bool numInBox(vector<int> &board, int row, int col, int proposedNum)
{
    int start_of_box_row, start_of_box_col;
    /*Get the top left corner of your box
    row%3 is the left over of your row, so row-row%3 gets you to the top row
    Same idea for the column
    */
    start_of_box_row = row - row % 3;
    start_of_box_col = col - col % 3;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[(row + start_of_box_row) * boardSize + col + start_of_box_col] == proposedNum)
            {
                return false;
            }
        }
    }
    return true;
}

int getValidColumn(vector<int> &board, int row)
{
    int num;
    bool valid = true;
    do
    {
        num = rand() % 9;
        valid = true;
        if (board[row * boardSize + num] != 0)
        {
            valid = false;
            break;
        }
    } while (valid);
    return num;
}

int getNumFilled(vector<int> &board)
{
    int count = 0;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i * boardSize + j] != 0)
            {
                count += 1;
            }
        }
    }
    return count;
}

void prettyPrintMatrix(vector<int> &board)
{
    cout << "___________________" << endl;
    for (int i = 0; i < 9; ++i)
    {
        string line = "|";
        for (int j = 0; j < 9; ++j)
        {
            line += to_string(board[i * boardSize + j]);
            if ((j + 1) % 3 == 0)
            {
                line += "|";
            }
            else
            {
                line += " ";
            }
        }
        cout << line << endl;
        if ((i + 1) % 3 == 0)
        {
            cout << "___________________" << endl;
        }
    }
}
int main()
{
    vector<int> sudokuBoard;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            sudokuBoard[boardSize * i + j] = 0;
        }
    }
    vector<int> rs, cs, vs;
    for (int i = 0; i < 25; i++)
    {
        int r = rand() % 9;
        rs.push_back(r);
        int c = getValidColumn(sudokuBoard, r);
        cs.push_back(c);
        int num = valid_input(sudokuBoard, r, c);
        vs.push_back(num);
        sudokuBoard[r * boardSize + c] = num;
    }
    for (size_t i = 0; i < rs.size(); ++i)
    {
        printf("Row: %d, Col %d ,Val %d\n", rs[i] + 1, cs[i] + 1, vs[i]);
    }
    int filled;
    filled = getNumFilled(sudokuBoard);
    printf("Total Number Filled %d \n", filled);
    prettyPrintMatrix(sudokuBoard);

    return 0;
}
