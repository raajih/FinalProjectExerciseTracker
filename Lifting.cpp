#include "Lifting.h"

Lifting::Lifting() : Exercise()//Default constructor
{
	type = "Lift";
	muscleGroup = "No muscle group added";
}

Lifting::Lifting(int dur, string day, string muscle) : Exercise(dur, day)
{
	type = "Lift";
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
	cout << type << "\n";
	Exercise::displayInfo();//Call original displayInfo
	cout << "Muscle Group: " << muscleGroup << "\n";
}

//Overload = 
Lifting& Lifting:: operator=(const Lifting& right)
{
	setDuration(right.getDuration());//Set the duration
	setDate(right.getDate());//Set the date
	muscleGroup = right.muscleGroup;//Set distance
	return *this;
}