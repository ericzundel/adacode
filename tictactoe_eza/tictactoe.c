#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

char board[3][3];
const int ROWS = 3;
const int COLUMNS = 3;
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void clearBuffer();
int userInputNum();
char userInputChar();


int main()
{
    char playAgain;
    do
    {
        playAgain = ' ';
        resetBoard();
    

            // randomly decide if computer goes first & execute move
        srand(time(0));
        if (rand() % 2 == 1)
        {
            computerMove();
        }
        printBoard();

        while((checkWinner() == ' ') && (checkFreeSpaces() > 0))
        {
            
            playerMove();
            if((checkWinner() == ' ')) // computer will not move if winner is decided
            {
            computerMove();
            }
            printBoard();
        }
        if(checkWinner() == PLAYER)
        {
            printf("\n****************\n");
            printf("*** YOU WIN! ***");
            printf("\n****************\n");
        }
        else if(checkWinner() == COMPUTER)
        { 
            printf("\n*****************\n");
            printf("*** YOU LOSE! ***");
            printf("\n*****************\n");
        }
        else
        {
            printf("\n*************\n");
            printf("*** DRAW! ***");
            printf("\n*************\n");
        }

        while((playAgain != 'Y') && (playAgain != 'N'))
        {
            printf("\n\nWould you like to play again? (Y/N): ");
            playAgain = toupper(userInputChar()); // get the uppercase of user's char input
            
            if((playAgain != 'Y') && (playAgain != 'N'))
            {
                printf("\nInvalid response. Please try again.");
            }
        }
    }while(playAgain == 'Y');
return 0;
}




void resetBoard()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}
int checkFreeSpaces()
{
    int freeSpaces = ROWS*COLUMNS;
    for(int i = 0; i < sizeof(board)/sizeof(board)[0]; i++)
    {
        for(int j = 0; j < sizeof(board[0])/sizeof(board[0][0]); j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void playerMove()   // player choses row/col nums 1:3
{
    int moveSpace[2];   // x, y coords of player's move
    printf("Your move!\n");
    while(board[moveSpace[0]][moveSpace[1]] != ' ')
        {
                // read user's input row - 1
            printf("Enter your row: ");
            moveSpace[0] = userInputNum() - 1;
                // user input column - 1
            printf("Enter your column: ");
            moveSpace[1] = userInputNum() - 1;

                // check if user's space is blank:
            if((board[moveSpace[0]][moveSpace[1]]) != ' ')
            {
                printf("Invalid move! Please try again.\n");
                printBoard();
            }
    }
    board[moveSpace[0]][moveSpace[1]] = PLAYER;
}
void computerMove()
{
    int moveSpace[2];   // space to move to (x, y)
    int spaces = ROWS*COLUMNS;  // total spaces
    int possibleMoves[spaces][2];   // list of all possible move coordinates
    int temp[2]; // temporary array used to swap rows of possibleMoves

        // counters used to keep track of which y-coordinates correspond to each x-coordinate
    int counter = COLUMNS;
    int numInsert = 0; 

        // make array of all possible moves
        // first generate the x-coordinates of each space
    for(int i = 0; i < (spaces); i++)
    {
        possibleMoves[i][0] = i % ROWS; 
    }
        // then generate their corresponding y-coordinates such that they cover every space
    for(int i = 0; i < (spaces); i++)
    {
        counter--;
        possibleMoves[i][1] = numInsert;
        if(counter == 0)
        {
          counter = COLUMNS;
          numInsert++;
        }
    }

        // scramble list of all possible moves
    for(int i = 0; i < 9; i++)
    { 
            // pick a random move from the array    
            srand(time(0));
            int randomMove = rand() % spaces;

            //swap ith move with a random move
            for(int j = 0; j < 2; j++)
            {
            temp[j] = possibleMoves[randomMove][j];
            possibleMoves[randomMove][j] = possibleMoves[i][j];
            possibleMoves[i][j] = temp[j];
            }
    }
        // pick the first available move from the random list
    int i = 0;
    for(i = 0; i < spaces; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            moveSpace[j] = possibleMoves[i][j];
        }
        if(board[moveSpace[0]][moveSpace[1]] == ' ')    // stop checking when free space found
        {
            break;
        }
    }
        // make the move
    board[moveSpace[0]][moveSpace[1]] = COMPUTER;
}
char checkWinner()
{
        // default to winner = ' '
    int playerInARow = 0;
    int computerInARow = 0;

        // check rows
    for (int i = 0; i < ROWS; i++)
    {
        playerInARow = 0;
        computerInARow = 0;
        for (int j = 0; j < COLUMNS; j++)
        {
                if(board[i][j] == PLAYER)
                {
                     playerInARow++;
                }
                else if(board[i][j] == COMPUTER)
                {
                     computerInARow++;
                }
        }
        if(playerInARow == COLUMNS)
        {
            return PLAYER;
        }
        if(computerInARow == COLUMNS)
        {
            return COMPUTER;
        }
    }
        // check columns
    for (int i = 0; i < ROWS; i++)
    {
        playerInARow = 0;
        computerInARow = 0;
        for(int j = 0; j < COLUMNS; j++)
        {
                if(board[j][i] == PLAYER)
                {
                     playerInARow++;
                }
                else if(board[j][i] == COMPUTER)
                {
                     computerInARow++;
                }
        }
        if(playerInARow == COLUMNS)
        {
            return PLAYER;
        }
        if(computerInARow == COLUMNS)
        {
            return COMPUTER;
        }
    }
        // check diagonals if board is square
    if(ROWS == COLUMNS)
    {
        // diagonal 1
        int diagLen = ROWS;
        playerInARow = 0;
        computerInARow = 0;
        for(int i = 0; i < diagLen; i++)
        {
            if(board[i][i] == PLAYER)
            {
                playerInARow++;
            }
            else if(board[i][i] == COMPUTER)
            {
                computerInARow++;
            }
        }
        if(playerInARow == diagLen)
        {
            return PLAYER;
        }
        if(computerInARow == diagLen)
        {
            return COMPUTER;
        }
            // diagonal 2
        playerInARow = 0;
        computerInARow = 0;
        int j = 0;
        for(int i = diagLen-1; i >= 0; i--)
        {
            if(board[i][j] == PLAYER)
            {
                playerInARow++;
            }
            else if(board[i][j] == COMPUTER)
            {
                computerInARow++;
            }
            j++;
        }
        if(playerInARow == diagLen)
        {
            return PLAYER;
        }
        if(computerInARow == diagLen)
        {
            return COMPUTER;
        }
    }
return(' ');
}
void clearBuffer()
{
    int ch;
    while((ch = getchar() != '\n') && (ch != EOF)); 
}
int userInputNum()
{
    int inputNum;
    inputNum = getchar();
    clearBuffer();
    inputNum -= '0';    // convert char to int ('1' --> 1)
    return inputNum;
}
char userInputChar()
{
    char inputChar;
    inputChar = getchar();
    clearBuffer();
    return inputChar;
}