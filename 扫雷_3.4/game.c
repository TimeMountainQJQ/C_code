#define _CRT_SECURE_NO_WARNINGS


#include"game.h"

void Init_board(char board[ROWS][COLS], int row, int col,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
				
		}

	}

}

void Display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------扫雷游戏------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);//加空格调整打印界面

		}
		printf("\n");

	}
	printf("------扫雷游戏------\n");
}

void Set_mine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] ='1';
		    count--;
		}
	}
}

int Get_mine_count(char board[ROWS][COLS], int x, int y) 
{
	return(board[x - 1][y] + board[x - 1][y - 1] +
		board[x][y - 1] + board[x + 1][y - 1] +
		board[x + 1][y] + board[x + 1][y + 1] +
		board[x][y + 1] + board[x - 1][y + 1] - 8 * '0');

}








void Find_mine(char	mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- EASY_COUNT)
	{
		win++;
	printf("请输入要排查的坐标：\)");
	scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标被排查，不能重复排查\n");
			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					Display_board(mine, ROW, COL);
					break;
				}

				else
				{
					int count = Get_mine_count(mine, x, y);
					show[x][y] = count + '0';//转化为数字字符
					Display_board(show, ROW, COL);
				}
			}
			
			
		}
        else
		{
		printf("坐标超过范围，请重新输入");
		}
	}
		if(win==row*col - EASY_COUNT)
			printf("恭喜，你赢了\n");
}