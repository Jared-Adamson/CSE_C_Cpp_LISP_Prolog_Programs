// Jared Adamson
//HW02_2 : Defines the entry point for the console application.


#include "stdafx.h"

#include <stdio.h>



//macros: visual studio flags
#pragma warning(disable: 4996)

//Define a name PI and associate the value 3.14159265 to it.  Use a macro. 

#define PI 3.14159265

void
clear(void)
{
	while (getchar() != '\n');
}


int main(void)
{
	clear;
	//Add a prompt for the number of cylinders to sum. Make sure to use the control
	//symbol for integers. 
	int c, i;
	float h, r, v, vtotal = 0;
	

	printf("%s\n", "Please enter the number of cylinders to sum:");
	scanf("%d", &c);
	clear;


	//Create a loop based on the number of cylinders the user enters. 
	for (i = 1; i <= c; i++){
		//    Within the loop, prompt for height and radius parameters (allow floating
		//    point numbers), and calculate the volume for that particular cylinder.
		//    
		clear;
		printf("%s%d%s\n", "Please enter the height of cylinder number ", i, ":");
		scanf("%f", &h);
		clear;
		printf("%s%d%s\n", "Please enter the radius of cylinder number ", i, ":");
		scanf("%f", &r);

		v = PI * (r * r) * h;

		printf("%s%d%s%f\n", "The volume of cylinder number ", i, " is ", v);

		vtotal += v;
	}

	//Display the total volume sum back to the user. Make sure to use the right control
	//symbol to display your result. 
	printf("%s%f\n", "The total volume of all of your cylinders is: ", vtotal);

	system("pause");

	return 0;
}
