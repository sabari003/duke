//  sudoko game
//  sabarash ,GCT, IT ,COIMBATORE
//  22-07-2019

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define newline printf("\n");

void printBox(int box[15][15] );// to print the box
bool numberExistRow( int box[15][15], int number, int row, int column);//checks the repeated number in the row
bool numberExistColumn( int box[15][15], int number, int row, int column);//checks the repeated number in the column
bool squareCheck ( int box[15][15] , int number , int row , int column );//checks the repeated number in the sub-box
void modeFunction( int box[15][15] ,int mode );//mode for playing - gets mode(easy,medium,hard) as a input
bool checkDefaultIndex( int row, int column );//checking with the default indexes
void printError( int errorNumber, int row, int column );//printing error function
void win(int box[15][15]);//to add the box values and check winning position
bool indexCheck( int row, int column );//to check the input indexes are in range
void clear ( int box[15][15] );// to clear the user input
void blink(int box[15][15],int i,int j);//to show the selected index to update

int defaultRow[90],defaultColumn[90];
int mode ;
bool flag = false;

void main()
{
// bool flag= false;
 int box[15][15]   , a=0,b=0,rowValue =0,number;
 srand(time(0)) ;
 flag = false;
	
	
	
	for ( int i =  0 ; i< 9 ; i++ )
	{
		for( int j = 0 ; j< 9 ; j++ )
		{
			box[i][j] = 0 ;
		}
	}

    	
	printf("\n\t\t👿️👿️👿️👿️👿️👹️SUdoKI👿️👿️👿️👿️👿️👿️\n\n");
	

   	printf("Give playing mode\n1-easy\n2-medium\n3-difficult\n4-no default values\n choice : ");

   	scanf("%d",&mode);
	modeFunction(box,mode);    
	
 printBox( box );
 
 for( int a =0,i=0,j=0 ; a< 9; a++ )//a,b is traversing row number // i,j is index number for box
 {
 	for( int b=0 ;b< 9 ;b++ ){
		inputNumber:
		{
			printf("\n Give index values:i😉️ and j😁️(i,j range -> 1 to 9) and  box[row][column]😚️ (range as 1 - 9 )\n");
			printf("\n row = ");
			scanf("%d",&i);
			i=i-1;
			//i = a;
			
			printf("\n column = ");
			scanf("%d",&j);	
			j=j-1;
			//j = b;
			blink(box,i,j);
			
			printf("\n value = ");
			scanf("%d",&number);
			printBox(box);
			//number = rand()%9 + 1;
			
			if ( true == indexCheck( i, j ) )
			{
				//printBox(box);
				//printError( 7);
				goto inputNumber ;
			}
			
						
			if ( true == checkDefaultIndex( i, j ) )
			{
				//printBox(box);
				//printError( 6,0,0);
				goto inputNumber ;
			}
			
			
			if(  true == numberExistRow(box,number,i,j) )
			{
				//printBox( box );
				//printError(2 );
				goto inputNumber;
			}
			
			if(  true == numberExistColumn(box,number,i,j) )
			{
				//printBox( box );
				//printError( 3);
				goto inputNumber;
			}
			
			if(  true == squareCheck(box,number,i,j) )
			{
				//printBox( box );
				//printError(4 );
				goto inputNumber;
			}
			
			//numCount++;
			box[i][j] = number;
			
			printBox(box);
			printf("\nUPDATED 💙️\n");
			i = 0 ; j=0;
			win(box);
			
			//			if( a % 2 == 0 && a != 0)
			if(  0)
			{
				printf("\ndo you want to clear all your  values ?🤒️\n 1-clear \n2-no\n ");
				int choice ;
				scanf("%d",&choice);
				if (choice == 1) clear(box);
			}

		
		}
	}
		
 }
	
}//main ends

bool indexCheck( int row, int column )
{

	if( row < 0 || row > 8 ||  column < 0 || column > 8 )//row,column index check
		{
			//printError(7,0,0);	
			return true;
		}
	//else
	return false;
}

