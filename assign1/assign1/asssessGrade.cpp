#define IS_DEFINED

#include "assessGrade.h"
#include <string.h>
#include <iostream>

void assessGrade(const char *letterSpecial)
{
	theGrade.finalMark = INT32_MAX;
	theGrade.returnCode = NUMBER_GRADE;
	if (strcmp(letterSpecial, "A+") == 0)
	{
		theGrade.finalMark = 95;
	}
	else if (strcmp(letterSpecial, "A") == 0)
	{
		theGrade.finalMark = 85;
	}
	else if (strcmp(letterSpecial, "B+") == 0)
	{
		theGrade.finalMark = 77;
	}
	else if (strcmp(letterSpecial, "B") == 0)
	{
		theGrade.finalMark = 72;
	}
	else if (strcmp(letterSpecial, "C+") == 0)
	{
		theGrade.finalMark = 67;
	}
	else if (strcmp(letterSpecial, "C") == 0)
	{
		theGrade.finalMark = 62;
	}
	else if (strcmp(letterSpecial, "D") == 0)
	{
		theGrade.finalMark = 57;
	}
	else if (strcmp(letterSpecial, "F") == 0)
	{
		theGrade.finalMark = 50;
	}
	else if (strcmp(letterSpecial, "0") == 0)
	{
		theGrade.finalMark = 0;
	}
	else if (strcmp(letterSpecial, "I") == 0)
	{
		theGrade.returnCode = SPECIAL_SITUATION_INCOMPLETE;
	}
	else if (strcmp(letterSpecial, "Q") == 0)
	{
		theGrade.returnCode = SPECIAL_SITUATION_WITHDRAW;
	}
	else if (strcmp(letterSpecial, "AU") == 0)
	{
		theGrade.returnCode = SPECIAL_SITUATION_AUDIT;
	}
	else if (strcmp(letterSpecial, "DNA") == 0)
	{
		theGrade.returnCode = SPECIAL_SITUATION_DID_NOT_ATTEND;
	}
	else if (strcmp(letterSpecial, "I/P") == 0)
	{
		theGrade.returnCode = SPECIAL_SITUATION_IN_PROCESS;
	}
	printGrade();
}

void assessGrade(double finalMark)
{
	theGrade.finalMark = finalMark;
	theGrade.returnCode = NUMBER_GRADE;
	printGrade();
}

void assessGrade(int marks[])
{
	double finalMark = 0;
	for (int i = 0; i < 5; i++)
	{
		finalMark += marks[i];
	}
	finalMark = finalMark / 5;

	theGrade.finalMark = finalMark;
	theGrade.returnCode = NUMBER_GRADE;
	printGrade();
}

void printGrade()
{
	if (theGrade.returnCode == NUMBER_GRADE)
	{
		if (theGrade.finalMark == INT32_MAX)
		{
			std::cout << "Invalid input." << std::endl;
		}
		else
		{
			std::string passFail = "";

			if (theGrade.finalMark > 54.5)
			{
				passFail = "PASS ";
			}
			else
			{
				passFail = "FAIL ";
			}
			std::cout << "Student achieved: " << theGrade.finalMark << "% which is a " << passFail.c_str() << "condition." << std::endl;
		}
	}
	else
	{
		std::cout << "Student had Special Situation: ";
		switch (theGrade.returnCode)
		{
		case SPECIAL_SITUATION_AUDIT:
			std::cout << "AU (Audit Condition)";
			break;
		case SPECIAL_SITUATION_DID_NOT_ATTEND:
			std::cout << "DNA (Did Not Attend Condition)";
			break;
		case SPECIAL_SITUATION_INCOMPLETE:
			std::cout << "I (Incomplete Condition)";
			break;
		case SPECIAL_SITUATION_IN_PROCESS:
			std::cout << "I/P (In Process Condition)";
			break;
		case SPECIAL_SITUATION_WITHDRAW:
			std::cout << "Q (Withdrawal after Drop Date Condition)";
			break;
		}
		std::cout << std::endl;
	}
}