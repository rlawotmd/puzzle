#include<iostream>
#include<time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main() {

	srand((unsigned int)time(NULL));

	int puzzleNum[5][5];
	int inputNum;
	int inputCount = 0;
	int number = 1;
	bool congratulation = false;
	
	//�ʱ� 5�� 5���� �迭�� 1���� 25���� �ʱ�ȭ�Ѵ�.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			puzzleNum[i][j] = number;
			number++;
		}			
	}
	//25�� ����ִ�[4][4] ��° ��ġ�� 0 ������ �����
	puzzleNum[4][4] = 0;  


	//����!!
	for (int i = 0; i < 100; i++) {
		int dest1 = rand() % 5;
		int sour1 = rand() % 5;
		int dest2 = rand() % 5;
		int sour2 = rand() % 5;

		int temp = puzzleNum[dest1][sour1];
		puzzleNum[dest1][sour1] = puzzleNum[dest1][sour2];
		puzzleNum[dest1][sour2] = puzzleNum[dest2][sour1];
		puzzleNum[dest2][sour1] = puzzleNum[dest2][sour2];
		puzzleNum[dest2][sour2] = temp;
	}
		

	// Zero �� ��ġ�� ã�ƺ��� [4][4]�� �������� 0�� ����ִ� ��ġ�� ����!
	int rememberA, rememberB;
	if (puzzleNum[4][4] != 0) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (puzzleNum[i][j] == 0) {
					rememberA = i;
					rememberB = j;
					int temp = puzzleNum[4][4];
					puzzleNum[4][4] = puzzleNum[i][j];
					puzzleNum[i][j] = temp;
				}
			}
		}
	}	
	

	//���� ���� ����~
	while (true) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (puzzleNum[i][j] == 0) {
					cout << "��" << "\t";
				} else cout << puzzleNum[i][j] << "\t";
			}
			cout << endl;
			cout << endl;
		}

		int checkNumber = 1;
		int checkCount = 0;
		if (!congratulation) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (puzzleNum[i][j] == checkNumber) {
						checkNumber++;
						checkCount++;
					}
				}
			}
			if (checkCount % 25 == 0) {
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
