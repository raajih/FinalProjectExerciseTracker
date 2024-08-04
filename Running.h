#ifndef RUNNING_H
#define RUNNING_H
#include "Exercise.h"


class Running : public Exercise
{
private:
	string type;//Run or lift
	double distance;//In miles

public:
	//Constructors
	Running();
	Running(int, string, double);

	//Getter and setter for distance
	double getDistance() const;
	void setDistance(int);

	double calcSpeed() const;//Calculate average running speed

	void displayInfo() const override;//Overload display info function

	Running& operator=(const Running&);//Overload = operator
};

#endif