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
	char mine[COLS][ROWS] = { 0 };//��Ų��úõ��׵���Ϣ
	char show[COLS][ROWS] = { 0 };//����Ų�����׵���Ϣ
	//��ʼ�����������Ϊָ��������
	//mine ������û�в����׵�ʱ����'0'
	Init_board(mine, ROWS, COLS,'0');
	//show ������û���Ų��ʱ����'*'
	Init_board(show, ROWS, COLS, '*');

	//������
	Set_mine(mine, ROW, COL);

	//Display_board(mine, ROW, COL);
	//��ӡ��ʼɨ������
	
	Display_board(show, ROW, COL);

	//�Ų���
	Find_mine(mine,show,ROW,COL);
	
}




int main()
{
	srand((unsigned int)time(NULL));//����������������
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}

	}



	while (input);


	return 0;
}