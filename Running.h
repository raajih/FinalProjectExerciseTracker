#ifndef RUNNING_H
#define RUNNING_H
#include "Exercise.h"


class Running : public Exercise
{
private:
	int distance;//In miles

public:
	//Constructors
	Running();
	Running(int, string, int);

	//Getter and setter for distance
	int getDistance() const;
	void setDistance(int);

	double calcSpeed() const;//Calculate average running speed

	void displayInfo() const;//Overload display info function
};

#endif