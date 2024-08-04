#include "Exercise.h"

//Constructors
Exercise::Exercise()//Default
{
	duration = 0;
	date = "No date added";
}
Exercise::Exercise(int dur, string day)
{
	if (day.length() != 10)
	{
		throw invalid_argument("Error. Invalid date format.");
	}
	duration = dur;
	date = day;
}

//Getter and setter for duration
int Exercise::getDuration() const
{ 
	return duration;
}
void Exercise::setDuration(int dur)
{
	if (dur < 0)
	{
		throw invalid_argument("Error. Duration must be nonnegative\n");
	}
	duration = dur;
}

//Getter and setter for date
string Exercise::getDate() const
{
	return date;
}
void Exercise::setDate(string dateNew)
{
	
	date = dateNew;
}

//Display info
void Exercise::displayInfo() const
{
	cout << "Date: " << date << "\n";
	cout << "Duration: " << duration << " minutes\n";
}