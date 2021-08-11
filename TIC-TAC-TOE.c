#include<stdio.h>
#include<string.h>


char board[3][3]=  {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char p1[10],p2[10];
int moves=0,i;
int showboard()
{
	printf("\nplay board\n\n");
	printf("\t\t\t %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
	printf("\t\t\t-----------\n");
	printf("\t\t\t %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
	printf("\t\t\t-----------\n");
	printf("\t\t\t %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
	return ;
	
}
int rowCrossed(char board[3][3])
{
    for( i=0;i<3;i++) {
        if (board[i][0]==board[i][1]&& board[i][1]==board[i][2]&& board[i][0] != ' ')
            return 1;
    }
    return 0;
}
int columnCrossed(char board[3][3])
{
    for( i=0;i<3;i++) {
        if (board[0][i] == board[1][i]&& board[1][i] == board[2][i]&& board[0][i] != ' ')
            return 1;
    }
    return 0;
}

int diagonalCrossed(char  board[3][3])
{
    if (board[0][0] == board[1][1]&& board[1][1] == board[2][2]&& board[0][0] != ' ')
        return 1;
  	if (board[0][2] == board[1][1]&& board[1][1] == board[2][0]&& board[0][2] != ' ')
        return 1;
	return 0;
	
}
int gameover(char board[3][3])
{
    if(rowCrossed(board)|| columnCrossed(board)|| diagonalCrossed(board))
    	return 1;
    return 0;
} 
void winner(char *winner)
{
	if(winner==p1)
		printf("Congratulations!%s has won the game",p1);
	else
		printf("Congratulations!%s has won the game",p2);
}
void play(char *player)
{
	
	int row,column;
	while(gameover(board)==0 && moves<=9)
	{	
		if(player==p1)
		{
			player1:
			{
							
				printf("It's your turn.Enter a row and column number to play(row:1-3 and column:1-3):");
				scanf("%d %d\n",&row,&column);
				if(board[row-1][column-1]==' ')
					board[row-1][column-1]='O';
				else
				{
						printf("gdhs");	
					printf("This cell has been occupied.Choose some other cell\n");	
						printf("gdhs");	
					goto player1;
				}
			}
			showboard(board);
			moves++;
		
			player=p2;
		}
		else
		{
			player2:
			{
			
				printf("It's your turn.Enter a row and column number to play(row:1-3 and column:1-3):");
				scanf("%d %d\n",&row,&column);
				if(board[row-1][column-1]==' ')
					board[row-1][column-1]='X';
				else
				{
					printf("This cell has been occupied.Choose some other cell\n");	
					goto player2;
				}
			}
			showboard(board);
			moves++;
			player=p1;
		}
		if (gameover(board)==0&& moves==9){
        	    printf("It's a draw\n");
        	    break;
		}
    	if(gameover(board)==1&&moves<=9) 
		{
			if (player==p1)
	            player=p2;
	        else if (player==p2)
	            player=p1;
	        winner(player);
	        break;
    	}
	}
	
	
}
int main()
{
	
	int toss;
	printf("Enter the name of first player:");
	scanf("%s\n",p1);
	printf("Enter the name of second player:");
	scanf("%s\n",p2);
	printf("RULES:\n");
	printf("1.input symbol(coin) for %s is 'O'\n",p1);
	printf("2.input symbol(coin) for %s is 'X'\n",p2);
	showboard(board);
	printf("Enter a number to perform toss:");
	scanf("%d\n",&toss);
	
	if(toss%2==0)
	{
		printf("%s has won the toss.\n",p1);
		
		play(p1);
	}
	else
	{
		printf("%s has won the toss.\n",p2);
		
		play(p2);
	}
}
