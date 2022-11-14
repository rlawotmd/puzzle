#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80
int col, row;
int moved;
void make_game(int level)
{
	srand(time(NULL));
	int rand_num = rand()%10+1;
	
	if(level == 1)
	{
		col = 3;
		row = 3;
		int oneline[9] = {0};
		switch(rand_num)
		{
			case 1:
				oneline[9] = {4, 3, 2, 8, 7, 6, 5, 1, 0};
				break;
			case 2:
				oneline[9] = {7, 8, 6, 1, 3, 2, 4, 5, 0};
				break;
			case 3:
				oneline[9] = {6, 2, 4, 3, 8, 1, 5, 7, 0};
				break;
			case 4:
				oneline[9] = {4, 6, 2, 7, 3, 8, 1, 5, 0};
				break;
			case 5:
				oneline[9] = {5, 7, 2, 1, 4, 8, 6, 3, 0};
				break;
			case 6:
				oneline[9] = {2, 6, 1, 3, 8, 5, 7, 4, 0};
				break;
			case 7:
				oneline[9] = {1, 6, 8, 3, 2, 5, 7, 4, 0};
				break;
			case 8:
				oneline[9] = {5, 7, 8, 4, 3, 1, 6, 2, 0};
				break;
			case 9:
				oneline[9] = {2, 3, 6, 1, 4, 7, 5, 8, 0};
				break;
			case 10:
				oneline[9] = {6, 5, 2, 3, 4, 7, 8, 1, 0};
				break;
		}
	}
	if(level == 2)
	{
		col = 3;
		row = 4;
		int oneline[12]= {0};
		switch(rand_num)
		{
			case 1:
				oneline[12] = {10, 8, 3, 9, 2, 11, 1, 5, 4, 7, 6, 0};
				break;
			case 2:
				oneline[12] = {5, 7, 6, 4, 8, 2, 11, 10, 3, 1, 9, 0};
				break;
			case 3:
				oneline[12] = {4, 3, 1, 6, 11, 9, 8, 10, 2, 7, 5, 0};
				break;
			case 4:
				oneline[12] = {1, 3, 2, 5, 4, 9, 11, 7, 6, 8, 10, 0};
				break;
			case 5:
				oneline[12] = {4, 7, 9, 2, 1, 3, 11, 6, 10, 5, 8, 0};
				break;
			case 6:
				oneline[12] = {6, 10, 8, 4, 1, 9, 3, 11, 5, 7, 2, 0};
				break;
			case 7:
				oneline[12] = {7, 4, 11, 5, 8, 1, 10, 2, 9, 3, 6, 0};
				break;
			case 8:
				oneline[12] = {2, 9, 5, 1, 3, 10, 8, 7, 4, 6, 11, 0};
				break;
			case 9:
				oneline[12] = {2, 6, 4, 5, 8, 10, 1, 9, 3, 7, 11, 0};
				break;
			case 10:
				oneline[12] = {2, 3, 1, 7, 11, 9, 5, 6, 8, 4, 10, 0};
				break;
		}
	}
	if(level == 3)
	{
		col = 4;
		row = 4;
		int oneline[16]= {0};
		switch(rand_num)
		{
			case 1:
				oneline[16] = {10, 4, 3, 5, 14, 13, 6, 9, 12, 1, 2, 15, 8, 7, 11, 0};
				break;
			case 2:
				oneline[16] = {12, 3, 15, 4, 2, 14, 9, 5, 11, 13, 8, 7, 6, 10, 1, 0};
				break;
			case 3:
				oneline[16] = {2, 5, 6, 12, 9, 1, 7, 14, 13, 4, 11, 15, 3, 8, 10, 0};
				break;
			case 4:
				oneline[16] = {2, 15, 7, 5, 1, 11, 10, 14, 6, 12, 9, 8, 13, 4, 3, 0};
				break;
			case 5:
				oneline[16] = {14, 5, 11, 13, 12, 2, 9, 15, 7, 1, 3, 6, 4, 8, 10, 0};
				break;
			case 6:
				oneline[16] = {2, 7, 14, 6, 12, 3, 4, 1, 11, 8, 9, 13, 15, 10, 5, 0};
				break;
			case 7:
				oneline[16] = {1, 6, 14, 2, 9, 15, 10, 12, 5, 13, 8, 3, 11, 4, 7, 0};
				break;
			case 8:
				oneline[16] = {15, 12, 8, 1, 2, 9, 3, 4, 11, 10, 14, 13, 7, 6, 5, 0};
				break;
			case 9:
				oneline[16] = {14, 4, 12, 7, 15, 3, 8, 13, 1, 9, 2, 6, 10, 11, 5, 0};
				break;
			case 10:
				oneline[16] = {6, 10, 9, 8, 3, 15, 5, 7, 1, 13, 2, 11, 12, 14, 4, 0};
				break;
		}
	}
	if(level == 4)
	{
		col = 4;
		row = 5;
		int oneline[20]= {0};
		switch(rand_num)
		{
			case 1:
				oneline[20] = {10, 5, 17, 15, 11, 9, 4, 13, 12, 19, 1, 7, 16, 14, 2, 6, 8, 18, 3, 0};
				break;
			case 2:
				oneline[20] = {17, 7, 11, 8, 10, 13, 18, 12, 15, 19, 16, 1, 3, 5, 4, 9, 2, 14, 6, 0};
				break;
			case 3:
				oneline[20] = {18, 17, 8, 6, 19, 9, 3, 4, 13, 7, 16, 14, 12, 5, 10, 1, 2, 11, 15, 0};
				break;
			case 4:
				oneline[20] = {1, 12, 7, 15, 18, 5, 8, 4, 19, 2, 3, 17, 16, 9, 13, 10, 6, 11, 14, 0};
				break;
			case 5:
				oneline[20] = {6, 16, 17, 14, 10, 5, 13, 15, 11, 7, 19, 4, 8, 18, 3, 2, 12, 1, 9, 0};
				break;
			case 6:
				oneline[20] = {7, 14, 11, 16, 8, 10, 15, 13, 17, 18, 3, 6, 2, 19, 5, 12, 1, 4, 9, 0};
				break;
			case 7:
				oneline[20] = {7, 14, 19, 4, 12, 5, 18, 1, 17, 3, 10, 15, 11, 13, 6, 8, 9, 16, 2, 0};
				break;
			case 8:
				oneline[20] = {10, 14, 2, 1, 16, 3, 4, 9, 15, 17, 19, 18, 5, 8, 13, 11, 7, 12, 6, 0};
				break;
			case 9:
				oneline[20] = {18, 17, 12, 11, 2, 19, 9, 6, 3, 14, 1, 13, 10, 8, 15, 16, 4, 7, 5, 0};
				break;
			case 10:
				oneline[20] = {8, 13, 5, 7, 1, 10, 15, 17, 16, 2, 11, 19, 14, 3, 9, 4, 18, 12, 6, 0};
				break;
		}
	}
	if(level == 5)
	{
		col = 5;
		row = 5;
		int oneline[25]= {0};
		switch(rand_num)
		{
			case 1:
				oneline[25] = {5, 11, 2, 14, 3, 10, 13, 22, 20, 19, 17, 15, 21, 24, 4, 6, 8, 18, 23, 16, 9, 1, 7, 12, 0};
				break;
			case 2:
				oneline[25] = {9, 17, 23, 15, 16, 20, 22, 11, 3, 1, 19, 13, 6, 14, 4, 24, 18, 12, 2, 10, 7, 21, 5, 8, 0};
				break;
			case 3:
				oneline[25] = {6, 22, 5, 1, 9, 14, 24, 11, 19, 3, 17, 16, 23, 10, 18, 15, 8, 2, 4, 12, 21, 7, 20, 13, 0};
				break;
			case 4:
				oneline[25] = {15, 2, 1, 3, 24, 14, 6, 7, 18, 13, 12, 20, 22, 9, 19, 17, 5, 10, 4, 16, 23, 21, 8, 11, 0};
				break;
			case 5:
				oneline[25] = {14, 15, 21, 1, 19, 20, 16, 9, 8, 18, 11, 23, 13, 6, 7, 12, 17, 22, 2, 4, 24, 3, 10, 5, 0};
				break;
			case 6:
				oneline[25] = {11, 5, 6, 21, 15, 12, 19, 10, 22, 14, 13, 17, 2, 3, 1, 23, 4, 24, 16, 18, 8, 20, 7, 9, 0};
				break;
			case 7:
				oneline[25] = {17, 1, 16, 4, 6, 12, 9, 3, 21, 19, 20, 22, 15, 11, 5, 23, 18, 8, 14, 13, 7, 2, 10, 24, 0};
				break;
			case 8:
				oneline[25] = {7, 3, 23, 12, 16, 20, 8, 4, 14, 5, 21, 19, 13, 15, 18, 10, 2, 17, 1, 9, 6, 22, 11, 24, 0};
				break;
			case 9:
				oneline[25] = {19, 10, 23, 14, 13, 21, 4, 3, 11, 22, 15, 18, 17, 8, 16, 6, 20, 12, 24, 7, 5, 1, 2, 9, 0};
				break;
			case 10:
				oneline[25] = {17, 23, 16, 8, 20, 5, 11, 1, 2, 15, 6, 22, 3, 13, 14, 9, 18, 24, 21, 10, 7, 12, 4, 19, 0};
				break;
		}
	}
}
void levelSelectMenu()//게임 레벨 선택 화면 
{
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃      슬라이딩 퍼즐	 ┃\n");
	printf("┃                        ┃\n");
	printf("┃        1. 3 X 3        ┃\n");
	printf("┃                        ┃\n");
	printf("┃        2. 3 X 4        ┃\n");
	printf("┃                        ┃\n");
	printf("┃        3. 4 X 4        ┃\n");
	printf("┃                        ┃\n");
	printf("┃        4. 4 X 5        ┃\n");
	printf("┃                        ┃\n");
	printf("┃        5. 5 X 5        ┃\n");
	printf("┃                        ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf(" Select > ");
} 

int main()
{

	srand(time(NULL));
	Select:;
	levelSelectMenu(); //게임 레벨 선택
	
	int level;			// 레벨 지 정 
	scanf("%d", &level);
	if (level < 1 || level > 5)
	{
		system("cls");
		goto Select;
	}
	
	make_game(level);
}

