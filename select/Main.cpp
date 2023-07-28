#include "lib.h"


int main()
{
	LockConsoleWindowSize();


	while (true)
	{

		Menu();

		Get_Answer(option_select);


		system("pause");
	}

	return 0;
}