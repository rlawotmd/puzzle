#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int n = 3;
    int puzzle[n][n] = {0}; // = { { 1,3,2 },{ 7,8,4 },{ 6,5,0 } };
	int row = n-1;
    int col = n-1;
    int key = 0;
    
	for (int i = 0; i < n; i++)
	    {
	    	for (int j = 0; j < n; j++)
	    	{
	    		if(i == n-1 && j == n-1) break;
	    		again:;
	    		int rand_num = rand()%(n*n)+1;
	    		for (int a = 0; a < i-1; a++)
	    		{
	    			for (int b = 0; b < j-1; b++)
	    			{
	    				if(rand_num == puzzle[a][b]) goto again;
					}
				}
	    		puzzle[i][j] = rand_num;
			}
		}
	puzzle[n-1][n-1] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", puzzle[i][j]);
		}
		printf("\n");
	}
}
