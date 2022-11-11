#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80
int n = 3;
void level(int Level) {
    if(Level == 3) {
    	
	}
	if(Level == 4) {
    	n++;
	}
	if(Level == 5) {
    	n++;
    	n++;
	}
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
/*void print_puzzle(int puzzle[3][3])
{
    int r, c;
    system("cls"); //콘솔 화면을 지우기
    for (r = 0; r < n; r++)//열 반복
    {
        for (c = 0; c < n; c++)//행 반복
        {
            if (puzzle[r][c])//참이면(0이 아니면)
            {
                printf("%3d", puzzle[r][c]);//퍼즐의 수를 출력
            }
            else//거짓(0)이면
            {
                printf("   ");//공백 출력
            }

        }
        printf("\n");//개행
    }
}*/
// https://mukppe.tistory.com/1217 문제 예시 
int main()
{
	srand(time(NULL));
	int Level; // 난이도를 입력받는 정수
	scan:;
	printf("\n3 ~ 5 중 입력해 주십시오.\n");
	scanf("%d", &Level);
	if (Level >=3 && Level <= 5)
	{
		level(Level);
	}
	else {
		goto scan;		
	}
	
    int puzzle[n][n] = {0}; // 퍼즐  값 
	int row = n-1;
    int col = n-1;
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
	
	
	while (is_ending != puzzle)
    {
        int r, c;
    	system("cls"); //콘솔 화면을 지우기
    	for (r = 0; r<n; r++)//열 반복
    	{
        	for (c = 0; c<n; c++)//행 반복
        	{
            	if (puzzle[r][c])//참이면(0이 아니면)
            	{
                	printf("%3d", puzzle[r][c]);//퍼즐의 수를 출력
            	}
            	else//거짓(0)이면
            	{
            	    printf("   ");//공백 출력
            	}

        	}
        	printf("\n");//개행
    	}
        printf(">> 방향키 선택 \n");
        key = get_directionkey();

        switch (key)
        {
        case RIGHT:
            if (col>0)
            {
                puzzle[row][col] = puzzle[row][col - 1];
                puzzle[row][col - 1] = 0;
                col--;
            }

            break;
        case LEFT:
            if (col<3 - 1)
            {
                puzzle[row][col] = puzzle[row][col + 1];
                puzzle[row][col + 1] = 0;
                col++;
            }
            break;
        case UP:
            if (row<3 - 1)
            {
                puzzle[row][col] = puzzle[row + 1][col];
                puzzle[row + 1][col] = 0;
                row++;
            }
            break;
        case DOWN:
            if (row>0)
            {
                puzzle[row][col] = puzzle[row - 1][col];
                puzzle[row - 1][col] = 0;
                row--;
            }
            break;
        }
    }
    return 0;


	
}


