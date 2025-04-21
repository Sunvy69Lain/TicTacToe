#include "board.hpp"

// Arrays of CrossOver draw methods:
void (CrossOver::*cross_row[3])() =
    {
        CrossOver::DrawRow0,
        CrossOver::DrawRow1,
        CrossOver::DrawRow2};
void (CrossOver::*cross_column[3])() =
    {
        CrossOver::DrawColumn0, CrossOver::DrawColumn1, CrossOver::DrawColumn2};
void (CrossOver::*cross_diagonal[2])() =
    {
        CrossOver::DrawDiagonal1, CrossOver::DrawDiagonal2};

// Board handling methods:
void Board::ResetBoard()
{
    for (int i = 0; i < total_rows; i++)
    {
        for (int j = 0; j < total_columns; j++)
            board[i][j] = ' ';
    }
}
void Board::SetValue(int row, int column, char value)
{
    board[row][column] = value;
}
char Board::GetValue(int row, int column)
{
    return board[row][column];
}
float Board::CellSize()
{
    return cell_size;
}

// Winner resolving methods:
void Board::CheckWinner()
{

    for (int r = 0; r < total_rows; r++)
    {
        if (board[r][0] != ' ' && board[r][1] != ' ' && board[r][2] != ' ')
        {
            if (board[r][0] == board[r][1] && board[r][0] == board[r][2])
            {
                row_crossed[r] = true;
                winner_exists = true;
            }
        }
    }
    for (int c = 0; c < total_columns; c++)
    {
        if (board[0][c] != ' ' && board[1][c] != ' ' && board[2][c] != ' ')
        {
            if (board[0][c] == board[1][c] && board[0][c] == board[2][c])
            {
                column_crossed[c] = true;
                winner_exists = true;
            }
        }
    }
    if (board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' ')
    {
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            diagonal_crossed[0] = true;
            winner_exists = true;
        }
    }
    if (board[2][0] != ' ' && board[1][1] != ' ' && board[0][2] != ' ')
    {
        if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
        {
            diagonal_crossed[1] = true;
            winner_exists = true;
        }
    }
}
void Board::CrossWinner(CrossOver *cross)
{
    for (int r = 0; r < total_rows; r++)
    {
        if (row_crossed[r])
        {
            (cross->*cross_row[r])();
        }
    }
    for (int c = 0; c < total_columns; c++)
    {
        if (column_crossed[c])
        {
            (cross->*cross_column[c])();
        }
    }
    for (int d = 0; d < 2; d++)
    {
        if (diagonal_crossed[d])
        {
            (cross->*cross_diagonal[d])();
        }
    }
}