#include "Exercise.h"
#include "Running.h"
#include "Lifting.h"
#include <vector>
#include <fstream>

//Prototypes
void addRun(vector<Running>&, Running);
void addLift(vector<Lifting>&, Lifting);
void sortByDate(vector<Running>&);
void swap(Running&, Running&);
void extractDateComponents(const Running&, int&, int&, int&);
void extractDateComponents(const Lifting&, int&, int&, int&);
void bubbleSortByDate(vector<Running>&);
void bubbleSortByDate(vector<Lifting>&);
void saveToFile(vector<Running>);
void saveToFile(vector<Lifting>);
void readFromFile(vector<Running>&);
void readFromFile(vector<Lifting>&);
int menu();

int main()
{
	vector<Running> newRunningLog;//Hold new runs
    vector<Lifting> newLiftingLog;//Hold new lifts

    vector<Running> oldRunningLog;//Hold old runs
    vector<Lifting> oldLiftingLog;//Hold old lifts

    //Get previous lifts and runs
    readFromFile(oldRunningLog);
    readFromFile(oldLiftingLog);

    int choice;//Choice for menu
	try
	{
        do 
        {
            choice = menu();

            switch (choice)
            {
            case 1://Read from running log file
                if (oldRunningLog.size() == 0)
                {
                    cout << "No previous runs\n";
                }
                else
                {
                    for (Running run : oldRunningLog)
                    {
                        run.displayInfo();
                    }
                }
                break;
            case 2://Read from lifting log file
                if (oldLiftingLog.size() == 0)
                {
                    cout << "No previous lifts\n";
                }
                else
                {
                    for (Lifting lift: oldLiftingLog)
                    {
                        lift.displayInfo();
                    }
                }
                break;
            case 3://Input new run into vector
            {
                int duration;
                string date;
                double distance;
                cout << "How long did you run for in whole minutes: ";
                cin >> duration;
                cin.ignore();
                cout << "What was the date you ran on? (MM-DD-YYYY): ";
                getline(cin, date);
                cout << "How far did you run in miles?: ";
                cin >> distance;
                cin.ignore();
                Running run(duration, date, distance);//Make a running object
                addRun(newRunningLog, run);//Add run to new running log
                cout << "Run added to temporary memory!\n";
                break;
            }
            case 4://Input new lift into vector
            {
                int duration;
                string date;
                string muscle;
                cout << "How long did you lift weights for in whole minutes: ";
                cin >> duration;
                cin.ignore();
                cout << "What was the date you lifted weights on? (MM-DD-YYYY): ";
                getline(cin, date);
                cout << "What muscle group did you hit?: ";
                getline(cin, muscle);
                Lifting lift(duration, date, muscle);//Make a lifting object
                addLift(newLiftingLog, lift);//Add lift to new lifting log
                cout << "Lift added to temporary memory!\n";
                break;
            }
            case 5://Combine new and old, then sort and save
                oldLiftingLog.insert(oldLiftingLog.end(), newLiftingLog.begin(), newLiftingLog.end());//Combine lift vectors
                oldRunningLog.insert(oldRunningLog.end(), newRunningLog.begin(), newRunningLog.end());//Combine run vectors
                bubbleSortByDate(oldLiftingLog);
                bubbleSortByDate(oldRunningLog);
                saveToFile(oldLiftingLog);
                saveToFile(oldRunningLog);
                break;
            }
        } while (choice != 5);

        
		
		
	}
	catch (invalid_argument e)
	{
		cout << e.what();
	}




	return 0;
}

void addRun(vector<Running> &runningLog, Running run)//Add a run to the running log
{
	runningLog.push_back(run);
}


void addLift(vector<Lifting>& liftingLog, Lifting lift)//Add a lifting session to the lifting log
{
	liftingLog.push_back(lift);
}

void swap(Running &a, Running &b)//For running class
{
	Running temp = a;
	a = b;
	b = temp;
}

void swap(Lifting& a, Lifting& b)//For lifting class
{
    Lifting temp = a;
    a = b;
    b = temp;
}

