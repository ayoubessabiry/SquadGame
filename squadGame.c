#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
	char s[5];
	char *ev[]  = {"even","odd"};
	int cog , pg;
	int cob , pb;
	int winner = 0;
	int player = 10;
	int com = 10;
	int t;
	srand(time(NULL));

	printf("\n                >>>>>>>>>>><<<<<<<<<<<");
	printf("                Welcome to Squid Game");
	printf("                >>>>>>>>>>><<<<<<<<<<<");
	system("clear");
	printf("\n==>Rules:\n");
	printf("+-------------------------------------------------+\n");
	printf("| Both you and the computer has 10 balls.         |\n");
	printf("| in each turn, you or the computer takes guess   |\n| if the number of balls hidden is even or odd\n| and bet a number of current balls.              |\n");
	printf("| if the guess is right,                          |\n| the winner takes the number of balls they bet on\n");
	printf("| First to collect 20 balls is the Winner\n");
	printf("+-------------------------------------------------+\n");
	printf("                     >>>>><<<<<\n");
	printf("                     GOOD LUCK !            \n");
	printf("                     >>>>><<<<<\n");
	printf("Read the Rules and type 'ok' whenever you are ready\n");
	do
	{
		printf("Enter Your choice : ");
		scanf("%s",s);
	}while(s[0] != 'o');
	system("clear");
	printf("\n\n\n\n\t\t\tThe Game is start....\n\n\n");
	system ("clear");
	while(winner == 0)
	{
		printf("\nYOU : %d\t\t\t COMPUTER : %d\n\n",player,com);
		printf("Generating turn randomly......\n");
		sleep(1);
		t = rand() % 10;// numbers between 0 & 9
		t += 1;
		if(t % 2 ==  0)// odd for computer and even for player
		{
			printf("It's your turn\n"),
			printf("take a number of balls : ");
			scanf("%d",&pb);
			sleep(2);
			printf("\nComputer is guessing...");
			cob = rand() % 10;
			cob += 1;
			cog = rand() % 10;
			cog += 1;
			cog %= 2; 
		        sleep(2);	
			printf("Computer guess is: %s \n",ev[cog]);// 0 for even & 1 for odd
			printf("Computer bet is: %d \n",cob);
			if(pb % 2 == cog)
			{
				printf("Computer is right !\n");
				if(cob >=  pb)
				{
					player -= pb;
					com += pb;
				}
				else 
				{
					player -= cob;
					com += cob;
				}
			}
			else
			{
				printf("Computer is wrong !\n");
				if(cob <= pb)
				{
					player += cob;
					com -= cob;
				}
				else
				{
					player += pb;
					com -= pb; 
				}
			}
				
		}
		else if(t % 2 ==  1)// odd for computer and even for player
		{
			printf("It's Computer's turn\n"),
			sleep(2);
			printf("\nComputer is guessing...");
			cob = rand() % 10;
			cob += 1;
			printf("\nTake a number of bulls : ");
			scanf("%d",&pb);
			printf("Guess( 0 for even or 1 for  odd)....\n");
			scanf("%d",&pg);
			if(cob % 2 == pg)
			{
				printf("YOU are right !\n");
				if(pb >=  cob)
				{
					com -= cob;
					player += cob;
				}
				else
				{
					player += pb;
					com -= pb;
				}

			}
			else
			{
				printf("YOU are  wrong !\n");
				if(cob >= pb)
				{
					player -= pb;
					com += pb;
				}
				else
				{
					player -= cob;
					com += cob;
				}
			}

		}
		if(com == 20)
		{
			system("clear");
			printf("\n\n\n\a\a\t\t YOU DIED !!!! \n\n\n");
			winner += 1;
		}
		else if(player == 20)
		{
			system("clear");
			printf("\n\n\n\a\a\t\t YOU WON !!!! \n\n\n");
			winner += 1;
		}
		else 
			winner = 0;
	}	
}

