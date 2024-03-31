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
	printf("------ɨ����Ϸ------\n");
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
			printf("%c ", board[i][j]);//�ӿո������ӡ����

		}
		printf("\n");

	}
	printf("------ɨ����Ϸ------\n");
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
	printf("������Ҫ�Ų�����꣺\)");
	scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("�����걻�Ų飬�����ظ��Ų�\n");
			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					Display_board(mine, ROW, COL);
					break;
				}

				else
				{
					int count = Get_mine_count(mine, x, y);
					show[x][y] = count + '0';//ת��Ϊ�����ַ�
					Display_board(show, ROW, COL);
				}
			}
			
			
		}
        else
		{
		printf("���곬����Χ������������");
		}
	}
		if(win==row*col - EASY_COUNT)
			printf("��ϲ����Ӯ��\n");
}