bool numberExistRow( int box[15][15], int number, int row, int column)//checks the repeated number in the row
{

//printf("\nrow-row = %d column =%d number=%d\n",row,column,number);
	/*{
	if( box[row][column] != 0 )//updation reason
		return false;// if false , random_mode is printed wrongly
	}*/

	for( int i = 0 ; i< 9  ; i++ )
	{
//	printf("\nrow-the old  and new number is %d,%d\n",box[row][i],number);
		if( number < 1 || number > 9 )
		{
			printError(1,0,0);	

			return true;
		}
		
		if( number == box[row][i] )// && number>0 && number <10)
		{	
			printError(2,0,i);
			return true;
		}
		
	}
//	printf("\nrow check :%d not exists🤑️\n",number);
	return false;
}//row checking function ends


bool numberExistColumn( int box[15][15], int number, int row, int column)//checks the repeated number in the Column
{

/*
if( box[row][column] != 0 )//updation reason
		return false;
*/

//printf("\ncolumn-   row = %d column =%d number=%d\n",row,column,number);
	for( int i = 0 ; i < 9  ; i++ )
	{
//	printf("\nthe old  and new number is %d,%d\n",box[row][i],number);
		if( number<1 || number > 9 )
		{	
			printError(1,0,0);	
			return true;
		}
		
		if( number == box[i][column] )// && number>0 && number <10)
		{	
			printError(3,i,0);
			//printf("\n%d column: already exists in same row,try another number 🤣️!\n",number);		
			return true;
		}		
			
		
	}
//	printf("\ncolumn check: %d not exists😻️\n",number);
	return false;
}


	
bool squareCheck ( int box[15][15] , int number , int row , int column )//checks the repeated number in the square
{
	
 int rowS , rowE ,columnS, columnE;// S - start , E- end
// printf("\nrow = %d column =%d\n",row,column);
 
  	//if( i%3==0 || (i%3) == 2 )
 	//printf("%d %d",
 	//row assignment
 	if( 0 <= row && row <= 2 )
 	{
 		rowS = 0 ; rowE = 2 ; 
 	}
 	else if( 3 <= row && row <=  5 )
 	{
	 	rowS = 3 ; rowE = 5 ;
 	}
 	else if( 6 <= row && row <= 8 )
 	{
	 	rowS = 6 ; rowE = 8 ;
 	}
 	else {
 	return true;
 	printf("error on row number\n");}
 	
 	
// 	printf("rowS=%d rowE=%d\n",rowS,rowE);
 
 	//column assignment
 	if( 0 <= column && column <= 2 )
 	{
	 	columnS = 0 ; columnE = 2 ; 
 	}
 	else if( 3 <= column && column <=  5 )
 	{
	 	columnS = 3 ; columnE = 5 ;
 	}
 	else if( 6 <= column && column <= 8 )
 	{
	 	columnS = 6 ; columnE = 8 ;
 	}
 	else {return true; printf("error on column number\n");}
 	
//	printf("columnS=%d columnE=%d\n",columnS, columnE);
 
 for( int i=rowS ; i<= rowE  ; i++ )
 {
 	for( int j=columnS  ; j <= columnE ; j++ )
 	{
//		printf("\nthe old  and new number in (%d,%d) is  %d,%d\n",i+1,j+1,box[row][i],number);
		if( number == box[i][j] )
		{
			printError(4,i,j);
			//printf("\n%d already exists in the  same BOX, try another number 🤐️!\n",number);	
			return true;
			//break;  // no need of it
		}		
	}
 }
// printf("\nbox check-%d not exists😎️\n",number);
	return false;
}


