//
// Created by ori on 30/11/2020.
//
/***********
* Ori Angel
* 314617739
* 01
* ass04
***********/
#include <string.h>
#include <math.h>
#include "ass4.h"

/******************
* Function Name: checkCharInput
* Input: char c
* Output: return the type of the char
* Function Operation: check what is the type of specific char
******************/

char *checkCharInput(char c) {
    if (c >= '1' && c <= '0' + (SIZE * SIZE))
        return "number";
    if (c == '/')
        return "slash";
    //range of all the valid spaces
    int rangeOfSpace = SIZE * SIZE;

    if ((c >= 'a' && c <= 'a' + rangeOfSpace) || c == ' ')
        return "space";
    return "unknown";
}

/******************
* Function Name: isInBoundaries
* Input: int i, int j
* Output: return 1 if in boundaries else return 0
* Function Operation: check if index inside arr.
******************/

int isInBoundaries(int i, int j) {
    if (i < SIZE * SIZE && j < SIZE * SIZE && i >= 0 && j >= 0) {
        return 1;
    }
    return 0;
}

/******************
* Function Name: printBoard
* Input: char board[][SIZE * SIZE]
* Output: -
* Function Operation: print the board to screen
******************/

void printBoard(char board[][SIZE * SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        for (int j = 0; j < SIZE * SIZE; j++) {

            printf("%c", board[i][j]);
            if (j % SIZE == (SIZE - 1) && j < SIZE * SIZE - 1)
                printf(" | ");
        }
        printf("\n");
        //line space between squares
        if (i % SIZE == (SIZE - 1) && i < SIZE * SIZE - 1)
            printf("\n");
    }
    printf("\n");
}

/******************
* Function Name: initializeBoard
* Input: char board[][SIZE * SIZE]
* Output: -
* Function Operation: initialize the arr cells.
******************/

void initializeBoard(char board[][SIZE * SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        for (int j = 0; j < SIZE * SIZE; j++) {
            board[i][j] = '0';
        }
    }
}


/******************
* Function Name: createBoard
* Input: char board[][SIZE * SIZE], char str[]
* Output: -
* Function Operation: print the sudoku board.
******************/

void createBoard(char board[][SIZE * SIZE], char str[]) {
    initializeBoard(board);
    int strIndex = 0;
    int numOfSlash = 0;
    for (int i = 0; i < SIZE * SIZE; i++) {
        for (int j = 0; j < SIZE * SIZE; j++) {
            char currentChar = str[strIndex];
            if (!(strcmp(checkCharInput(currentChar), "number"))) {
                board[i][j] = currentChar;
            }
            if (!(strcmp(checkCharInput(currentChar), "space"))) {
                for (int k = 'a'; k <= currentChar; k++) {
                    //check boundaries
                    if (j < SIZE * SIZE) {
                        board[i][j] = ' ';
                        j++;
                    } else {
                        printf("Error\n");
                        return;
                    }
                }
                //finish spaces
                j--;
            }
            if (!(strcmp(checkCharInput(currentChar), "unknown"))) {
                board[i][j] = currentChar;
            }
            //end of line or end of str
            if (!(strcmp(checkCharInput(currentChar), "slash")) || currentChar == 0) {
                //space till end of line
                for (j = j; j < SIZE * SIZE; j++) {
                    board[i][j] = ' ';
                }
                //don't check slash twice
                strIndex--;
            }
            //check next char
            strIndex++;
        }
        //check row valid
        if (!(strcmp(checkCharInput(str[strIndex]), "slash"))) {
            {
                strIndex++;
                numOfSlash++;
            }
        }
    }
    //check if str finish
    if (str[strIndex] != 0) {
        printf("Error\n");
        return;
    }
    //check correct numOfSlash
    if (numOfSlash != ((SIZE * SIZE) - 1)) {
        printf("Error\n");
        return;
    }
}

/******************
* Function Name: replaceAll
* Input: char board[][SIZE * SIZE], char current, char replace
* Output: -
* Function Operation: replace one char to another
******************/

void replaceAll(char board[][SIZE * SIZE], char current, char replace) {
    int isReplaceInBoard = 0;
    if (current != ' ') {
        if (strcmp(checkCharInput(replace), "space") != 0 && replace != '/' && replace != 0) {
            for (int i = 0; i < SIZE * SIZE; i++) {
                for (int j = 0; j < SIZE * SIZE; j++) {
                    if (board[i][j] == current) {
                        board[i][j] = replace;
                        isReplaceInBoard = 1;
                    }
                }
            }
        } else {
            printf("Error\n");
            return;
        }
        if (!isReplaceInBoard)
            printf("Error\n");
    } else
        printf("Error\n");
}

