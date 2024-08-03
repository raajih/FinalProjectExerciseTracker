#include "Running.h"

//Constructors
Running::Running() : Exercise()
{
	distance = 0;
}
Running::Running(int dur, string day, int dis) : Exercise(dur, day)
{
	distance = dis;
}

//Getter and setter for distance
int Running::getDistance() const
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
	speed = (distance / (getDuration() / 60));//Divide miles by hour to get mph (have to convert minutes to hour)
	return speed;

}

//Display info
void Running::displayInfo() const
{
	Exercise::displayInfo();//Call original display info
	cout << "Distance: " << distance << " miles\n";
}