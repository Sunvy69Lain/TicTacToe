#include <raylib.h>
#include "board.hpp"
#include "grid_lines.hpp"
#include "cross_over.hpp"
#include "simulate_players.hpp"

int main()
{
    float win_size = 500;
    InitWindow(win_size, win_size, "TicTacToe");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) // Replay loop.
    {
        Board board(win_size);
        GridLines grid_lines(win_size);
        CrossOver cross(win_size);
        SimulatePlayers players(win_size, 70, 60);

        while (WindowShouldClose() == false)
        {
            // Player input:
            Vector2 mouse_pos = GetMousePosition();
            int mouse_row = mouse_pos.y / board.CellSize();
            int mouse_column = mouse_pos.x / board.CellSize();
            bool mouse_clicked = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

            if (mouse_clicked && board.GetValue(mouse_row, mouse_column) == ' ' && board.winner_exists == false)
            {
                if (board.turn == 'X')
                {
                    board.SetValue(mouse_row, mouse_column, 'X');
                    board.turn = 'O';
                }
                else if (board.turn == 'O')
                {
                    board.SetValue(mouse_row, mouse_column, 'O');
                    board.turn = 'X';
                }
            }

            // Display game simulation:
            BeginDrawing();
            ClearBackground(WHITE);
            grid_lines.Draw();

            if (board.GetValue(0, 0) == 'X')
                players.DrawXindex00();
            if (board.GetValue(0, 1) == 'X')
                players.DrawXindex01();
            if (board.GetValue(0, 2) == 'X')
                players.DrawXindex02();
            if (board.GetValue(1, 0) == 'X')
                players.DrawXindex10();
            if (board.GetValue(1, 1) == 'X')
                players.DrawXindex11();
            if (board.GetValue(1, 2) == 'X')
                players.DrawXindex12();
            if (board.GetValue(2, 0) == 'X')
                players.DrawXindex20();
            if (board.GetValue(2, 1) == 'X')
                players.DrawXindex21();
            if (board.GetValue(2, 2) == 'X')
                players.DrawXindex22();

            if (board.GetValue(0, 0) == 'O')
                players.DrawOindex00();
            if (board.GetValue(0, 1) == 'O')
                players.DrawOindex01();
            if (board.GetValue(0, 2) == 'O')
                players.DrawOindex02();
            if (board.GetValue(1, 0) == 'O')
                players.DrawOindex10();
            if (board.GetValue(1, 1) == 'O')
                players.DrawOindex11();
            if (board.GetValue(1, 2) == 'O')
                players.DrawOindex12();
            if (board.GetValue(2, 0) == 'O')
                players.DrawOindex20();
            if (board.GetValue(2, 1) == 'O')
                players.DrawOindex21();
            if (board.GetValue(2, 2) == 'O')
                players.DrawOindex22();

            board.CheckWinner();
            board.CrossWinner(&cross);
            EndDrawing();

            // Reset game:
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER))
            {
                break;
            }
        }
    }

    CloseWindow();
}