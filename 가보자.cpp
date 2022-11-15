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
void levelSelectMenu()//���� ���� ���� ȭ�� 
{
	printf("����������������������������������������������������\n");
	printf("��      �����̵� ����	 ��\n");
	printf("��                        ��\n");
	printf("��        1. 3 X 3        ��\n");
	printf("��                        ��\n");
	printf("��        2. 3 X 4        ��\n");
	printf("��                        ��\n");
	printf("��        3. 4 X 4        ��\n");
	printf("��                        ��\n");
	printf("��        4. 4 X 5        ��\n");
	printf("��                        ��\n");
	printf("��        5. 5 X 5        ��\n");
	printf("��                        ��\n");
	printf("����������������������������������������������������\n");
	printf(" Select > ");
} 
int get_directionkey()//����Ű�� �Է¹޴� �Լ�
{
    int key;
    key = _getch();
    if (key == 224)//����Ű
    {
        return _getch(); //� ���� Ű���� ��ȯ
    }
    return 0;    //����Ű�� �ƴ�
}

int main()
{
	srand(time(NULL));
	int level; // ���̵��� �Է¹޴� ����
	scan:;
	printf("\n3 ~ 5 �� �Է��� �ֽʽÿ�.\n");
	scanf("%d", &level);
	if (level < 1 || level > 5)
	{
		system("cls");
		goto Select;
	}
	setlevel(level);
	
    int puzzle[row][col] = {0}; // ����  �� 
	int n = col;
    int key = 0;
    int num_Length = n*n; 
	int game_num = num_Length - 1;
    int oneline[num_Length] = {0};
    int newline[num_Length] = {0}; 
    int rand_num;
    
    
    //1 ~ n * n ������ �ߺ� ���� ���� �� �� 
    for(int i = 0; i < num_Length; i++) {
		oneline[i] = rand()%num_Length+1;
		for(int j = 0; j < i; j++) {
			if(oneline[i] == oneline[j])
			i--;				
			}
		}
	
	// ���� �� ���� ū�� 0���� �� �� 
	for(int i = 0; i < num_Length; i++) {
		if(oneline[i] == num_Length)
		{
			i++;
			}
			newline[i] = oneline[i];				
		}
	
		for(int i = 0; i < num_Length; i++)
			printf("%d\n", newline[i]); 
			
	// ���� ū�� ���� �� ���� �ֱ� 
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

    for (r = 0; r<n; r++)//�� �ݺ�
    {
        for (c = 0; c<n; c++)//�� �ݺ�
        {
        	if((r * n + c + 1) == (n*n)) break;
            is_ending[r][c] = r * n + c + 1;
        }
    }
    is_ending[n-1][n-1] = 0;



	
}
