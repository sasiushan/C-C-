/*
	Title: maze
	Purpose: Assignment One Unix & C Programming (COMP1000)
	Author: Sasiru Ushan Hettiarachchi
	Curtin ID: 20522908
	Date: 12/Sep/2021
*/
#include<stdio.h>
#include<stdlib.h>
#include"terminal.h"
#include"map.h"

	int clear()/* a function that clears the screen */
	{
		system("clear");
		return 0;
	}
	

	int main(int argc, char * argv[])
	{

		if(argc<=2)
		{
			
			int **t, metadataAmount, mapRow, mapCol, i, j;
			getMetadata(&t, &metadataAmount, &mapRow, &mapCol);/* get info from function getMetadata() */
			int posX;
			int posY;
			int prevPosX;
			int prevPosY; 
			char input;
			



			char **arr = malloc(sizeof(int*) * mapRow);

			for(i=0; i<8; i++)
			{
				arr[i] = malloc(sizeof(int) * mapCol);
			} 

			arr[0][0] = '#'; arr[0][1] = '-'; arr[0][2] = '-'; arr[0][3] = '-'; arr[0][4] = '-'; arr[0][5] = '-'; arr[0][6] = '-'; arr[0][7] = '-'; arr[0][8] = '-'; arr[0][9] = '#';
			arr[1][0] = '|'; arr[1][1] = ' '; arr[1][2] = ' '; arr[1][3] = ' '; arr[1][4] = ' '; arr[1][5] = ' '; arr[1][6] = ' '; arr[1][7] = '0'; arr[1][8] = 'X'; arr[1][9] = '|';
			arr[2][0] = '|'; arr[2][1] = '0'; arr[2][2] = ' '; arr[2][3] = '0'; arr[2][4] = ' '; arr[2][5] = ' '; arr[2][6] = ' '; arr[2][7] = '0'; arr[2][8] = ' '; arr[2][9] = '|';
			arr[3][0] = '|'; arr[3][1] = ' '; arr[3][2] = ' '; arr[3][3] = '0'; arr[3][4] = ' '; arr[3][5] = ' '; arr[3][6] = ' '; arr[3][7] = '0'; arr[3][8] = ' '; arr[3][9] = '|';
			arr[4][0] = '|'; arr[4][1] = ' '; arr[4][2] = '0'; arr[4][3] = '0'; arr[4][4] = '0'; arr[4][5] = '0'; arr[4][6] = ' '; arr[4][7] = '0'; arr[4][8] = ' '; arr[4][9] = '|';
			arr[5][0] = '|'; arr[5][1] = ' '; arr[5][2] = ' '; arr[5][3] = ' '; arr[5][4] = '0'; arr[5][5] = ' '; arr[5][6] = ' '; arr[5][7] = '0'; arr[5][8] = ' '; arr[5][9] = '|';
			arr[6][0] = '|'; arr[6][1] = ' '; arr[6][2] = '0'; arr[6][3] = '^'; arr[6][4] = '0'; arr[6][5] = ' '; arr[6][6] = ' '; arr[6][7] = ' '; arr[6][8] = ' '; arr[6][9] = '|';
			arr[7][0] = '#'; arr[7][1] = '-'; arr[7][2] = '-'; arr[7][3] = '-'; arr[7][4] = '-'; arr[7][5] = '-'; arr[7][6] = '-'; arr[7][7] = '-'; arr[7][8] = '-'; arr[7][9] = '#';
			

			
			
			/* starting point of '^' is arr[6][3] where posX = 6 anf posY = 3*/
			posX = 6;
			posY = 3;
			

			clear();
			while(arr[posX][posY] != arr[1][8]) /* while the current position of '^' is not equal to ending position 'x' */
			{
				
				for(i=0; i<mapRow; i++)/* prints the map */
				{
					for(j=0; j<mapCol;j++)
					{

						printf("  %c", arr[i][j]);
					}
					printf("\n");
				}

				disableBuffer(); 
				scanf(" %c", &input);
				prevPosX=posX; 
				prevPosY= posY;

				if(input =='a')
				{
					if(arr[posX][posY-1] != '0' && arr[posX][posY-1] == ' ')/* if there is no wall ('0') and there is free space(' ') to the left, operation can execute*/
					{
						posY--;
						arr[posX][posY]= '<';
						arr[prevPosX][prevPosY] = ' ';
						
					}
					clear();
				}
				if(input == 'd')
				{
					if(arr[posX][posY+1] !='0' && arr[posX][posY+1] == ' ')/* if there is no wall('0') and there is free space(' ') to the right, operation can execute*/
					{
						posY++;
						arr[posX][posY]= '>';
						arr[prevPosX][prevPosY]= ' ';
						
					}
					clear();
				}
				if(input == 'w')
				{
					if(arr[posX-1][posY] != '0' && arr[posX-1][posY] != '-')/* if there is no wall('0') and there is upper border('-') to the top, operation can execute*/
					{
						posX--;
						arr[posX][posY]='^';
						arr[prevPosX][prevPosY] = ' ';
						
					}
					clear();
				}
				if(input == 's')
				{
					if(arr[posX+1][posY] != '0' && arr[posX+1][posY] == ' ')/* if there is no wall('0') and there is free space(' ') to the bottom, operation can execute*/
					{
						posX++;
						arr[posX][posY]='v';
						arr[prevPosX][prevPosY] = ' ';

					}
					clear();
					
				}
				else
				{
					clear();
				}

				enableBuffer();
			}
			

			for(i=0; i<mapRow; i++) /* print game to screen after exiting loop (winning condition is true '^'=='X') */
				{
					for(j=0; j<mapCol;j++)
					{

						printf("  %c", arr[i][j]); 
					}
					printf("\n");
				}

			
			if(arr[posX][posY] == arr[1][8]) /*print winning message */
				{
					printf("You Won!!!\n ");
				}

				free(arr);
			
		
		}
		else/* if more than two parameters are input in terminal, output a error message */
		{
			printf("Error parameter limit exceeded! \n");
		}
}
