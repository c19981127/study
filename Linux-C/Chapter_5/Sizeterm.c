#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>
int main()
{
	int nrows , ncolumns;
	setupterm(NULL,fileno(stdout),(int *)0);
	nrows = tigetnum("lines");
	ncolumns = tigetnum("cols");
	printf("this terminal has %d rows and %d columns \n",nrows,ncolumns);
	exit(0);
}
