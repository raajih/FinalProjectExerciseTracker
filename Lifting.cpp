#include "Lifting.h"

Lifting::Lifting() : Exercise()//Default constructor
{
	muscleGroup = "No muscle group added";
}

Lifting::Lifting(int dur, string day, string muscle) : Exercise(dur, day)
{
	muscleGroup = muscle;
}

//Getter and setter for muscle group
string Lifting::getMuscleGroup() const
{
	return muscleGroup;
}
void Lifting::setMuscleGroup(string muscle)
{
	muscleGroup = muscle;
}

//Display info
void Lifting::displayInfo() const
{
	Exercise::displayInfo();//Call original displayInfo
	cout << "Exercise Type: Weight Lifting\n"
		<< "Muscle Group: " << muscleGroup << "\n";
}