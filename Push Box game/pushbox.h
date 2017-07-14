/*
推箱子游戏
c
简单实现
（头文件部分）
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> 
int map_first[9][9] = {
	{ 1,1,1,1,1,0,0,0,0 },
	{ 1,0,0,0,1,0,0,0,0 },
	{ 1,0,2,0,1,0,1,1,1 },
	{ 1,0,2,0,1,0,1,4,1 },
	{ 1,1,1,0,1,1,1,4,1 },
	{ 0,1,1,0,0,0,0,4,1 },
	{ 0,1,0,2,0,1,0,0,1 },
	{ 0,1,0,0,3,1,1,1,1 },
	{ 0,1,1,1,1,1,0,0,0 }
};//定义初始的游戏界面
  //1代表墙2是箱子3是玩家4是目标点5是已移入箱子的目标点
int map[9][9] = { 0 };
int i, j;//坐标
int count1();	//箱子还未到达的最终位置的个数
int count2();	//箱子已到达的最终位置的个数
int find();		//找到玩家位置
int output();	//输出图画
int act(int x1, int y1, int x2, int y2);//操作

int count1()
{
	int n = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (map[i][j] == 4)
				n++;;
		}
	}
	return n;
}
int count2()
{
	int m = 0;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (map[i][j] == 5)
				m++;
		}
	}
	return m;
}

//找到玩家位置
int find()
{
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (map[i][j] == 3||map[i][j]==6)
				return 0;
		}
	}
	return 0;
}

//输出图画
int output()
{
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (map[i][j] == 0)
				printf("  ");//输出空格
			if (map[i][j] == 1) 
				printf("■");//输出墙的砖块
			if (map[i][j] == 2)
				printf("□");//输出箱子
			if (map[i][j] == 3)
				printf("我");//输出在空格上的玩家
			if (map[i][j] == 4)
				printf("☆");//输出目标点
			if (map[i][j] == 5)
				printf("★");//输出已入箱子的目标点
			if (map[i][j] == 6)
				printf("我");//输出在目标点上的玩家
		}
		printf("\n");
	}
	return 0;
}

//游戏主界面
int game_main_UI()
{
	printf("--------------------------------\n"
	"请按任意键游戏开始\n"
	"制作：ledgil\n"
	"请按wasd键控制上左下右\n"
	"请按r键重新开始游戏\n"
	"请按p键退出游戏\n"
	"--------------------------------\n");
	return 0;
}

/*
1---墙
2---箱子
3---在空格上的玩家
4---目标点
5---已入箱子的目标点
6---在目标点上的玩家

玩家在空格上
		玩家前是0，0变3，3变0
		玩家前是4，4变6，3变0
		玩家前是2
				箱子前是0，0变2，2变3，3变0
				箱子前是4，4变5，2变3，3变0
		玩家前是5
				箱子前是0，0变2，5变6，3变0
				箱子前是4，4变5，5变6，3变0
玩家在目标点上
		玩家前是0，0变3，6变4
		玩家前是4，4变6，6变4
		玩家前是2
				箱子2前是0，0变2，2变3，6变4
				箱子2前是4，4变5，2变3，6变4
		玩家前是5
				箱子5前是0，0变2，5变6，6变4
				箱子5前是4，4变5，5变6，6变4
*/
int act(int x1,int y1,int x2,int y2)
{
	/*玩家在空格上
		玩家前是0，0变3，3变0
		玩家前是4，4变6，3变0*/
	if (map[i][j] == 3)
	{
		if (map[i + x1][j + y1] == 0)
		{
			map[i + x1][j + y1] = 3;
			map[i][j] = 0;
			return 1;
		}
		if (map[i + x1][j + y1] == 4)
		{
			map[i + x1][j + y1] = 6;
			map[i][j] = 0;
			return 1;
		}
		/*玩家前是2
				箱子前是0，0变2，2变3，3变0
				箱子前是4，4变5，2变3，3变0
		*/
		if (map[i + x1][j + y1] == 2)
		{
			if (map[i + x2][j + y2] == 0)
			{
				map[i + x2][j + y2] = 2;
				map[i + x1][j + y1] = 3;
				map[i][j] = 0;
				return 1;
			}
			else if (map[i + x2][j + y2] == 4)
			{
				map[i + x2][j + y2] = 5;
				map[i + x1][j + y1] = 3;
				map[i][j] = 0;
				return 1;
			}
		}
		/*玩家前是5
		箱子前是0，0变2，5变6，3变0
		箱子前是4，4变5，5变6，3变0*/
		if (map[i + x1][j + y1] == 5)
		{
			if (map[i + x2][j + y2] == 0)
			{
				map[i + x2][j + y2] = 2;
				map[i + x1][j + y1] = 6;
				map[i][j] = 0;
				return 1;
			}
			else if (map[i + x2][j + y2] == 4)
			{
				map[i + x2][j + y2] = 5;
				map[i + x1][j + y1] = 6;
				map[i][j] = 0;
				return 1;
			}
		}
	}
	/*玩家在目标点上
		玩家前是0，0变3，6变4
		玩家前是4，4变6，6变4*/
	if (map[i][j] == 6)
	{
		if (map[i + x1][j + y1] == 0)
		{
			map[i + x1][j + y1] = 3;
			map[i][j] = 4;
			return 1;
		}
		if (map[i + x1][j + y1] == 4)
		{
			map[i + x1][j + y1] = 6;
			map[i][j] = 4;
			return 1;
		}
		/*	玩家前是2
				箱子2前是0，0变2，2变3，6变4
				箱子2前是4，4变5，2变3，6变4
		*/
		if (map[i + x1][j + y1] == 2)
		{
			if (map[i + x2][j + y2] == 0)
			{
				map[i + x2][j + y2] = 2;
				map[i + x1][j + y1] = 3;
				map[i][j] = 4;
				return 1;
			}
			else if (map[i + x2][j + y2] == 4)
			{
				map[i + x2][j + y2] = 5;
				map[i + x1][j + y1] = 3;
				map[i][j] = 4;
				return 1;
			}
		}
		/*玩家前是5
				箱子5前是0，0变2，5变6，6变4
				箱子5前是4，4变5，5变6，6变4*/
		if (map[i + x1][j + y1] == 5)
		{
			if (map[i + x2][j + y2] == 0)
			{
				map[i + x2][j + y2] = 2;
				map[i + x1][j + y1] = 6;
				map[i][j] = 4;
				return 1;
			}
			else if (map[i + x2][j + y2] == 4)
			{
				map[i + x2][j + y2] = 5;
				map[i + x1][j + y1] = 6;
				map[i][j] = 4;
				return 1;
			}
		}
	}
	return 0;
}