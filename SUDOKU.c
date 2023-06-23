#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 4
#define SOZE 9

void inputBoard(int [][SIZE]);                             /*SUDOKU SOLVER PROTOTYPE*/
void outputBoard(int [][SIZE]);                            /*SUDOKU SOLVER PROTOTYPE*/
void solvingSudoku(int [][SIZE]);                          /*SUDOKU SOLVER PROTOTYPE*/
int nextround(int [][SIZE]);                               /*SUDOKU SOLVER PROTOTYPE*/
void check(int [][SIZE], int,int,int,int);                 /*SUDOKU SOLVER PROTOTYPE*/
void sudoku();                                             /*SUDOKU MAIN GAME PROTOTYPE*/
void display();                                            /*SUDOKU HIGHSCORES PROTOTYPE*/
int SudokuChecker(int sud[4][4]);                          /*SUDOKU CHECKER PROTOTYPE*/

struct score{
	char player[20];
	int lives;
	char print[5];
};
int main(void){
	int request, i, j;
	
	printf("%s","\n|| SUDOKU ||\n""\n1  Play game""\n2  Sudoku Solver""\n3  Highscore""\n0  Exit""\nEnter your choice: ");
	scanf("%d", &request);
	system("cls");
	while(request!=0){
		
		switch(request){
			case 1:{
			sudoku();
			break;
			}
			case 2:{
				int brd[SIZE][SIZE];
				
				printf("Enter the sudoku pattern.Enter 0 for any blank cells\n");
            
                inputBoard(brd);
                solvingSudoku(brd);
                printf("Here is the solved Sudoku puzzle!\n");
                outputBoard(brd);
                system("pause");
                system("cls");
				
				break;
			}
			case 3:{
				display();puts("");system("pause");system("cls");
				break;
			}
			case 0:{
				break;
				break;
			}
			default:{
				printf("\nInvalid input\n");
				break;
			}
		}
		printf("%s","\n|| SUDOKU ||\n""\n1  Play game""\n2  Sudoku Solver""\n3  Highscore""\n0  Exit""\nEnter your choice: ");
		scanf("%d", &request);
		system("cls");
	}
}

void display(){/*SUDOKU HIGHSCORES*/
struct score p1;
FILE *fdisplay;
fdisplay=fopen("Scores.DAT","r");

if(fdisplay==NULL){
	printf("\nError, file does not exist!!");
	exit(1);}
	
while(fgets(p1.print,5,fdisplay)!=NULL){
	printf("%s", p1.print);
}
fclose(fdisplay);
}

          void inputBoard(int brd[][SIZE])/*SUDOKU SOLVER*/
          
{
    int m,n;
    for (m=0;m<SIZE;m++)
   {
    for(n=0;n<SIZE;n++)
    scanf("%d", &brd[m][n]);
   }
}



          void outputBoard(int brd[][SIZE])/*SUDOKU SOLVER*/
{
	
    int m,n;
    for (m=0;m<SIZE;m++)
   {
    for (n=0;n<SIZE;n++)
    printf("%d ",brd[m][n]);
    printf("\n");
   }
}




          void solvingSudoku(int brd[][SIZE])/*SUDOKU SOLVER*/
{
	
    int emptycellLocated;
    do
   {
    emptycellLocated = nextround(brd);
   }
   while(emptycellLocated);
   }


   int nextround(int brd[][SIZE])/*SUDOKU SOLVER*/
   
{
   int m,n;
   int sum; 
   int zerocounter;

 
   for(m=0;m<SIZE;m++)
  {
   sum=0;
   zerocounter=0;

   for(n=0;n<SIZE;n++)
  {
     if(brd[m][n]==0)
     zerocounter++;
     else
     {
     sum = sum + brd[m][n];
     }
  }
     if(zerocounter == 1)
     { 
    for (n=0;n<SIZE;n++) 
   {
     if (brd[m][n]==0) 
	 {
    brd[m][n]=10-sum;
    break;
     }
   }
     }
   }

    for (n=0;n<SIZE;n++)
   {
    sum=0;
    zerocounter=0;

    for(m=0;m<SIZE;m++) 
   {
     if(brd[m][n]==0)
     {
    zerocounter++;
	 }
     else
    sum=sum + brd[m][n];
   }
     if(zerocounter==1) 
	 {  
   for(m=0;m<SIZE;m++)
  {
     if (brd[m][n]==0)
	 {
   brd[m][n]=10-sum;  
   break;
     }
  }
     }
  }
 
   check(brd, 0, 2, 0, 2);
   check(brd, 0, 2, 2, 4);
   check(brd, 2, 4, 0, 2);
   check(brd, 2, 4, 2, 4);


   for(m=0;m<SIZE;m++)
  {
   for(n=0;n<SIZE;n++)
  {
    if(brd[m][n]==0)  
   return 1;
    }
 }
   return 0;  
}




           void check(int brd[][SIZE],int lrow,int urow,int lcol,int ucol)
{
	
   int m,n;
   int total=0;  
   int zerocounter=0; 

   for (m=lrow;m<urow;m++)
  {  
   for (n=lcol;n<ucol;n++)
  {
    if(brd[m][n]==0)
    {
   zerocounter++;
    }
    else
    {
   total+=brd[m][n];
    }
  }
  }
    if(zerocounter==1) 
	{  
   for (m=lrow;m<urow;m++)
  {
   for(n=lcol;n<ucol;n++)
  { 
    if(brd[m][n]==0)
    {
   brd[m][n]=10-total;  
   break;
    }
  }
  }
    }
}

