#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char Board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';
char PlayerChoice;

void ResetBoard();
void PrintBoard();
int CheckFreeSpaces();
void Player1Move();
void Player2Move();
void ComputerMove();
char CheckWinner();
void PrintWinner(char);

int main()
{
    char Winner = ' ';
    char Replay = ' ';

    printf("\n\n             [ TIC-TAC-TOE ]");

    do
    {
        Winner = ' ';
        Replay = ' ';

        printf("\n__________________________________________\n");

        while (1)
        {

            printf("\n[Choose a player between human & computer]\nEnter 'H' or 'C': ");
            scanf(" %c", &PlayerChoice);
            PlayerChoice = toupper(PlayerChoice);

            if (PlayerChoice == 'H')
            {
                break;
            }
            else if (PlayerChoice == 'C')
            {
                break;
            }
            else
                printf("INVALID CHOICE!\n");
        }

        ResetBoard();
        if (PlayerChoice == 'H')
        {
            while (Winner == ' ' && CheckFreeSpaces() > 0)
            {
                PrintBoard();
                Player1Move();
                Winner = CheckWinner();
                if (Winner != ' ' || CheckFreeSpaces() == 0)
                {
                    break;
                }
                PrintBoard();
                Player2Move();
                Winner = CheckWinner();
                if (Winner != ' ' || CheckFreeSpaces() == 0)
                {
                    break;
                }
            }
        }

        if (PlayerChoice == 'C')
        {
            while (Winner == ' ' && CheckFreeSpaces() > 0)
            {
                PrintBoard();
                Player1Move();
                Winner = CheckWinner();
                if (Winner != ' ' || CheckFreeSpaces() == 0)
                {
                    break;
                }

                ComputerMove();
                Winner = CheckWinner();
                if (Winner != ' ' || CheckFreeSpaces() == 0)
                {
                    break;
                }
            }
        }

        PrintBoard();
        PrintWinner(Winner);
        printf("\n\nWould you like to play again? (Y/N): ");
        scanf(" %c", &Replay);
        Replay = toupper(Replay);

    } while (Replay == 'Y');

    printf("THANKS FOR PLAYING!\n\n");
}

void ResetBoard()
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            Board[r][c] = ' ';
        }
    }
}

void PrintBoard()
{
    printf("\n");
    printf(" %c | %c | %c \n", Board[0][0], Board[0][1], Board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", Board[1][0], Board[1][1], Board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", Board[2][0], Board[2][1], Board[2][2]);
    printf("\n");
}

int CheckFreeSpaces()
{
    int freeSpaces = 9;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (Board[r][c] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}

void Player1Move()
{
    int r;
    int c;
    do
    {
        if (PlayerChoice == 'H')
        {
            printf("[For player 'X']\n");
            printf("Enter row #(1-3): ");
            scanf("%d", &r);
            r--;
            printf("Enter column #(1-3): ");
            scanf("%d", &c);
            c--;
        }
        else if (PlayerChoice == 'C')
        {

            printf("Enter row #(1-3): ");
            scanf("%d", &r);
            r--;
            printf("Enter column #(1-3): ");
            scanf("%d", &c);
            c--;
        }

        if (Board[r][c] == ' ')
        {
            Board[r][c] = PLAYER1;
            break;
        }
        else
            printf("INVALID MOVE!\n\n");

    } while (Board[r][c] != ' ');
}

void Player2Move()
{
    int r;
    int c;

    do
    {

        printf("[For player 'O']\n");
        printf("Enter row #(1-3): ");
        scanf("%d", &r);
        r--;
        printf("Enter column #(1-3): ");
        scanf("%d", &c);
        c--;

        if (Board[r][c] == ' ')
        {
            Board[r][c] = PLAYER2;
            break;
        }
        else
            printf("INVALID MOVE!\n\n");

    } while (Board[r][c] != ' ');
}

void ComputerMove()
{
    srand(time(0));
    int r;
    int c;

    if (CheckFreeSpaces > 0)
    {
        do
        {
            r = rand() % 3;
            c = rand() % 3;

        } while (Board[r][c] != ' ');

        Board[r][c] = COMPUTER;
    }
    else
        PrintWinner(' ');
}

char CheckWinner()
{
    for (int r = 0; r < 3; r++)
    {
        if (Board[r][0] == Board[r][1] && Board[r][0] == Board[r][2])
        {
            return Board[r][0];
        }
    }

    for (int c = 0; c < 3; c++)
    {
        if (Board[0][c] == Board[1][c] && Board[0][c] == Board[2][c])
        {
            return Board[0][c];
        }
    }

    if (Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2])
    {
        return Board[0][0];
    }
    if (Board[2][0] == Board[1][1] && Board[2][0] == Board[0][2])
    {
        return Board[2][0];
    }

    return ' ';
}

void PrintWinner(char Winner)
{
    if (PlayerChoice == 'H')
    {
        if (Winner == PLAYER1)
        {
            printf("'X' WINS!");
        }
        else if (Winner == PLAYER2)
        {
            printf("'O' WINS!");
        }
        else
            printf("ITS A TIE!");
    }

    if (PlayerChoice == 'C')
    {
        if (Winner == PLAYER1)
        {
            printf("YOU WIN!");
        }
        else if (Winner == COMPUTER)
        {
            printf("YOU LOSE!");
        }
        else
            printf("ITS A TIE!");
    }
}
