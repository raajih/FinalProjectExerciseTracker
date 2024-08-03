#ifndef EXERCISE_H
#define EXERCISE_H
#include <iostream>
#include <string>
using namespace std;

//BASE CLASS FOR EXERCISES
class Exercise
{
private:
	int duration;//In minutes
	string date;//MM-DD-YYYY format

public:
	Exercise();//Default constructor
	Exercise(int, string);
	
	//Getter and setter for duration
	int getDuration() const;
	void setDuration(int);

	//Getter and setter for date
	string getDate() const;
	void setDate(string, string, string);

	//Display info
	void displayInfo() const;

};

#endif
