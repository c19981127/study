#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char *menu[] = {"a - add new recond","d - delete a recond","q - quit",NULL};
int getchoice(char *greet , char *choices[]);
int main()
{
	int choice = 0;
	if(!isatty(fileno(stdout)))
	{
		fprintf(stderr,"You are not a terminal \n");
		//whether it is a terminal device if yes return 1 else return 0
		fprintf(stderr,"%d \n",isatty(fileno(stdout)));
		exit(1);
	}
	do
	{
		choice = getchoice("Please select an action :" , menu);
		printf("You have chosen : %c \n",choice);
	}while(choice != 'q');
	exit(0);
}
int getchoice(char *greet , char *choices[])
{
	int chosen = 0;
	int selected;
	char **option;

	do
	{
		printf("Choice: %s \n",greet);
		option=choices;
		while(*option)
		{
			printf("%s \n",*option);
			option++;
		}
		printf("%d \n",isatty(fileno(stdout)));
		do
		{
			selected = getchar();
		}while(selected == '\n');
		option = choices;
		while(*option)
		{
			if(selected == *option[0])
			{
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen)
		{
			printf("You have antered a incorrect choice \n");
		}
	}while(!chosen);
	return selected;
}
	
