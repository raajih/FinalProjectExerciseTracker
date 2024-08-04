#include "Running.h"

//Constructors
Running::Running() : Exercise()
{
	type = "Run";
	distance = 0;
}
Running::Running(int dur, string day, double dis) : Exercise(dur, day)
{
	type = "Run";
	distance = dis;
}

//Getter and setter for distance
double Running::getDistance() const
{
	return distance;
}
void Running::setDistance(int dis)
{
	if (dis < 0)
	{
		throw invalid_argument("Error. Distance must be nonnegative\n");
	}
	distance = dis;
}

//Calculate speed
double Running::calcSpeed() const
{
	if (getDuration() == 0)//In case duration is 0
	{
		throw invalid_argument("Error. Cannot divide by zero");
	}
	double speed;
	speed = (distance / (getDuration() / 60.0));//Divide miles by hour to get mph (have to convert minutes to hour)
	return speed;

}

//Display info
void Running::displayInfo() const
{
	cout << type << "\n";
	Exercise::displayInfo();//Call original display info
	cout << "Distance: " << distance << " miles\n";
	cout << "Average speed: " << calcSpeed() << " mph\n";
}

//Overload = 
Running& Running:: operator=(const Running& right)
{
	setDuration(right.getDuration());//Set the duration
	setDate(right.getDate());//Set the date
	distance = right.distance;//Set distance
	return *this;
}