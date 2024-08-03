#include "Exercise.h"
#include "Running.h"

int main()
{
	 Running workout1, workout2;
	try
	{
		//TEST
		workout2.setDuration(20);
		workout2.setDate("02", "16", "2000");
		workout2.setDistance(-12);
		workout1.displayInfo();
		workout2.displayInfo();

	}
	catch (invalid_argument e)
	{
		cout << e.what();
	}




	return 0;
}