void printBox(int box[15][15] )
{
//int i=0, j=0;
flag = true;
newline
 for( int i = 0,a=0 ; i < 13 ; i++ )
     {
	if( i % 4  == 0  && i != 0)
	printf("  |___________________________________");
	if( i == 0 )
	printf("   __1__2__3_____4__5__6_____7__8__9__\n  |           |           |           |");//newline
		for( int j = 0,b=0 ; j < 9 ; j++,b++)
		{
			if ( j == 0 && (  i%4 != 0  ) ) //print numbers when 1st column and number rows 
				printf("%d",a+1);
				
		
			
			if( j % 3 == 0    &&   i % 4 != 0  )// print side border 0th 3rd 6th columns and not in number rows
				printf(" | ");
			
					
			if( i % 4  != 0)// print numbers
			{
				if( true  == checkDefaultIndex( a,b) )	printf(" %d*",box[a][b]);
				else 					printf(" %d ",box[a][b]);
			}			
			if( j == 8   && i %4 != 0)//8th column border
			printf(" | ");
			
			if ( i %4 == 0  && j == 8 && i != 0)//4,8,12 th row ,8th column border
			printf("| ");
		}
		printf("\n");
		if( i % 4 != 0  ) a++;
    }
    
    printf("\n\n");
    flag = false;
}
	
	


void modeFunction( int box[15][15] ,int mode )//mode for playing - gets mode(easy,medium,hard) as a input
{
	int number,row, column,loop ,temp ;//randomCount =0,
	flag = true;

	if( mode == 1 )
	loop = 40;
	
	else if( mode == 2 )
	loop = 30;
	
	else if( mode == 3 )
	loop = 20;
	
	else if( mode == 4 )
	{
	//return ;
	loop = 0 ;}
	
	else 
	{
	printf("\nERROR        : wrong MODE input😯️\n");
	//printError(5);
	main();
	}
		


  for( temp=0 ; temp < loop ; temp ++ )
  {

  	random:
	column = rand()%9 ;// column,row,number should be in random ,caz.... to avoid same index ,,no values blocking
	row    = rand()%9 ;
	number = rand()%9 +1;
			
//	printf("random: row = %d column= %d number=%d\n",row+1,column+1,number);
			
	if( true == numberExistRow(box,number,row,column))// || (true == numberExistColumn(box,number,row,column) ) || (  true == squareCheck(box,number,row,column) ) ) 
	{
//		printf("wrong random number =%d😮️\n",box[row][column] );
		printError(2,0,column);
		//randomCount++ ;
		goto random;
	}
	
	
	if (true == numberExistColumn(box,number,row,column) )
	{
//		printf("wrong random number =%d😮️\n",box[row][column] );
		printError(3,row,0);
		//randomCount++ ;
		goto random;
	}
	
	if(  true == squareCheck(box,number,row,column) )
	{
//		printf("wrong random number =%d😮️\n",box[row][column] );
		printError(4,row,column);
		//randomCount++ ;
		goto random;
	}
		
	else
	{
	defaultRow[temp]	= row;
	defaultColumn[temp] 	= column;	
//	printf("correct random number =%d☺️\n",number);
	box[row][column] 	= number ;
	//printBox( box );	
	//newline
	}
  }
  /*
  for( int i = 0 ; i< loop ; i++ )
  {
 	printf("defaultRow[%d],defaultColumn[%d] = (%d,%d)\n",i+1,i+1,defaultRow[i]+1,defaultColumn[i]+1);  
  }*/
  
  flag = false;
  
}

bool checkDefaultIndex(  int row, int column )
{
//	int defaultRow[30],defaultColumn[30];
	int loop ;

	if     ( mode == 1 ) loop = 40;
	else if( mode == 2 ) loop = 30;
	else if( mode == 3 ) loop = 20;
	else                 loop = 0;
	
	for ( int i = 0 ; i < loop ; i++ )
	{
//	printf("%d==%d %d==%d inside loop=%d\n", defaultRow[i]+1, row+1 , defaultColumn[i]+1, column+1 ,i);
		if ( defaultRow[i] == row && defaultColumn[i] == column )
		{
//			printf("%d==%d %d==%d inside if\n", defaultRow[i], row , defaultColumn[i], column );
			printError(6,0,0);
			//printf("INDEX ERROR : there is already a system number\n");	 
			return true ;
		}
	}
	return false;
}

