#include "Exercise.h"
#include "Running.h"
#include "Lifting.h"
#include <vector>

int main()
{
	Lifting workout1, workout2;
	try
	{
		//TEST
		workout2.setDuration(60);
		workout2.setDate("02", "16", "2000");
		workout2.setMuscleGroup("Back");
		workout2.displayInfo();

	}
	catch (invalid_argument e)
	{
		cout << e.what();
	}




	return 0;
}