/******************
* Function Name: replaceAll
* Input: char board[][SIZE * SIZE], char current, char replace
* Output: -
* Function Operation: replace one char to another
******************/

void changeChar(char board[][SIZE * SIZE], char locationRow, char locationCol, char change) {
    //convert char to int
    int i = locationRow - '0';
    int j = locationCol - '0';
    if (isInBoundaries(i, j)) {
        if (board[i][j] != ' ' && change != 0) {
            board[i][j] = change;
        } else {
            printf("Error\n");
        }
    } else {
        printf("Error\n");
    }
}

/******************
* Function Name: addChar
* Input: char board[][SIZE * SIZE], char locationRow, char locationCol, char add
* Output: -
* Function Operation: add new char in empty cell
******************/
void addChar(char board[][SIZE * SIZE], char locationRow, char locationCol, char add) {
    //convert char to int
    int i = locationRow - '0';
    int j = locationCol - '0';
    if (isInBoundaries(i, j)) {
        //just space valid
        if (board[i][j] == ' ' && add != 0) {
            board[i][j] = add;

        } else {
            printf("Error\n");
        }
    } else {
        printf("Error\n");
    }
}

/******************
* Function Name: deleteChar
* Input: char board[][SIZE * SIZE], char locationRow, char locationCol
* Output: -
* Function Operation: delete char in the board
******************/
void deleteChar(char board[][SIZE * SIZE], char locationRow, char locationCol) {
    //convert char to int
    int i = locationRow - '0';
    int j = locationCol - '0';
    if (isInBoundaries(i, j)) {
        if (board[i][j] == ' ') {
            printf("Error\n");
        } else {
            board[i][j] = ' ';
        }
    } else {
        printf("Error\n");
    }
}

/******************
* Function Name: makeMove
* Input: char board[][SIZE * SIZE], char move[]
* Output: -
* Function Operation: make move (replace,add,delete or change) in the board
******************/
void makeMove(char board[][SIZE * SIZE], char move[]) {

    // Returns first token
    char *token = strtok(move, ",");
    //string length
    int length = strlen(token);
    char fun[20];
    strcpy(fun, token);
    //check if one of the functions
    if (!strcmp(fun, "replaceAll") || !strcmp(fun, "change") || !strcmp(fun, "add") || !strcmp(fun, "delete")) {
        char char1[2] = "", char2[2] = "", char3[2] = "";
        int i = 1;
        while (token != NULL) {
            token = strtok(NULL, ",");
            //location must be one digit
            if (token != NULL) {
                if (1 == strlen(token)) {
                    if (i == 1)
                        strcpy(char1, token);
                    if (i == 2)
                        strcpy(char2, token);
                    if (i == 3 && token != NULL)
                        strcpy(char3, token);
                    i++;
                } else {
                    printf("Error\n");
                    return;
                }
            }
        }
        if (!(strcmp(fun, "replaceAll"))) {
            replaceAll(board, char1[0], char2[0]);
        }
        if (!(strcmp(fun, "change"))) {
            changeChar(board, char1[0], char2[0], char3[0]);
        }
        if (!(strcmp(fun, "add"))) {
            addChar(board, char1[0], char2[0], char3[0]);
        }
        if (!(strcmp(fun, "delete"))) {
            deleteChar(board, char1[0], char2[0]);
        }
    } else {
        printf("Error\n");
        return;
    }
}

/******************
* Function Name: correntInput
* Input: char board[][SIZE * SIZE]
* Output: return 1 if the board is valid and 0 else
* Function Operation: check is the board valid
******************/
int correntInput(char board[][SIZE * SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        for (int j = 0; j < SIZE * SIZE; j++) {
            if ((board[i][j] != ' ') && (board[i][j] < '1' || board[i][j] > '0' + SIZE * SIZE)) {
                return 0;
            }
        }
    }
    return 1;
}

/******************
* Function Name: isCellCorrect
* Input: char board[][SIZE * SIZE], int iChar, int jChar
* Output: return 1 if the cell is valid and 0 else
* Function Operation: check if the value of cell is the same as another in the same row or column
******************/
int isCellCorrect(char board[][SIZE * SIZE], int iChar, int jChar) {
    //check row
    for (int j = 0; j < SIZE * SIZE; j++) {
        if ((board[iChar][j] == board[iChar][jChar]) && jChar != j) {
            return 0;
        }
    }
    //check column
    for (int i = 0; i < SIZE * SIZE; i++) {
        if ((board[i][jChar] == board[iChar][jChar]) && iChar != i) {
            return 0;
        }
    }
    return 1;
}