void printError( int errorNumber, int row, int column )
{
//printf("flag :%d",flag);
 if( flag == false )
  {
	if     ( errorNumber == 1 ) 		printf("\nVALUE ERROR💔️  : the number should be in range (1-9) 😛️\n");
	else if( errorNumber == 2 )		printf("\nROW-ERROR💔️    : already exists in %dth column,try another number 🤣️!\n",column+1);		
	else if( errorNumber ==  3)		printf("\nCOLUMN ERROR💔️ : already exists in %dth row,try another number 🤣️!\n",row+1);		
	else if( errorNumber == 4 )		printf("\nSUB-BOX ERROR💔️: already exists in (%d,%d) , try another number 🤐️!\n",row+1,column+1);	
	else if( errorNumber ==  5)		printf("\nERROR💔️        : wrong MODE input😯️\n");	//wont works
	else if( errorNumber ==  6)		printf("\nREWRITE ERROR💔️: there is already a system number🙈️\n");	 
	else if( errorNumber ==  7)		printf("\nINDEX ERROR💔️  : the index should be in range (1-9) 😛️\n");
  }
}

void win(int box[15][15])
{
 int totalsum=0;
 for ( int i = 0 ; i < 9 ;i++ )
 {
  for( int j = 0 ; j< 9 ; j++ )
	{
		totalsum += box[i][j];
	}
 }
// printf("%d is  total sum\n",totalsum);
 
 if( totalsum == 405 )
 {
	printf("🕺️❣️🕺️❣️🕺️❣️🕺️❣️🕺️❣️wINNer WInneR chiCKEn dINnER!🕺️❣️🕺️❣️🕺️❣️🕺️❣️🕺️❣️ \ndo you want to play again? 1-yes 2-no");
	int play ;
	scanf("%d",&play);
	if( play == 1)	main();
 	exit(0);	
 }
}


void clear(int box[15][15])
{

flag = true;
  for( int i  =0 ;i< 9 ;i++ )
  {	
	for( int j= 0 ;j< 9 ; j++ )
	{
		if( true == checkDefaultIndex( i,j) )
		{
		}
		else box[i][j] = 0;
	}
  }
  flag = false;
  printBox(box);
  
}
void blink(int box[15][15],int x,int y)
{
int i=0, j=0;
flag = true;
newline
 for( int i = 0,a=0 ; i < 13 ; i++ )
     {
	if( i % 4  == 0  && i != 0)
	printf("  |___________________________________");
	if( i == 0 )
	printf("   __1__2__3_____4__5__6_____7__8__9__\n  |           |           |           |");//newline
		for( int j = 0,b=0 ; j < 9 ; j++,b++)
		{
			if ( j == 0 && (  i%4 != 0  ) ) //print numbers when 1st column and number rows 
				printf("%d",a+1);
				
		
			
			if( j % 3 == 0    &&   i % 4 != 0  )// print side border 0th 3rd 6th columns and not in number rows
				printf(" | ");
			
					
			if( i % 4  != 0)// print numbers
			{
				if ( a == x && b == y ) 			printf("_%d_",box[a][b]);
				else if( true  == checkDefaultIndex( a,b) )	printf(" %d*",box[a][b]);
				else 						printf(" %d ",box[a][b]);
			}			
			if( j == 8   && i %4 != 0)//8th column border
			printf(" | ");
			
			if ( i %4 == 0  && j == 8 && i != 0)//4,8,12 th row ,8th column border
			printf("| ");
		}
		printf("\n");
		if( i % 4 != 0  ) a++;
    }
    
    printf("\n\n");
    flag = false;
}
	
