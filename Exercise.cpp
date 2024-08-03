#include "Exercise.h"

//Constructors
Exercise::Exercise()//Default
{
	duration = 0;
	date = "";
}
Exercise::Exercise(int dur, string day)
{
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
void Exercise::setDate(string month, string day, string year)
{
	if (month.length() != 2)//If month isn't two digits
	{
		throw invalid_argument("Error. Month needs TWO digits\n");
	}
	if (day.length() != 2)//If day isn't two digits
	{
		throw invalid_argument("Error. Day needs TWO digits\n");
	}
	if (year.length() != 4)//If year isn't four digits
	{
		throw invalid_argument("Error. Year needs FOUR digits\n");
	}
	date = (month + "-" + day + "-" + year);
}

//Display info
void Exercise::displayInfo() const
{
	cout << "Date: " << date << "\n";
	cout << "Duration: " << duration << " minutes\n";
}