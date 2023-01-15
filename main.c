#pragma execution_character_set( "utf-8" )
#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include <string.h>


int i, j;
char move[20];
size_t size;

void printGameBoard(char gameBoard[8][8]);
int validityOfMove(char move[20]);
char* drawPiece(char piece);
int placeMove(char from[3], char to[3]);

char gameBoard[8][8] = {{ 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' },
                        { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
                        { 'R', 'N', 'B','Q', 'K', 'B',  'N', 'R' },
                    };

int main(){
    SetConsoleOutputCP(65001);
    printf("\n\n\t\tCHESS\n\n");

    printGameBoard(gameBoard);

    while(1) {
        askinput:
            printf("Enter : ");
            fgets(move, 25, stdin);
            move[strlen(move) - 1] = '\0';
            if(validityOfMove(move) != 0)
                continue;
            printGameBoard(gameBoard);
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
        return "A";
}

int validityOfMove(char move[20]) {
    if(strlen(move) != 4) 
        return printf("\nNot a valid move, [example: e4e5]\n\n");
    
    const char legalLetter[9] = "abcdefgh";
    const char legalDigits[9] = "12345678";
    int toIsValid = 0, fromIsValid = 0;

    char from[3], to[3];
    from[0] = move[0];
    from[1] = move[1];
    from[2] = '\0';

    to[0] = move[2];
    to[1] = move[3];
    to[2] = '\0';

    for(i = 0; i <= 8; i++) {
        if(from[0] == legalLetter[i]) {
            for(j = 0; j <= 8; j++) {
                if(from[1] == legalDigits[j])
                    fromIsValid = 1;
            }
        }
    }
    if(!fromIsValid)
        return printf("\nNot a valid move, [example: e4e5]\n\n");
    
    for(i = 0; i <= 8; i++) {
        if(to[0] == legalLetter[i]) {
            for(j = 0; j <= 8; j++) {
                if(to[1] == legalDigits[j])
                    toIsValid = 1;
            }
        }
    }
    if(!toIsValid)
        return printf("\nNot a valid move, [example: e4e5]\n\n");
    placeMove(from, to);
    return 0;
    // printf("\nPiece %s %s moved to\n", from, to);
}

int placeMove(char from[3], char to[3]) {
    int fromRow, fromCol;
    int toRow, toCol;
    char temp;
    switch (from[0]){
        case 'a':
            fromRow = 0;
            break;
        case 'b':
            fromRow = 1;
            break;
        case 'c':
            fromRow = 2;
            break;
        case 'd':
            fromRow = 3;
            break;
        case 'e':
            fromRow = 4;
            break;
        case 'f':
            fromRow = 5;
            break;
        case 'g':
            fromRow = 6;
            break;
        case 'h':
            fromRow = 7;
            break;
        default:
            break;
    }
    switch (from[1]){
        case '1':
            fromCol = 7;
            break;
        case '2':
            fromCol = 6;
            break;
        case '3':
            fromCol = 5;
            break;
        case '4':
            fromCol = 4;
            break;
        case '5':
            fromCol = 3;
            break;
        case '6':
            fromCol = 2;
            break;
        case '7':
            fromCol = 1;
            break;
        case '8':
            fromCol = 0;
            break;
        default:
            break;
    }

    switch (to[0]){
        case 'a':
            toRow = 0;
            break;
        case 'b':
            toRow = 1;
            break;
        case 'c':
            toRow = 2;
            break;
        case 'd':
            toRow = 3;
            break;
        case 'e':
            toRow = 4;
            break;
        case 'f':
            toRow = 5;
            break;
        case 'g':
            toRow = 6;
            break;
        case 'h':
            toRow = 7;
            break;
        default:
            break;
    }
    switch (to[1]){
        case '1':
            toCol = 7;
            break;
        case '2':
            toCol = 6;
            break;
        case '3':
            toCol = 5;
            break;
        case '4':
            toCol = 4;
            break;
        case '5':
            toCol = 3;
            break;
        case '6':
            toCol = 2;
            break;
        case '7':
            toCol = 1;
            break;
        case '8':
            toCol = 0;
            break;
        default:
            break;
    }
    temp = gameBoard[fromCol][fromRow];
    
    gameBoard[fromCol][fromRow] = 0;
    gameBoard[toCol][toRow] = 0;

    gameBoard[toCol][toRow] = temp;

    // printf("HERE:: %d %d\n", fromCol, fromRow);
    // gameBoard[toCol][toRow] = gameBoard[fromCol][fromRow];
    return 0;
}