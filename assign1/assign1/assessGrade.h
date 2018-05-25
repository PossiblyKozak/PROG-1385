#define NUMBER_GRADE							0
#define SPECIAL_SITUATION_INCOMPLETE			1
#define SPECIAL_SITUATION_WITHDRAW				2
#define SPECIAL_SITUATION_AUDIT					3
#define SPECIAL_SITUATION_DID_NOT_ATTEND		4
#define SPECIAL_SITUATION_IN_PROCESS			5


#ifndef IS_DEFINED
	/* ---------------------------------------------------------- */
	/* Structure used to hold the current time                    */
	/* ---------------------------------------------------------- */
	struct grade
	{
		int returnCode;
		double finalMark;
	};

	// single variable used to hold the currently configured time
	grade theGrade = { 0, 0 }; // global variable – YIKERS!!
#else
	struct grade
	{
		int returnCode;
		double finalMark;
	};
	extern grade theGrade;
#endif

void assessGrade(int[]);
void assessGrade(double);
void assessGrade(const char*);
void printGrade();