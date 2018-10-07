/******************************************************************************************************
**	Author		: 	James Jallorina
**	Date		: 	10-07-2018
**	Description : 	You have just been employed by MacroMuscle, Inc. (Software for Hard Bodies).
**					The company is entering the European market and wants a program that converts
**					inches to centimeters (1 inch = 2.54 cm). The company wants the program set up
**					so that it prompts the user to enter an inch value. Your assignment is to define
**					the program objectives and to design the program (steps 1 and 2 of the
**					programming process). 
**
**	Source		:	C Primer Plus Fith Edition by Stephen Prata
******************************************************************************************************/

#include <stdio.h>

int main(int argc, char **argv)
{
	float a = 0.00, b = 0.00;
	printf("Enter inches to centimeters conversion: ");
	scanf("%f", &a);
	b = a * 2.54;
	printf("Converted value to centimeters: [%f] \n", b);
	return 0;
}