// Function to extract date components as integers for Running class
void extractDateComponents(const Running& run, int& year, int& month, int& day)
{
    string date = run.getDate();
    year = stoi(date.substr(6, 4));
    month = stoi(date.substr(0, 2));
    day = stoi(date.substr(3, 2));
}

//Function to extract date components as integers for Lifting class
void extractDateComponents(const Lifting& lift, int& year, int& month, int& day)
{
    string date = lift.getDate();
    year = stoi(date.substr(6, 4));
    month = stoi(date.substr(0, 2));
    day = stoi(date.substr(3, 2));
}

// Bubble sort function for running class
void bubbleSortByDate(vector<Running>& runningLog)
{
    bool swapped;
    int n = runningLog.size();

    do
    {
        swapped = false;
        for (int i = 0; i < n - 1; ++i)
        {
            int year1, month1, day1;
            int year2, month2, day2;

            extractDateComponents(runningLog[i], year1, month1, day1);
            extractDateComponents(runningLog[i + 1], year2, month2, day2);

            if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2))
            {
                swap(runningLog[i], runningLog[i + 1]);
                swapped = true;
            }
        }
        --n; // Reduce the range for the next pass
    } while (swapped);
}

// Bubble sort function for lifting class
void bubbleSortByDate(vector<Lifting>& liftingLog)
{
    bool swapped;
    int n = liftingLog.size();

    do
    {
        swapped = false;
        for (int i = 0; i < n - 1; ++i)
        {
            int year1, month1, day1;
            int year2, month2, day2;

            extractDateComponents(liftingLog[i], year1, month1, day1);
            extractDateComponents(liftingLog[i + 1], year2, month2, day2);

            if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2))
            {
                swap(liftingLog[i], liftingLog[i + 1]);
                swapped = true;
            }
        }
        --n; // Reduce the range for the next pass
    } while (swapped);
}

void saveToFile(vector<Running> runLog)//Save to running file
{
    fstream output;
    output.open("runLog.txt", ios::out);//Open file

    for (Running run : runLog)//Loop through running log and output to file
    {
        output << run.getDate() << "\n";
        output << run.getDuration() << "\n";
        output << run.getDistance() << "\n";
    }

    cout << "Data saved successfully\n";
    output.close();//Close

}

void saveToFile(vector<Lifting> liftLog)//Save to lifting file
{
    fstream output;
    output.open("liftLog.txt", ios::out);//Open in app mode

    for (Lifting lift : liftLog)
    {
        output << lift.getDate() << "\n";
        output << lift.getDuration() << "\n";
        output << lift.getMuscleGroup() << "\n";
    }

    cout << "Data saved successfully\n";
    output.close();
}

int menu()
{
    int choice;

    cout << "1. See previous runs\n"
        << "2. See previous lifting sessions\n"
        << "3. Input new run\n"
        << "4. Input new lifting session\n"
        << "5. Save exercises and exit\n"
        << "Input choice (1-5): ";
    cin >> choice;

    while (choice < 1 || choice > 5)
    {
        cout << "Invalid choice. Please try again: ";
        cin >> choice;
    }
    cin.ignore();

    return choice;
}

void readFromFile(vector<Running>& runLog)//Read from running log
{
    fstream input;
    input.open("runLog.txt", ios::in);

    if (input.fail())//If file doesn't exist
    {
        input.open("runLog.txt", ios::out);//Create if doesn't exist
    }
    else//File exists
    {
        string date;
        int duration;
        double distance;

        while (getline(input, date))//While still reading from a file
        {
            input >> duration;
            input >> distance;
            Running run(duration, date, distance);
            addRun(runLog, run);//Add run to vector
            input.ignore();
        }
    }
}

void readFromFile(vector<Lifting>& liftLog)//Read from lifting log
{
    fstream input;
    input.open("liftLog.txt", ios::in);

    if (input.fail())//If file doesn't exist
    {
        input.open("runLog.txt", ios::out);//Create if doesn't exist
    }
    else//File exists
    {
        string date;
        int duration;
        string muscle;

        while (getline(input, date))//While still reading from a file
        {
            input >> duration;
            input.ignore();
            getline(input, muscle);
            Lifting lift(duration, date, muscle);
            addLift(liftLog, lift);//Add lift to vector
            input.ignore();
        }
    }
}