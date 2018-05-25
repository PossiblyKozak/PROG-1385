#include <iostream>
#include <string>
#include "assessGrade.h"

int main()
{
	std::string input;
	std::getline(std::cin, input);
	while (strcmp(input.c_str(), "X") != 0)
	{		
		if (atoi(input.c_str()) == atof(input.c_str()) && input.find('.') == std::string::npos && atoi(input.c_str()) != 0)
		{
			int marks[5] = { atoi(input.c_str()), 0, 0, 0, 0 };
			int i = 1;
			while (strchr(input.c_str(), ' ') != false && i != 5)
			{		
				input = strchr(input.c_str(), ' ') + sizeof(char);
				marks[i] = atoi(input.c_str());
				i++;
			}
			if (strchr(input.c_str(), ' ') == false)
			{
				assessGrade(marks);
			}			
			else
			{
				assessGrade("Invalid");
			}
		}
		else if (input.find('.') != std::string::npos)
		{
			assessGrade(atof(input.c_str()));
		}
		else
		{
			assessGrade(input.c_str());
		}
		std::getline(std::cin, input);
	}	

	return 0;
}