#ifndef LIFTING_H
#define LIFTING_H
#include "Exercise.h"


class Lifting : public Exercise
{
private:
	string type, muscleGroup;

public:
	//Constructors
	Lifting();
	Lifting(int, string, string);

	//Getter and setter for muscle group
	string getMuscleGroup() const;
	void setMuscleGroup(string);

	//Overload display info function
	void displayInfo() const override;

	Lifting& operator=(const Lifting&);//Overload = operator
};

#endif