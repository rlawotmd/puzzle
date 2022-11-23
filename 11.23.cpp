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

void levelSelectMenu()//게임 레벨 선택 화면  
{
	system("cls");
	printf("\n\n\n");
	printf("		   ┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("		   ┃     Sliding Puzzle     ┃\n");
	printf("		   ┃                        ┃\n");
	printf("		   ┃        1. 3 X 3        ┃\n");
	printf("		   ┃                        ┃\n");
	printf("		   ┃        2. 3 X 4        ┃\n");
	printf("		   ┃                        ┃\n");
	printf("		   ┃        3. 4 X 4        ┃\n");
	printf("		   ┃                        ┃\n");
	printf("		   ┃        4. 4 X 5        ┃\n");
	printf("		   ┃                        ┃\n");
	printf("		   ┃        5. 5 X 5        ┃\n");
	printf("		   ┃                        ┃\n");
	printf("		   ┃        Q. 종료         ┃\n");
	printf("		   ┃                        ┃\n");
	printf("		   ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("		      <<Press the number >>");
} 
void firstline(int col) //퍼즐 시작 라인 
{
	if (col == 3)
	{
		printf("\n\n		   ┌━━━┬━━━┬━━━┐\n");
	}
	if (col == 4)
	{
		printf("\n\n		   ┌━━━┬━━━┬━━━┬━━━┐\n");
	}
	if (col == 5)
	{
		printf("\n\n		   ┌━━━┬━━━┬━━━┬━━━┬━━━┐\n");
	}
}

void midline(int col) // 퍼즐 중간 라인 
{
	if (col == 3)
	{
		printf("		   ├━━━┼━━━┼━━━┤\n");
	}
	if (col == 4)
	{
		printf("		   ├━━━┼━━━┼━━━┼━━━┤\n");
	}
	if (col == 5)
	{
		printf("		   ├━━━┼━━━┼━━━┼━━━┼━━━┤\n");
	}
}

void lastline(int col) // 퍼즐 끝 라인  
{
	if (col == 3)
	{
		printf("		   └━━━┴━━━┴━━━┘\n");
	}
	if (col == 4)
	{
		printf("		   └━━━┴━━━┴━━━┴━━━┘\n");
	}
	if (col == 5)
	{
		printf("		   └━━━┴━━━┴━━━┴━━━┴━━━┘\n");
	}
}
void how_to() // 게임 설명  
{
	printf("\n");
	printf("		     방향키로 움직이기\n");
	printf("   ↑ : 빈칸을 기준으로 아래쪽에 있는 숫자 빈칸으로 옮기기\n");
	printf("   ← : 빈칸을 기준으로 오른쪽에 있는 숫자 빈칸으로 옮기기\n");
	printf("   → : 빈칸을 기준으로 왼쪽에 있는 숫자 빈칸으로 옮기기\n");
	printf("   ↓ : 빈칸을 기준으로 위쪽에 있는 숫자 빈칸으로 옮기기\n\n");
	printf("   Q : 레벨 선택으로 돌아가기");
}

int main()
{
	system("title Sliding Puzzle"); // 콘솔창 이름 설정  
	system("mode con: cols=65 lines=25"); // 콘솔창 크기 설정  

	CONSOLE_CURSOR_INFO cursorInfo = { 0, }; // 콘솔창 커서 깜박임 끄기  
	cursorInfo.bVisible = 0; 
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	
	int level;
	Select:;
	levelSelectMenu();
	level = getch(); // 레벨 선택 입력 받기 
	if(level == 'q' || level == 'Q')
	{
		exit(0);
	} 
	level -= '0';
	
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
	
		int puzzleNum[row][col] = {0}; // 퍼즐 기본 값 생성  
		int number = 1;		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				puzzleNum[i][j] = number;
				number++;
			}			
		}
		puzzleNum[row-1][col-1] = 0; // 마지막 제일 큰값 '0'으로 설정  
		
		int tmp;
		for (int i = 0; i < 5000; i++) // 섞기  
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
		
		for(int a = 0; a < col; a++) // 왼쪽으로 다 밀기  
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
			for (int i = 0; i < row; i++) // 위쪽으로 다 밀기  
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
	
	int ending[row][col]; // 답지 만들기  
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
	
	while (is_end != 0) // 게임 시작  
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
			case Q :
				{
					goto Select;
				}
			case q :
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
	// 종료 
	the_END:; 
	system("cls");
	printf("\n\n\n");
	firstline(col);	    
	for (int i = 0; i < row; i++)
	{
	    for (int j = 0; j < col; j++)
	    {
	        if(j == 0) printf("		   ");
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
	printf("\n\n		   Congratulation!\n		You moved %d times!\n", moved_count);
	printf("\n\n		S. 레벨 선택으로 돌아가기\n\n			Q. 종료");
	
	int keep = getch();
	
	if(keep == 'q' || keep == 'Q') exit(0);
	
	if(keep == 's' || keep == 'S') goto Select;
	
	else goto the_END;
	
}
