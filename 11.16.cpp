#include <iostream>
#include<time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define LEFT    75
#define RIGHT   77
#define UP      72
#define DOWN    80

using namespace std;

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

void levelSelectMenu()//���� ���� ���� 
{
	system("cls");
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
void firstline(int col)
{
	if (col == 3)
	{
		printf("��������������������������\n");
	}
	if (col == 4)
	{
		printf("����������������������������������\n");
	}
	if (col == 5)
	{
		printf("������������������������������������������\n");
	}
}

void midline(int col)
{
	if (col == 3)
	{
		printf("��������������������������\n");
	}
	if (col == 4)
	{
		printf("����������������������������������\n");
	}
	if (col == 5)
	{
		printf("������������������������������������������\n");
	}
}

void lastline(int col)
{
	if (col == 3)
	{
		printf("��������������������������\n");
	}
	if (col == 4)
	{
		printf("����������������������������������\n");
	}
	if (col == 5)
	{
		printf("������������������������������������������\n");
	}
}

/*void 3x3_print_puzzle(int puzzle[][3])
{
    int r, c;
    system("cls"); //�ܼ� ȭ���� �����
    for (r = 0; r<3; r++)//�� �ݺ�
    {
        for (c = 0; c<3; c++)//�� �ݺ�
        {
            if (puzzle[r][c])//���̸�(0�� �ƴϸ�)
            {
                printf("%3d", puzzle[r][c]);//������ ���� ���
            }
            else//����(0)�̸�
            {
                printf("   ");//���� ���
            }

        }
        printf("\n");//����
    }
}*/

int main()
{
	int level;
	Select:;
	levelSelectMenu();
	scanf("%d", &level);
	if(level < 1 || level > 5) goto Select;
	int n;
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
	
		int puzzleNum[row][col];
		int inputNum;
		int inputCount = 0;
		int number = 1;
		bool congratulation = false;
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				puzzleNum[i][j] = number;
				number++;
			}			
		}
		puzzleNum[row-1][col-1] = 0;  
	
		for (int i = 0; i < 100; i++) {
			int dest1 = rand() % row;
			int sour1 = rand() % col;
			int dest2 = rand() % row;
			int sour2 = rand() % col;
	
			int temp = puzzleNum[dest1][sour1];
			puzzleNum[dest1][sour1] = puzzleNum[dest1][sour2];
			puzzleNum[dest1][sour2] = puzzleNum[dest2][sour1];
			puzzleNum[dest2][sour1] = puzzleNum[dest2][sour2];
			puzzleNum[dest2][sour2] = temp;
		}
			
		int rememberA, rememberB;
		if (puzzleNum[row-1][col-1] != 0) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (puzzleNum[i][j] == 0) {
						rememberA = i;
						rememberB = j;
						int temp = puzzleNum[row-1][col-1];
						puzzleNum[row-1][col-1] = puzzleNum[i][j];
						puzzleNum[i][j] = temp;
					}
				}
			}
		}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			printf("%3d ", puzzleNum[i][j]);
		}
		printf("\n");
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
		printf("\n");
	}
	
/*	while (ending[row][col] != puzzleNum[row][col])
    {
        system("cls"); //�ܼ� ȭ���� �����
	    for (int r = 0; r < row; r++)//�� �ݺ�
	    {
	        for (int c = 0; c < col; c++)//�� �ݺ�
	        {
	            if (puzzleNum[r][c])//���̸�(0�� �ƴϸ�)
	            {
	                printf("%3d", puzzleNum[r][c]);//������ ���� ���
	            }
	            else//����(0)�̸�
	            {
	                printf("   ");//���� ���
	            }
	
	        }
	        printf("\n");//����
	    }
        printf(">> ����Ű ���� \n");
        int key = get_directionkey();

        switch (key)
        {
        case RIGHT:
            if (col>0)
            {
                puzzleNum[row][col] = puzzleNum[row][col - 1];
                puzzleNum[row][col - 1] = 0;
                col--;
            }

            break;
        case LEFT:
            if (col<3 - 1)
            {
                puzzleNum[row][col] = puzzleNum[row][col + 1];
                puzzleNum[row][col + 1] = 0;
                col++;
            }
            break;
        case UP:
            if (row<3 - 1)
            {
                puzzleNum[row][col] = puzzleNum[row + 1][col];
                puzzleNum[row + 1][col] = 0;
                row++;
            }
            break;
        case DOWN:
            if (row>0)
            {
                puzzleNum[row][col] = puzzleNum[row - 1][col];
                puzzleNum[row - 1][col] = 0;
                row--;
            }
            break;
        }
    }
    return 0;
*/
	
	//���� ���� ����~
	while (true) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (puzzleNum[i][j] == 0) {
					cout << "   " << "\t";
				} else cout << puzzleNum[i][j] << "\t";
			}
			cout << endl;
			cout << endl;
		}

		int checkNumber = 1;
		int checkCount = 0;
		if (!congratulation) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (puzzleNum[i][j] == checkNumber) {
						checkNumber++;
						checkCount++;
					}
				}
			}
			if (checkCount % (row*col) == 0) {
				congratulation = true;
				break;
			}
		}
		else break;

		cout << "���� Input Count : " << inputCount << endl;
		cout << "������ ������ ���ڸ� �Է��ϼ���." << endl;
		cout << "��(4), ��(8), ��(6), ��(2)" << endl;
		cin >> inputNum;
		
		while (true) {
			if (!cin.good() || inputNum != 8 && inputNum != 6 && inputNum != 2 && inputNum != 4) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "�ٽ� �Է��ϼ���. �̻��Ѱ� �Է¹޾���" << endl;
				cout << "��(4), ��(8), ��(6), ��(2)" << endl;
				cin >> inputNum;
				cout << endl;
				continue;
			}
			else break;
		}


		
		if (inputNum == 4) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (puzzleNum[i][j] == 0 && j > 0) {
						int temp = puzzleNum[i][j];
						puzzleNum[i][j] = puzzleNum[i][j-1];
						puzzleNum[i][j - 1] = temp;
					}
				}
			}
		}
		if (inputNum == 8) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (puzzleNum[i][j] == 0 && i > 0) {
						int temp = puzzleNum[i][j];
						puzzleNum[i][j] = puzzleNum[i - 1][j];
						puzzleNum[i - 1][j] = temp;
					}
				}
			}
		}
		if (inputNum == 6) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (puzzleNum[i][j] == 0 && j < 4) {
						int temp = puzzleNum[i][j];
						puzzleNum[i][j] = puzzleNum[i][j + 1];
						puzzleNum[i][j + 1] = temp;
						break;
					}
				}
			}
		}
		if (inputNum == 2) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (puzzleNum[i][j] == 0 && i < 4) {
						int temp = puzzleNum[i][j];
						puzzleNum[i][j] = puzzleNum[i + 1][j];
						puzzleNum[i + 1][j] = temp;
						break;
					}
				}
			}
		}

		system("cls");
		inputCount++;

		

	}

	return 0;
}
