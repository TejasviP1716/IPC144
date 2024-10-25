/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  :Tejasvi Parmar
Section    :ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	// Variable Declaration

	char  iterationLoop;
	int   loop, i;

	printf("+----------------------+\n");
	printf("Loop application STARTED\n");
	printf("+----------------------+\n");

	// looping starts with do-while loop

	do
	{
		printf("\nD = do/while | W = while | F = for | Q = quit\n");
		printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
		scanf(" %c%d", &iterationLoop, &loop);

		if (iterationLoop == 'D')           //logic of 'D' with nested if else 
		{
			if (loop <= 20 && loop >= 3)
			{
				printf("DO-WHILE: ");

				for (i = 0; i < loop; i++)
				{
					printf("D");
				}
				printf("\n");          //newline

			}
			else
				printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
		}

		else if (iterationLoop == 'W')        //logic of 'W' with nested if else 
		{
			if (loop <= 20 && loop >= 3)
			{
				printf("WHILE   : ");

				for (i = 0; i < loop; i++)
				{
					printf("W");
				}
				printf("\n");          //newline
			}
			else
				printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
		}

		else if (iterationLoop == 'F')       //logic of 'F' with nested if else
		{
			if (loop <= 20 && loop >= 3)

			{
				printf("FOR     : ");

				for (i = 0; i < loop; i++)
				{
					printf("F");
				}
				printf("\n");                //newline
			}
			else

				printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
		}

		else if (iterationLoop == 'Q')         //logic of 'Q' with nested if else 
		{
			if (loop == 0)
			{
				printf("\n+--------------------+\n");
				printf("Loop application ENDED\n");
				printf("+--------------------+\n");
			}
			else
				printf("ERROR: To quit, the number of iterations should be 0!\n");
		}
		else
			printf("ERROR: Invalid entered value(s)!\n");
	}while (loop != 0 || iterationLoop != 'Q');

	//program complete

    return 0;
}
