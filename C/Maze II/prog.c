/*
	Title: maze
	Purpose: Assignment 2 Unix & C Programming (COMP1000)
	Author: Sasiru Ushan Hettiarachchi
	Curtin ID: 20522908
	Date: 6/Oct/2021
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"terminal.h"
#include"map.h"
#include"openFile.h"
#include"linkList.h"

	int clear()/* a function that clears the screen */
	{
		system("clear");
		return 0;
	}
	
	int main(int argc, char * argv[])
	{

			if(argc>2)
			{
				printf("\nPlease enter VALID parameters ");
			}
			else
			{

			read(argv);/*read file function */

			int **t, metadataAmount, mapRow, mapCol, i, j;
			getMetadata(&t, &metadataAmount, &mapRow, &mapCol);/* get data from function getMetadata() */
			
			char input;

			char **arr = malloc(sizeof(int*) * mapRow);/* create table */

			for(i=0; i<mapRow; i++)
			{
				arr[i] = malloc(sizeof(int) * mapCol);
			} 

			arr[0][0] = '#'; arr[0][1] = '-'; arr[0][2] = '-'; arr[0][3] = '-'; arr[0][4] = '-'; arr[0][5] = '-'; arr[0][6] = '-'; arr[0][7] = '-'; arr[0][8] = '-'; arr[0][9] = '-'; arr[0][10] = '-'; arr[0][11] = '-'; arr[0][12] = '-'; arr[0][13] = '#'; 
			arr[1][0] = '|'; arr[1][1] = '~'; arr[1][2] = ' '; arr[1][3] = ' '; arr[1][4] = ' '; arr[1][5] = ' '; arr[1][6] = ' '; arr[1][7] = '0'; arr[1][8] = 'X'; arr[1][9] = ' '; arr[1][10] = ' '; arr[1][11] = ' '; arr[1][12] = ' '; arr[1][13] = '|';
			arr[2][0] = '|'; arr[2][1] = ' '; arr[2][2] = ' '; arr[2][3] = ' '; arr[2][4] = ' '; arr[2][5] = ' '; arr[2][6] = ' '; arr[2][7] = '0'; arr[2][8] = ' '; arr[2][9] = ' '; arr[2][10] = ' '; arr[2][11] = ' '; arr[2][12] = ' '; arr[2][13] = '|';
			arr[3][0] = '|'; arr[3][1] = ' '; arr[3][2] = ' '; arr[3][3] = ' '; arr[3][4] = ' '; arr[3][5] = ' '; arr[3][6] = ' '; arr[3][7] = '0'; arr[3][8] = ' '; arr[3][9] = ' '; arr[3][10] = ' '; arr[3][11] = ' '; arr[3][12] = ' '; arr[3][13] = '|';
			arr[4][0] = '|'; arr[4][1] = ' '; arr[4][2] = '0'; arr[4][3] = '0'; arr[4][4] = '0'; arr[4][5] = '0'; arr[4][6] = ' '; arr[4][7] = ' '; arr[4][8] = ' '; arr[4][9] = ' '; arr[4][10] = ' '; arr[4][11] = ' '; arr[4][12] = ' '; arr[4][13] = '|';
			arr[5][0] = '|'; arr[5][1] = ' '; arr[5][2] = ' '; arr[5][3] = ' '; arr[5][4] = '0'; arr[5][5] = ' '; arr[5][6] = ' '; arr[5][7] = '0'; arr[5][8] = ' '; arr[5][9] = ' '; arr[5][10] = ' '; arr[5][11] = ' '; arr[5][12] = ' '; arr[5][13] = '|';
			arr[6][0] = '|'; arr[6][1] = ' '; arr[6][2] = '0'; arr[6][3] = '^'; arr[6][4] = ' '; arr[6][5] = ' '; arr[6][6] = ' '; arr[6][7] = ' '; arr[6][8] = ' '; arr[6][9] = ' '; arr[6][10] = ' '; arr[6][11] = ' '; arr[6][12] = ' '; arr[6][13] = '|';
			arr[7][0] = '|'; arr[7][1] = ' '; arr[7][2] = '0'; arr[7][3] = ' '; arr[7][4] = ' '; arr[7][5] = ' '; arr[7][6] = ' '; arr[7][7] = ' '; arr[7][8] = ' '; arr[7][9] = '0'; arr[7][10] = ' '; arr[7][11] = ' '; arr[7][12] = ' '; arr[7][13] = '|'; 
			arr[8][0] = '|'; arr[8][1] = ' '; arr[8][2] = ' '; arr[8][3] = ' '; arr[8][4] = ' '; arr[8][5] = ' '; arr[8][6] = ' '; arr[8][7] = ' '; arr[8][8] = ' '; arr[8][9] = ' '; arr[8][10] = ' '; arr[8][11] = ' '; arr[8][12] = ' '; arr[8][13] = '|';
			arr[9][0] = '#'; arr[9][1] = '-'; arr[9][2] = '-'; arr[9][3] = '-'; arr[9][4] = '-'; arr[9][5] = '-'; arr[9][6] = '-'; arr[9][7] = '-'; arr[9][8] = '-'; arr[9][9] = '-'; arr[9][10] = '-'; arr[9][11] = '-'; arr[9][12] = '-'; arr[9][13] = '#';
			
			
			int posX, posY, prevPosX, prevPosY; 
			int posx, posy, prevposx, prevposy;			
			/*starting point of '^' is arr[6][3]*/
			posX = 6;
			posY = 3;

			/* snake starting point '~'*/
			posx = 1;
			posy = 1;
			

			clear();

			/* 	while the current position of '^' is not equal to ending position 'x'and 
			the current position of snake '~ is not equal to the current position of the head '^'' */
			while((arr[posX][posY]!=arr[1][8]) && (arr[posx][posy]!=arr[posX][posY])) 
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

				prevposx = posx;
				prevposy = posy;

				if(input =='a') 
				{
					/* if there is no wall ('0') and no border ('|'), move head to the left */
					if(arr[posX][posY-1] != '0' && arr[posX][posY-1] != '|')
					{
						posY--;
						arr[posX][posY]= '<';
						arr[prevPosX][prevPosY] = ' ';
						insert(posX, posY, '<');	/* insert into linkList */
					}
					/* if there is no wall ('0') and no border ('|') and no 'X' move snake to the left */
					if((arr[posx][posy-1]!='0') && (arr[posx][posy-1] != '|') && (arr[posx][posy-1] != 'X'))
					{
						posy--;
						arr[posx][posy] = '~';
						arr[prevposx][prevposy]=' ';
					}

					clear();
				}
				if(input == 'd')
				{
					/* if there is no wall('0') and there is no border('|') move head to the right*/
					if(arr[posX][posY+1] !='0' && arr[posX][posY+1] != '|')
					{						
						posY++;
						arr[posX][posY]= '>';
						arr[prevPosX][prevPosY]= ' ';
						insert(posX, posY, '>');
						
					}	
					/* if there is no wall('0') and there is no border('|') move snake to the right*/
					if(arr[posx][posy+1] !='0' && arr[posx][posy+1] != '|')
					{
						posy++;
						arr[posx][posy]= '~';
						arr[prevposx][prevposy]= ' ';	
					}
					
					clear();

				}
				if(input == 'w')
				{
					/* if there is no wall('0') and there is no upper border('-') move head to the top*/
					if(arr[posX-1][posY] != '0' && arr[posX-1][posY] != '-')
					{
						posX--;
						arr[posX][posY]='^';
						arr[prevPosX][prevPosY] = ' ';
						insert(posX, posY, '^');
					}
					/* if there is no wall('0') and there is no upper border('-') and there is no 'X', move snake to the top*/
					if(arr[posx-1][posy] != '0' && arr[posx-1][posy] != '-' && arr[posx-1][posy] != 'X')
					{
						posx--;
						arr[posx][posy]='~';
						arr[prevposx][prevposy] = ' ';	
					}

					clear();

				}
				if(input == 's')
				{
					/* if there is no wall('0') and there is no lower border space('-'), move head to the bottom*/
					if(arr[posX+1][posY] != '0' && arr[posX+1][posY] != '-')
					{
						posX++;
						arr[posX][posY]='v';
						arr[prevPosX][prevPosY] = ' ';
						insert(posX, posY, 'v');		
					}
					/* if there is no wall('0') and there is no lower border space('-'), move snake to the bottom*/
					if(arr[posx+1][posy] != '0' && arr[posx+1][posy] != '-')
					{
						posx++;
						arr[posx][posy]='~';
						arr[prevposx][prevposy] = ' ';
					}

					clear();
					
				}
				if(input == 'u') /* Enter 'u' TWICE the first time to undo */
				{
					int *ptr;
					ptr = removeFirst();
					posX = ptr[0];
					posY = ptr[1]; 
					arr[posX][posY] = ptr[2];
					arr[prevPosX][prevPosY]= ' ';
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
			if(arr[posx][posy] == arr[posX][posY] || arr[posX][posY] == arr[posX][posy])
			{
				printf("You Lost!!\n");
			}

				free(arr);/*free memory*/
			
		
	}
		
}
