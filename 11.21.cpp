#include <iostream>
#include<time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80
#define Q	113
#define q	81

void levelSelectMenu()//啪歜 溯漣 摹鷗 
{
	system("cls");
	printf("\n\n\n");
	printf("		   旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("		   早      蝸塭檜註 ぷ闌	    早\n");
	printf("		   早                        早\n");
	printf("		   早        1. 3 X 3        早\n");
	printf("		   早                        早\n");
	printf("		   早        2. 3 X 4        早\n");
	printf("		   早                        早\n");
	printf("		   早        3. 4 X 4        早\n");
	printf("		   早                        早\n");
	printf("		   早        4. 4 X 5        早\n");
	printf("		   早                        早\n");
	printf("		   早        5. 5 X 5        早\n");
	printf("		   早                        早\n");
	printf("		   早        6. 謙猿         早\n");
	printf("		   早                        早\n");
	printf("		   曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("			<<Press the number >>");
} 
void firstline(int col)
{
	if (col == 3)
	{
		printf("\n\n		   忙收收收成收收收成收收收忖\n");
	}
	if (col == 4)
	{
		printf("\n\n		   忙收收收成收收收成收收收成收收收忖\n");
	}
	if (col == 5)
	{
		printf("\n\n		   忙收收收成收收收成收收收成收收收成收收收忖\n");
	}
}

void midline(int col)
{
	if (col == 3)
	{
		printf("		   戍收收收托收收收托收收收扣\n");
	}
	if (col == 4)
	{
		printf("		   戍收收收托收收收托收收收托收收收扣\n");
	}
	if (col == 5)
	{
		printf("		   戍收收收托收收收托收收收托收收收托收收收扣\n");
	}
}

void lastline(int col)
{
	if (col == 3)
	{
		printf("		   戌收收收扛收收收扛收收收戎\n");
	}
	if (col == 4)
	{
		printf("		   戌收收收扛收收收扛收收收扛收收收戎\n");
	}
	if (col == 5)
	{
		printf("		   戌收收收扛收收收扛收收收扛收收收扛收收收戎\n");
	}
}
void how_to()
{
	printf("\n");
	printf("		酈爾萄 寞щ酈煎 遺霜檜晦\n");
	printf("   ∟ : 綴蘊擊 晦遽戲煎 嬴楚薹縑 氈朝 璋濠 綴蘊戲煎 衡晦晦\n");
	printf("   ∠ : 綴蘊擊 晦遽戲煎 螃艇薹縑 氈朝 璋濠 綴蘊戲煎 衡晦晦\n");
	printf("   ⊥ : 綴蘊擊 晦遽戲煎 豭薹縑 氈朝 璋濠 綴蘊戲煎 衡晦晦\n");
	printf("   ⊿ : 綴蘊擊 晦遽戲煎 嬪薹縑 氈朝 璋濠 綴蘊戲煎 衡晦晦\n\n");
	printf("   Q : 溯漣 摹鷗戲煎 給嬴陛晦");
}

int main()
{
	system("title Sliding Puzzle");
	system("mode con: cols=65 lines=25");
	
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	
	int level;
	Select:;
	levelSelectMenu();
	level = getch(); 
	level -= '0';
	
	if(level < 1 || level > 6) goto Select;
	int row, col;
	
	if(level == 1)
	{
		row = 3;
		col = 3;
	}
	if(level == 2)
	{
		row = 3;
		col = 4;
	}
	if(level == 3)
	{
		row = 4;
		col = 4;
	}
	if(level == 4)
	{
		row = 4;
		col = 5;
	}
	if(level == 5)
	{
		row = 5;
		col = 5;
	}
	if(level == 6)
	{
		return 0;
	}
	
	srand((unsigned int)time(NULL));
	
		int puzzleNum[row][col] = {0};
		int number = 1;
		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				puzzleNum[i][j] = number;
				number++;
			}			
		}
		puzzleNum[row-1][col-1] = 0;
		
		int tmp;
		for (int i = 0; i < 5000; i++)
		{
			int rand_num = rand() % 4;
			if (rand_num == 0)
			{
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						if (puzzleNum[i][j] == 0 && j > 0)
						{
							tmp = puzzleNum[i][j];
							puzzleNum[i][j] = puzzleNum[i][j - 1];
							puzzleNum[i][j - 1] = tmp;
							break;
						}
					}
				}
			}
			else if (rand_num == 1)
			{
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						if (puzzleNum[i][j] == 0 && j < col-1)
						{
							tmp = puzzleNum[i][j];
							puzzleNum[i][j] = puzzleNum[i][j + 1];
							puzzleNum[i][j + 1] = tmp;
							break;
						}
					}
				}
			}
			
			else if (rand_num == 2)
			{
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						if (puzzleNum[i][j] == 0 && i < row - 1)
						{
							tmp = puzzleNum[i][j];
							puzzleNum[i][j] = puzzleNum[i + 1][j];
							puzzleNum[i + 1][j] = tmp;
							break;
						}
					}
				}
			}
			
			else if (rand_num == 3)
			{
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						if (puzzleNum[i][j] == 0 && i > 0)
						{
							tmp = puzzleNum[i][j];
							puzzleNum[i][j] = puzzleNum[i - 1][j];
							puzzleNum[i - 1][j] = tmp;
							break;
						}
					}
				}
			}
		}
		
		for(int a = 0; a < col; a++)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (puzzleNum[i][j] == 0 && i < row - 1)
					{
						tmp = puzzleNum[i][j];
						puzzleNum[i][j] = puzzleNum[i + 1][j];
						puzzleNum[i + 1][j] = tmp;
						break;
					}
				}
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (puzzleNum[i][j] == 0 && j < col-1)
					{
						tmp = puzzleNum[i][j];
						puzzleNum[i][j] = puzzleNum[i][j + 1];
						puzzleNum[i][j + 1] = tmp;
						break;
					}
				}
			}
		}
	
	int ending[row][col];
	int ans_num = 1;	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			ending[i][j] = ans_num;
			ans_num++;			
		}
	}
	ending[row-1][col-1] = 0;
	
	int is_end = row*col;
	int key = 0;
	int moved_count = 0;
	int n_row = row - 1;
	int n_col = col - 1;
	
	while (is_end != 0)
    {
    	system("cls");
    	printf("\n\n					   Moved Count : %d\n", moved_count);
	    firstline(col);	    
	    for (int i = 0; i < row; i++)
	    {
	        for (int j = 0; j < col; j++)
	        {
	        	if(j == 0) printf("		   ");
	            if (puzzleNum[i][j] == 0)
	            {
	                printf("弛   ");
	            }
	            else
	            {
	                printf("弛%3d", puzzleNum[i][j]);
	            }	
	        }
	        printf("弛\n");
	        if(i == row-1)
	        {
	        	lastline(col);
			}
			else midline(col);
	    }
        how_to();
		
		key = _getch();
        
        switch(key)
        {
	        case RIGHT:
			{
				if (n_col > 0)
	            {
	                puzzleNum[n_row][n_col] = puzzleNum[n_row][n_col - 1];
	                puzzleNum[n_row][n_col - 1] = 0;
	                n_col--;
	                moved_count++;
	            }
	            break;
			}
			case LEFT:
			{
				if (n_col< col - 1)
	            {
	                puzzleNum[n_row][n_col] = puzzleNum[n_row][n_col + 1];
	                puzzleNum[n_row][n_col + 1] = 0;
	                n_col++;
	                moved_count++;
	            }
	            break;
			}
			
			case UP:
			{
				if (n_row < row - 1)
	            {
	                puzzleNum[n_row][n_col] = puzzleNum[n_row + 1][n_col];
	                puzzleNum[n_row + 1][n_col] = 0;
	                n_row++;
	                moved_count++;
	            }
	            break;
			}
			
			case DOWN:
			{
				if (n_row > 0)
	            {
	                puzzleNum[n_row][n_col] = puzzleNum[n_row - 1][n_col];
	                puzzleNum[n_row - 1][n_col] = 0;
	                n_row--;
	                moved_count++;
	            }
            break;
			}
			case Q:
				{
					goto Select;
				}
			case q:
				{
					goto Select;
				}
		}			
			
			is_end = row*col;
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < col; j++)
				{
					if(ending[i][j] == puzzleNum[i][j])
					{
						is_end--;
					}
				}
			}
		}
	
	system("cls");
	firstline(col);	    
	    for (int i = 0; i < row; i++)
	    {
	        for (int j = 0; j < col; j++)
	        {
	        	if(j == 0) printf("		   ");
	            if (puzzleNum[i][j] == 0)
	            {
	                printf("弛   ");
	            }
	            else
	            {
	                printf("弛%3d", puzzleNum[i][j]);
	            }	
	        }
	        printf("弛");
	        printf("\n");
	        if(i == row-1)
	        {
	        	lastline(col);
			}
			else midline(col);
	    }
	    printf("Congratulation!\nYou moved %d times!", moved_count);
}
