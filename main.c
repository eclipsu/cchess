#pragma execution_character_set( "utf-8" )
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <string.h>


int i, j;
char move[4];
size_t size;

void printGameBoard(char gameBoard[8][8]);
char* drawPiece(char piece);

int main(){
    SetConsoleOutputCP(65001);
    printf("\n\n\t\tCHESS\n\n");
    char gameBoard[8][8] = {{ 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
                            { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 0, 0, 0, 0, 0, 0, 0, 0 },
                            { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
                            { 'R', 'N', 'B','Q', 'K', 'B',  'N', 'R' },
                        };

    printGameBoard(gameBoard);

    while(1) {
        askinput:
            printf("Enter : ");
            fgets(move, 25, stdin);
            move[strlen(move) - 1] = '\0';
            if(strlen(move) != 5)
                goto askinput;
            printf("Moved played: %s\n", move);
    }
    return 0;
}

void printGameBoard(char gameBoard[8][8]) {
    for(i = 0; i <= 7; i++) {
        if(i == 0)
            printf("\ta  b  c  d  e  f  g  h\n\n");

        printf("%d\t", (10 - i + -2));
        for(j = 0; j <= 7; j++) {
            if(gameBoard[i][j] == 0)
                printf(".  ");
            else
                printf("%s  ", drawPiece(gameBoard[i][j]));
            if(j == 7)
                printf("\t%d", (10 - i + -2));
        }
        if(i == 7)
            printf("\n\n \ta  b  c  d  e  f  g  h\n");
        printf("\n");
    }
}

char* drawPiece(char piece) {
    if(piece == 'P')
        return "♟︎";
    if(piece == 'p')
        return "♙";
    if(piece == 'k')
        return "♔";
    if(piece == 'K')
        return "♚";
    if(piece == 'q')
        return "♕";
    if(piece == 'Q')
        return "♛";
    if(piece == 'r')
        return "♖";
    if(piece == 'R')
        return "♜";
    if(piece == 'b')
        return "♗";
    if(piece == 'B')
        return "♝";
    if(piece == 'n')
        return "♘";
    if(piece == 'N')
        return "♞";
    else
        return "Failed";
}