int SudokuChecker(int sud[4][4])/*SUDOKU CHECKER*/
{
    int i,j,k,a,b,c,temp=1;
        for(i=0;i<4;i++)
        {
          for(j=0;j<4;j++)
          {
            if(sud[i][j]==0)
              temp=2;
          }
        }
        if(temp==1)
        {
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            for(a=0;a<4;a++)
            {
                if(a!=i && sud[i][j]==sud[a][j])
                    return 0;
                if(a!=j && sud[i][j]==sud[i][a])
                    return 0;
                if(i<2 && j<2)
                {
                    for(b=0;b<2;b++)
                    {
                        for(c=0;c<2;c++)
                        {
                            if((b!=i || c!=j) && sud[i][j]==sud[b][c])
                                return 0;
                        }
                    }
                }
                else if(i<2 && j<4)
                {
                    for(b=0;b<2;b++)
                    {
                        for(c=2;c<4;c++)
                        {
                            if((b!=i || c!=j) && sud[i][j]==sud[b][c])
                                return 0;
                        }
                    }
                }
                else if(i<4 && j<2)
                {
                    for(b=2;b<4;b++)
                    {
                        for(c=0;c<2;c++)
                        {
                            if((b!=i || c!=j) && sud[i][j]==sud[b][c])
                                return 0;
                        }
                    }
                }
                else if(i<4 && j<4)
                {
                    for(b=2;b<4;b++)
                    {
                        for(c=2;c<4;c++)
                        {
                            if((b!=i || c!=j) && sud[i][j]==sud[b][c])
                                return 0;
                        }
                    }
                }
            }
        }
    }
    	}
}
void sudoku(){/*SUDOKU MAIN GAME*/
	int level, row, col, i, j, p, sud[SIZE][SIZE];
	char sudoku[SOZE][SOZE], newvalue, *newptr=&newvalue, uplimit='4', downlimit='1', rand1='1', rand2='2', rand3='3', rand4='4', nin='-', player[20], enter[]="\n";
	struct score p1;
	p1.lives=3;
	for(i=0;i<SOZE;i++){
		for(j=0;j<SOZE;j++){
			if(i==0||i==2||i==4||i==6||i==8){
			sudoku[i][j]='_';
			}
			else if((i==1||i==3||i==5||i==7)&&(j==0||j==2||j==4||j==6||j==8)){
			    sudoku[i][j]='|';
			    }
			else{
				sudoku[i][j]='-';
			    }
			
		    }
	    }
	printf("%s","\n1 - Level""\n2 - Level""\n3 - Level""\nWhich level do you prefer? ");scanf("%d", &level);
	if(level==1){
		sudoku[1][7]=rand3;
		sudoku[3][3]=rand1;sudoku[3][5]=rand2;sudoku[3][7]=rand4;
		sudoku[5][1]=rand4;sudoku[5][3]=rand2;sudoku[5][5]=rand3;sudoku[5][7]=rand1;
		sudoku[7][1]=rand1;sudoku[7][3]=rand3;sudoku[7][5]=rand4;sudoku[7][7]=rand2;
	    }
	else if(level==2){
	    sudoku[1][3]=rand2;sudoku[1][5]=rand4;
		sudoku[3][1]=rand1;sudoku[3][5]=rand2;sudoku[3][7]=rand3;
		sudoku[5][1]=rand4;sudoku[5][7]=rand2;
		sudoku[7][3]=rand1;sudoku[7][5]=rand3;sudoku[7][7]=rand4;
		}
	else if(level==3){
		sudoku[3][5]=rand1;
		sudoku[5][1]=rand4;
		sudoku[7][3]=rand2;sudoku[7][7]=rand3;
	    }
	
	printf("\n\t\t\t  SUDOKU\n");
	for(i=0;i<SOZE;i++){
	    printf("\n\t\t\t");
		for(j=0;j<SOZE;j++){
			printf("%c", sudoku[i][j]);
		    }
	    }
	puts("");
	
while(p1.lives!=0){
	col = 0, row = 0;
	printf("\nEnter the cursor row and column ( 1, 2, 3, 4 ): ");
	printf("\nRow Number: "); scanf("%d",&row);
	//For Row
	if(row == 2)
	{
		row = 3;
	}
	
	else if(row == 3)
	{
		row = 5;
	}
	
	else if(row == 4)
	{
		row = 7;
	}
	printf("Column Number: "); scanf("%d",&col);
	//For Column
	if(col == 2)
	{
		col = 3;
	}
	
	else if(col == 3)
	{
		col = 5;
	}
	
	else if(col == 4)
	{
		col = 7;
	}
	
	if( (row==3 && col==5)|| (row==5 && col==1) || (row==7 && col==3) || (row==7 && col==7) ||(row==0||row==2||row==4||row==6||row==8) ||
		((row==1||row==3||row==5||row==7)&&(col==0||col==2||col==4||col==6||col==8)) || (row>9||col>9)
	    || (level==1 && ( (row==1 && col==7) || (row==3 && col==3) || (row==3 && col==7)
		|| (row==5 && col==1) || (row==5 && col==3) || (row==5 && col==5) || (row==5 && col==7)
		|| (row==7 && col==1) || (row==7 && col==3) || (row==7 && col==5) || (row==7 && col==7) ) )
		            
		|| (level==2 && ( (row==1 && col==3) || (row==1 && col==5) || (row==3 && col==1)
		|| (row==3 && col==7) || (row==5 && col==1) || (row==5 && col==7) || (row==7 && col==3)
		|| (row==7 && col==5) ) )
					
		|| (level==3 && ( (row==3 && col==5) || (row==5 && col==1)
		|| (row==7 && col==3) || (row==7 && col==7) ) ) ){
			 	
		printf("\nWrong Input for row, and column!!  ");
		puts("");
		system("pause");
		system("cls");
		
		
        }
	else{
		printf("\nEnter value ( 1, 2, 3, 4 ): ");scanf(" %c", newptr);
		if(*newptr>uplimit || *newptr<downlimit){
		printf("\nWrong input for value!!  ");
		puts("");
		system("pause");
		system("cls");
		}
		else{
		sudoku[row][col]=*newptr;
		system("cls");
		}
		
	    }
    printf("\n\t\t\t  SUDOKU\n");
	for(i=0;i<SOZE;i++){
		printf("\n\t\t\t");
		for(j=0;j<SOZE;j++){
			printf("%c", sudoku[i][j]);
		    }
	    }
	puts("");
	if((level==1&&( (sudoku[1][1]!='-') && (sudoku[1][3]!='-') && (sudoku[1][5]!='-') && (sudoku[3][1]!='-') && (sudoku[3][5]!='-')))
				 
	    || (level==2 && ( (sudoku[1][1]!='-') && (sudoku[1][7]!='-') && (sudoku[3][3]!='-') && (sudoku[3][5]!='-') && (sudoku[5][3]!='-')
		&& (sudoku[5][5]!='-') && (sudoku[7][1]!='-') && (sudoku[7][7]!='-') ))
				
		|| (level==3 && ( (sudoku[1][1]!='-') && (sudoku[1][3]!='-') && (sudoku[1][5]!='-') && (sudoku[1][7]!='-') && (sudoku[3][1]!='-') && 
		(sudoku[3][3]!='-') && (sudoku[3][7]!='-') && (sudoku[5][3]!='-') && (sudoku[5][5]!='-') && (sudoku[5][7]!='-') && (sudoku[7][1]!='-') && (sudoku[7][5]!='-')))){
				  	
				  		
		for(p=0,j=1;j<SOZE;p++,j+=2){
			sud[0][p]=sudoku[1][j]-48;
			}
						
		for(p=0,j=1;j<SOZE;p++,j+=2){
			sud[1][p]=sudoku[3][j]-48;
			}
		for(p=0,j=1;j<SOZE;p++,j+=2){
		    sud[2][p]=sudoku[5][j]-48;
			}
		for(p=0,j=1;j<SOZE;p++,j+=2){
			sud[3][p]=sudoku[7][j]-48;
			}
					
		int solution=(SudokuChecker(sud)), i, j;
                            
		if(solution==0){
            printf("\n\t\tThe solution is Incorrect!");
			p1.lives--;
			}
		else{
		    printf("\n\n\t\t\tYou Won!!");
			FILE *fscore;
            fscore=fopen("Scores.DAT","a+");

            if(fscore==NULL){
	        printf("\nError, file does not exist!!");
			exit(1);
            }
			
			printf("\nEnter your name: ");scanf("%s", &p1.player);
            system("cls");
			fputs(enter,fscore);
            fprintf(fscore,"%-20s%5d\n",p1.player,p1.lives);
            fclose(fscore);
            display();
            system("pause");
            system("cls");
                                
			break;
			}
		}
	}
    if(p1.lives==0){
        printf("\n\n\t\t\tYOU LOST");
        puts("");
		system("pause");
        system("cls");
		}
}
