#include "Exercise.h"
#include "Running.h"
#include "Lifting.h"
#include <vector>

int main()
{
	vector<Exercise*> workoutLog;
	//Have to use pointers in order for the correct display info function to be called
	Exercise* workout1 = new Running();
	Exercise* workout2 = new Lifting();
	try
	{
		//TEST
		Exercise* workout1 = new Running(65,"04-12-1999", 24);
		Exercise* workout2 = new Lifting(60, "02-16-2000", "Back");

		workoutLog.push_back(workout1);
		workoutLog.push_back(workout2);

		for (auto& x : workoutLog)
		{
			x->displayInfo();
		}

	}
	catch (invalid_argument e)
	{
		cout << e.what();
	}




	return 0;
}