/******************
* Function Name: isSameNumInSquare
* Input: char board[][SIZE * SIZE], int iChar, int jChar
* Output: return 1 if the num is in square
* Function Operation: check if the num is in sudoku square
******************/
int isSameNumInSquare(char board[][SIZE * SIZE], int iChar, int jChar) {
    int iSquare = (iChar / SIZE) * SIZE;
    int jSquare = (jChar / SIZE) * SIZE;
    for (int i = iSquare; i < iSquare + SIZE; i++) {
        for (int j = jSquare; j < jSquare + SIZE; j++) {
            if ((board[i][j] == board[iChar][jChar]) && (iChar != i && jChar != j)) {
                return 0;
            }
        }
    }
    return 1;
}

/******************
* Function Name: testBoard
* Input: char board[][SIZE * SIZE]
* Output: return 1 if board valid 0 else.
* Function Operation: check if the board valid
******************/

int testBoard(char board[][SIZE * SIZE]) {
    if (!correntInput(board)) {
        return 0;
    }
    for (int i = 0; i < SIZE * SIZE; i++) {
        for (int j = 0; j < SIZE * SIZE; j++) {
            if (board[i][j] != ' ') {
                if (!isCellCorrect(board, i, j) && !isSameNumInSquare(board, i, j)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/******************
* Function Name: isSameBoard
* Input: char board[][SIZE * SIZE], char board1[][SIZE * SIZE]
* Output: return 1 if the boards are same 0 else.
* Function Operation: check if the boards are the same
******************/
int isSameBoard(char board[][SIZE * SIZE], char board1[][SIZE * SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        for (int j = 0; j < SIZE * SIZE; j++) {
            if (board[i][j] != board1[i][j]) {
                printf("Found inequality on row %d col %d.\n", i, j);
                return 0;
            }
        }
    }
    return 1;
}

/******************
* Function Name: initializeArr
* Input: char arr[SIZE]
* Output: -
* Function Operation: initializeArr
******************/
void initializeArr(char arr[SIZE]) {
    for (int i = 0; i < SIZE * SIZE; i++) {
        arr[i] = '0';
    }
}

/******************
* Function Name: fillCell
* Input: char board[][SIZE * SIZE], int iChar, int jChar]
* Output: -
* Function Operation: fill cell on board
******************/

int fillCell(char board[][SIZE * SIZE], int iChar, int jChar) {
    int countSpace = 0;
    int value = 0;
    char arrRow[SIZE * SIZE];
    initializeArr(arrRow);
    char arrColumn[SIZE * SIZE];
    initializeArr(arrColumn);

    //fill arrRow
    for (int j = 0; j < SIZE * SIZE; j++) {
        if (board[iChar][j] != ' ') {
            value = board[iChar][j] - '0';
            //arr start from 0
            arrRow[value - 1] = '1';
        } else {
            countSpace++;
        }
    }
    //fill arrColumn
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (board[i][jChar] != ' ') {
            value = board[i][jChar] - '0';
            arrColumn[value - 1] = '1';
        } else
            countSpace++;
    }
    //more than 1 space
    if (countSpace != 2) {
        printf("Error\n");
        return 0;
    }


//search for the correct num
    char c = '0';
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (arrRow[i] == '0' && arrColumn[i] == '0') {
            c = (char) (i + 1) + '0';
            board[iChar][jChar] = c;
            //check that the num is not in square
            if (!isSameNumInSquare(board, iChar, jChar)) {
                board[iChar][jChar] = ' ';
            }
        }
    }
    return 1;
}

/******************
* Function Name: completeBoard
* Input: char board[][SIZE * SIZE]
* Output: -
* Function Operation: solve the board if valid.
******************/
void completeBoard(char board[][SIZE * SIZE]) {
    if (!testBoard(board)) {
        printf("Error\n");
        return;
    }

    for (int i = 0; i < SIZE * SIZE; i++) {
        for (int j = 0; j < SIZE * SIZE; j++) {
            if (board[i][j] == ' ') {
                if (!fillCell(board, i, j)) {
                    return;
                }
            }
        }
    }
}










