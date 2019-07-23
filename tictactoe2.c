
//tic tac toe 
//vs . computer


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int a =0 ;
void printBOX(int box[3][3]);
void checkWin(int box[3][3],int round);
void win(int e[3]);
int checkInput(int box[3][3], int temp1 , int temp2 ) ;

bool flag = false;
void main()
{
	int box[3][3] = {0};
	
	int row , column, round, checkResult, value,temp1,temp2, inputCheck;
	printf("1st player is X = 1  and 2nd player is O = 2\n");
	
	srand(time(0));
	
	printBOX(box);
	
	
	for ( round = 0 ; round < 9 ; round++ )
	{
	if( round % 2 == 0 )
	{
	hhh:
	printf("player %d give index for move\n",(round % 2 )+1);
	//int temp1, temp2 ;
	scanf("%d%d",&temp1,&temp2);
	
	inputCheck = checkInput (box, temp1, temp2 );
	if ( inputCheck == 0)
	goto hhh;
	
	
	
	box[temp1-1][temp2-1] = 1;
	printBOX(box);
	checkWin(box, round);
	}
	
	if ( round % 2 == 1 ) 
	{
	flag = true;
	hhb:
	printf("player %d give index for move\n",(round % 2)+1);
	//int temp3, temp4 ;
	//scanf("%d%d",&temp1,&temp2);
	temp1 =  rand()%3 +1;
	temp2 = rand()%3 +1;
	
	inputCheck = checkInput ( box,temp1, temp2 );
	if ( inputCheck == 0 )
	goto hhb;
	
	box[temp1-1][temp2-1] = 2;
	printBOX(box);
	checkWin(box, round);
	}
	flag = false;
	}
	
	
	
}

void printBOX(int box[3][3])
{
	//a =sizeof (box[3][3]);
	printf("\n");
	
	for ( int row = 0 ; row < 3 ; row++ )
	{	printf("|");
		for (  int column = 0 ; column < 3 ; column++ )
		{
			printf(" %d ",box[row][column]);
		}
		printf("|\n");
	}
	printf("\n");
	
}

void checkWin(int box[3][3],int round)
{	

	int e[3];
	/*
	inverse diagonal
	
	0 0 x
	0 x 0
	x 0 0
	*/
	/*for ( int row = 0 ; row < 3 ; row++ )
	{	
		for (  int column = 0 ; column < 3 ; column++ )
		{
			if ( row + column == 2 )
			e[row] = box[row][column] ;
		}
	}*/
	
	e[0]=box[0][0]; e[1] = box[1][1]; e[2] = box[2][2];
	win(e);
	
			
	/*
	diagonal
	
	x 0 0
	0 x 0
	0 0 x
	*/		
	/*for ( int row = 0 ; row < 3 ; row++ )
	{	
		for (  int column = 0 ; column < 3 ; column++ )
		{	
			if( row == column )
			e[row] = box[row][column] ;
		}	
	}*/
	
	e[0]=box[2][0]; e[1] = box[1][1]; e[2] = box[0][2];
	win(e);
	
	e[0]=box[0][0]; e[1] = box[1][0]; e[2] = box[2][0];
	win(e);
	
	e[0]=box[0][1]; e[1] = box[1][1]; e[2] = box[2][1];
	win(e);
	
	e[0]=box[0][2]; e[1] = box[1][2]; e[2] = box[2][2];
	win(e);
	
	
	e[0]=box[0][0]; e[1] = box[0][1]; e[2] = box[0][2];
	win(e);
	
	e[0]=box[1][0]; e[1] = box[1][1]; e[2] = box[1][2];
	win(e);
	
	e[0]=box[2][0]; e[1] = box[2][1]; e[2] = box[2][2];
	win(e);
	
	/*e[0]=box[][]; e[1] = box[][]; e[2] = box[][];
	win(e);*/ 
if( round == 8)
 {
	int draw=0;
	for ( int row = 0 ; row < 3 ; row++ )
	{	
		for (  int column = 0 ; column < 3 ; column++ )
		{	
			if( box[row][column] !=0 )
			{
				draw++ ;
			}
			if ( draw == 9 )
			{
				printf("draw match, none win😏️🤐️\n");
				exit(0);
			}
			else if( box[row][column] ==0 )// does not enters here....
			{	
			if( flag == false )
				printf("wrong position entered🤗️\n");
				exit(0);
			}
			
		}
	}
 }
}

void win(int e[3])
{

	if ( e[0] == 1 && e[1] == 1 && e[2] == 1 )
	{	
		printf("****************❣️🕺️🤑️😎️💙️👌️winner winner chicker dinner!🕺️🤑️😎️💙️👌️❣️ 1st player wins***************\n");
		exit(0);
	}	
	
	if ( e[0] == 2 &&  e[1] == 2 && e[2] == 2 )
	{
		printf("*******************booyah!❣️😂️🙈️❣️😂️🙈️second player wins❣️😂️🙈️❣️😂️🙈️*******************************\n");
		exit(0);
	}

}
	
int checkInput(int box[3][3], int temp1 , int temp2 ) 
{
  if( flag == false )
  {
	
	if( box[temp1-1][temp2-1] != 0)
	{
	printf("there is already a value or garbage value...😪️ %d\n",box[temp1-1][temp2-1]);
	return 0;
	}
	
	else if ( 1 <= temp1 && temp1 <= 3 && 1 <= temp2 && temp2 <= 3 )
	return 1;
	
	else
	{
	printf("give correct ranges, stupid👿️!\n" );
	return 0 ;
	}
  }	
}




