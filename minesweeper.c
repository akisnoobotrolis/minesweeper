#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


int incert(int *, int *);
void filltablewithmines( char **,int ,int ,int );
void printpinakas(char **,int ,int );
void calculatecells(char **,int ,int );
void filltable(char **,int,int);
void playgame(char **,char **,char **, int, int, int);
void freetable(char **,int);
char **desmeusi(int , int);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	char **pinakas;
	char **game;
	char **boole;
	int rows,i,j,cols,m,num;
	
	printf("MINESWEEPER\n\n\n");
	m=incert(&rows,&cols);
	system ("cls");
	pinakas=desmeusi(rows,cols);
	game=desmeusi(rows,cols);
	boole=desmeusi(rows,cols);			
	filltablewithmines(pinakas, rows,cols, m);
	calculatecells(pinakas,rows,cols);
	filltable(game,rows,cols);
	filltable(boole,rows,cols);
	playgame(game,pinakas,boole,rows,cols,m);
	printf("THE REVEALED TABLE WAS:\n\n");
	printpinakas(pinakas,rows,cols);
	system ("pause");
	freetable(pinakas,rows);
	freetable(game,rows);
	freetable(boole,rows);
		
return 0;
}

int incert(int *rows,int *cols) {
	int a, b,c;
	do{
	printf("Incert number of rows: ");
	scanf("%d",&a);
}
while (a<0);
	*rows=a;
	do{
	printf("\nIncert number of cols: ");
	scanf("%d",&b);
	}
	while (b<0);
	*cols=b;
	printf("\nInsert number of mines: ");
	do{
		scanf("%d",&c);
		if (c>((*rows) * (*cols)))
			printf("\nThe number of mines must be even or smaller than the size of table's cells (%d) \n Please insert again number of mines:",(*rows)*(*cols));
		
	}
	while(c>(*rows) * (*cols));
	return c;
	}


void filltablewithmines(char **pinakas,int rows,int cols,int mines){
	
	int k,x,y;
	filltable(pinakas,rows,cols);
	k=0;
	while(k<mines){
		y=rand()%rows;
		x=rand()%cols;
		if(*(pinakas[y]+x)==' '){
			++k;
			*(pinakas[y]+x)='X';	
		}
	
	}
}

					
					
				

	

void printpinakas(char **pinakas,int rows,int cols){
	int i,j;
	int numsx=0, numsy=0;
	for(i=-2;i<rows;i++){
		if(i==-2){
			for(j=0;j<cols;j++){
				if(j==0)
				printf("  x");
				if (j<cols-1)
				printf(".%2d",numsx);
				else
				printf(".%2d.\n",numsx);
				numsx++;
				
		
			}
		}
		else if(i==-1)printf(" y\n");
		else{
		if(i<10)
		printf(" %d:",numsy);
		else
			printf("%d:",numsy);
		for(j=0;j<cols;j++){ 
		 	if(j<cols-1)
		 	printf("| %c",*(pinakas[i]+j));
		 	else
			printf("| %c|",*(pinakas[i]+j));
		}
	printf("\n");
	numsy++;	
	}
	}
}
void calculatecells(char **pinakas,int rows ,int cols){
	int i,j,k,l;
	char num;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(pinakas[i][j]==' '){
				num='0';
				for(k=i-1;k<=i+1;k++){
					for(l=j-1;l<=j+1;l++){
						if(k>-1 && l>-1 && k<rows && l<cols){
						if(pinakas[k][l]=='X')
							num++;
						}
					}
					}
					pinakas[i][j]=num;
					}
				}
			}
	}	

void filltable(char **game,int rows,int cols){
	int i,j;
		for(i=0;i<rows;i++){
			for(j=0;j<cols;j++){
				*(game[i]+j)=' ';
			}
		}
	}
	
	
	
	
	void playgame(char **game, char **pinakas,char ** boole, int rows,int cols,int mines){
		int x,y,num;
		printpinakas(game,rows,cols);
		num=0;
		
		do{
			
			do{
				printf("\n\ngive x:");
				scanf("%d",&x);
				x=(int)x;
				if(x<0 || x>=cols)
				printf("x must be between 0 and %d\n",cols-1);
			}
			while (x<0 || x>=cols);
			
			do{
				printf("give y:");
				scanf("%d",&y);
				y=(int)y;
				if(y<0 || y>=rows)
				printf("y must be between 0 and %d\n",rows-1);
			}
			while (y<0 || y>=rows);
			printf("\n");
			system ("cls");
			*(game[y]+x)=*(pinakas[y]+x);
			printf("\n");
			printpinakas(game,rows,cols);
			if(boole[y][x]==' '){
				
				boole[y][x]='1';
				++num;
			}
			if (*(game[y]+x)=='X')
				printf("GAME OVER\n");
		}
		while (*(game[y]+x)!='X' && num!=(rows*cols)-(mines));
		if(num==(rows*cols)-(mines) && *(game[y]+x)!='X')
		printf("YOU WON\n\n");
	}
	void freetable(char **pinakas,int rows){
		int i;
		for(i=0;i<rows;i++)
			free(pinakas[i]);
		free(pinakas);
	
	}
	
	char **desmeusi(int a,int b){
		int i;
		char **pinakas;
		pinakas=(char**)malloc(a*sizeof(char*));
		for(i=0;i<a;i++)
		pinakas[i]=(char*)malloc(b*sizeof(char));
		return pinakas;
	}

