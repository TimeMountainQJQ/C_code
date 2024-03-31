#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
void menu()
{
	printf("***********************\n");
	printf("****1.play   0.exit****\n");
	printf("***********************\n");
}
void game()
{
	char mine[COLS][ROWS] = { 0 };//存放布置好的雷的信息
	char show[COLS][ROWS] = { 0 };//存放排查出的雷的信息
	//初始化数组的内容为指定的内容
	//mine 数组在没有布置雷的时候都是'0'
	Init_board(mine, ROWS, COLS,'0');
	//show 数组在没有排查的时候都是'*'
	Init_board(show, ROWS, COLS, '*');

	//设置雷
	Set_mine(mine, ROW, COL);

	//Display_board(mine, ROW, COL);
	//打印初始扫雷棋盘
	
	Display_board(show, ROW, COL);

	//排查雷
	Find_mine(mine,show,ROW,COL);
	
}




int main()
{
	srand((unsigned int)time(NULL));//设置随机数生成起点
	int input = 0;
	do
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}

	}



	while (input);


	return 0;
}