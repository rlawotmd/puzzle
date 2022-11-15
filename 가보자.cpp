#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80
int row = 3;
int col = 3;
void setlevel(int n)
{
	if(n == 1)
	{
	}
	if(n == 2)
	{
		col++;
	}
	if(n == 3)
	{
		row++;
		col++;
	}
	if(n == 4)
	{
		row++;
		col++;
		col++;
	}
	if(n == 5)
	{
		row++;
		row++;
		col++;
		col++;
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

int main()
{
	srand(time(NULL));
	int level; // 난이도를 입력받는 정수
	scan:;
	printf("\n3 ~ 5 중 입력해 주십시오.\n");
	scanf("%d", &level);
	if (level < 1 || level > 5)
	{
		system("cls");
		goto Select;
	}
	setlevel(level);
	
    int puzzle[row][col] = {0}; // 퍼즐  값 
	int n = col;
    int key = 0;
    int num_Length = n*n; 
	int game_num = num_Length - 1;
    int oneline[num_Length] = {0};
    int newline[num_Length] = {0}; 
    int rand_num;
    
    
    //1 ~ n * n 까지의 중복 없는 난수 생 성 
    for(int i = 0; i < num_Length; i++) {
		oneline[i] = rand()%num_Length+1;
		for(int j = 0; j < i; j++) {
			if(oneline[i] == oneline[j])
			i--;				
			}
		}
	
	// 난수 중 제일 큰값 0으로 변 경 
	for(int i = 0; i < num_Length; i++) {
		if(oneline[i] == num_Length)
		{
			i++;
			}
			newline[i] = oneline[i];				
		}
	
		for(int i = 0; i < num_Length; i++)
			printf("%d\n", newline[i]); 
			
	// 제일 큰값 없앤 값 퍼즐에 넣기 
	int one_ = 0;		
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(0 == newline[one_]) one_++;
			puzzle[i][j] = newline[one_];
			one_++;
		}
	}
	puzzle[n-1][n-1] = 0;
    
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%3d ", puzzle[i][j]);
		}
		printf("\n");
	}
	int is_ending[n][n];
	int r, c;

    for (r = 0; r<n; r++)//열 반복
    {
        for (c = 0; c<n; c++)//행 반복
        {
        	if((r * n + c + 1) == (n*n)) break;
            is_ending[r][c] = r * n + c + 1;
        }
    }
    is_ending[n-1][n-1] = 0;



	
}
