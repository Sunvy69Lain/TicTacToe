#pragma once
#define total_rows 3
#define total_columns 3
#include "cross_over.hpp"

class Board
{
public:
    char turn = 'X';
    bool winner_exists = false;
    bool row_crossed[3] = {false, false, false};
    bool column_crossed[3] = {false, false, false};
    bool diagonal_crossed[2] = {false, false};

private:
    char board[total_rows][total_columns];
    float win_size;
    float cell_size;
    char PlayerX = 'X';
    char PlayerO = 'O';

public:
    Board(float win_size) : win_size(win_size), cell_size(win_size / 3) { ResetBoard(); }

    float CellSize();

    void ResetBoard();

    void SetValue(int row, int column, char value);

    char GetValue(int row, int column);

    void CheckWinner();

    void CrossWinner(CrossOver *cross);
};