#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double my_sql(double x)
{
	assert(x >= 0.00);
	return sqrt(x);
}
int main()
{
	printf("%g \n",my_sql(2.0));
	printf("%g \n",my_sql(-1.0));
	exit(EXIT_SUCCESS);
}
