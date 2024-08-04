#ifndef LIFTING_H
#define LIFTING_H
#include "Exercise.h"


class Lifting : public Exercise
{
private:
	string muscleGroup;

public:
	//Constructors
	Lifting();
	Lifting(int, string, string);

	//Getter and setter for muscle group
	string getMuscleGroup() const;
	void setMuscleGroup(string);

	//Overload display info function
	void displayInfo() const;
};

#endif