#include <iostream>
#include<time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80

int get_directionkey()//방향키를 입력받는 함수
{
    int key;
    key = _getch();
    if (key == 224)//방향키
    {
        return _getch(); //어떤 방향 키인지 반환
    }
    return 0;    //방향키가 아님
}

void levelSelectMenu()//게임 레벨 선택 
{
	system("cls");
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
void firstline(int col)
{
	if (col == 3)
	{
		printf("┌━━━┬━━━┬━━━┐\n");
	}
	if (col == 4)
	{
		printf("┌━━━┬━━━┬━━━┬━━━┐\n");
	}
	if (col == 5)
	{
		printf("┌━━━┬━━━┬━━━┬━━━┬━━━┐\n");
	}
}

void midline(int col)
{
	if (col == 3)
	{
		printf("├━━━┼━━━┼━━━┤\n");
	}
	if (col == 4)
	{
		printf("├━━━┼━━━┼━━━┼━━━┤\n");
	}
	if (col == 5)
	{
		printf("├━━━┼━━━┼━━━┼━━━┼━━━┤\n");
	}
}

void lastline(int col)
{
	if (col == 3)
	{
		printf("└━━━┴━━━┴━━━┘\n");
	}
	if (col == 4)
	{
		printf("└━━━┴━━━┴━━━┴━━━┘\n");
	}
	if (col == 5)
	{
		printf("└━━━┴━━━┴━━━┴━━━┴━━━┘\n");
	}
}

int main()
{
	int level;
	Select:;
	levelSelectMenu();
	scanf("%d", &level);
	if(level < 1 || level > 5) goto Select;
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
		for (int i = 0; i < 100; i++)
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
//	int tmp;
	int moved_count = 0;
	int n_row = row - 1;
	int n_col = col - 1;
	
	while (is_end != 0)
    {
	    system("cls");
	    firstline(col);	    
	    for (int i = 0; i < row; i++)
	    {
	        for (int j = 0; j < col; j++)
	        {
	            if (puzzleNum[i][j] == 0)
	            {
	                printf("│   ");
	            }
	            else
	            {
	                printf("│%3d", puzzleNum[i][j]);
	            }	
	        }
	        printf("│\n");
	        if(i == row-1)
	        {
	        	lastline(col);
			}
			else midline(col);
	    }
	    printf("Moved Count : %d\n", moved_count);
        
        printf(">> 방향키로 움직이기\n");
        key = get_directionkey();
        
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
	            if (puzzleNum[i][j] == 0)
	            {
	                printf("│   ");
	            }
	            else
	            {
	                printf("│%3d", puzzleNum[i][j]);
	            }	
	        }
	        printf("│");
	        printf("\n");
	        if(i == row-1)
	        {
	        	lastline(col);
			}
			else midline(col);
	    }
	    printf("Congratulation!\nYou moved %d", moved_count);
}
