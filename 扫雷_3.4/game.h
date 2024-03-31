#pragma once

#include<stdio.h>
#include<time.h>

#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void Init_board(char board[ROWS][COLS], int row, int col,char set);

void Display_board(char board[ROWS][COLS], int row, int col);

void Set_mine(char board[ROWS][COLS], int row, int col);

void Find_mine(char	mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);