#include "Exercise.h"

int main()
{
	Exercise workout1, workout2;
	try
	{
		workout2.setDuration(20);
		workout2.setDate("0", "16", "2000");
		//TEST
		workout1.displayInfo();
		workout2.displayInfo();

	}
	catch (invalid_argument e)
	{
		cout << e.what();
	}




	return 0;
}