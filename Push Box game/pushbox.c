/*
��������Ϸ
c
��ʵ��
�����������֣�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"pushbox.h"

int main()
{
	int n, m;
	int x1, y1, x2, y2;
	int step=0;
	system("title ��������Ϸ(������)");
	memcpy(map, map_first, sizeof(map_first));
	game_main_UI();
	system("pause");
	system("cls");//����
	n = count1();
	while (1)
	{
		system("cls");
		output();
		m = count2();
		find();
		switch (getch())
		{
		case 'w':
			x1 = -1;
			y1 = 0;
			x2 = -2;
			y2 = 0;
			if (act(x1, y1, x2, y2))
				step++;
			break;
		case 'a':
			x1 = 0;
			y1 = -1;
			x2 = 0;
			y2 = -2;
			if (act(x1, y1, x2, y2))
				step++;
			break;
		case 's':
			x1 = 1;
			y1 = 0;
			x2 = 2;
			y2 = 0;
			if (act(x1, y1, x2, y2))
				step++;
			break;
		case 'd':
			x1 = 0;
			y1 = 1;
			x2 = 0;
			y2 = 2;
			if (act(x1, y1, x2, y2))
				step++;
			break;
		case 'r':
			memcpy(map, map_first, sizeof(map_first));
			break;
		case 'p':
			printf("\n ����ֹ����Ϸ��\n");
			printf("��һ������%d", step);
			printf("��\n");
			system("pause");
			return 0;
		}
		if (n == m)
		{
			printf("\n��Ϸ���� you win��\n");
			printf("��һ������%d", step);
			printf("��\n");
			system("pause");
			return 0;
		}
	}
	system("pause");
}