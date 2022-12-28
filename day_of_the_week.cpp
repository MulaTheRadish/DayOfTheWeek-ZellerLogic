//loading necessary libraries
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
//produces a number ranging from 0-6, which will be used as an index for an array.
int algorithm(int dd, int mm, int yy)
{
    //Rules according to Zeller's Algorithm:
    //For march to december, mm is 3-12. For January and February it is 13 and 14 respectively. 
    //If we consider January and February, then we must deduct 1 from the year. 
    //Algorithm considers both the first 2 characters, and last 2 characters of the year. 
    if (mm > 2) 
    { 
        mm = mm; 
    }
    else 
    { 
        mm = mm + 12;
        yy--;
    }
    int l2y = yy % 100; //last 2 characters of the year.
    int f2y = yy / 100; // first 2 characters of the year.
    //Zeller's Algorithm:
    int wd = dd + floor((13 * (mm + 1)) / 5) + l2y + l2y / 4 + f2y / 4 + f2y * 5;
    wd = wd % 7;
    return wd;
}

int main()
{
    //defining variables:
    string date;
    char delimiter = '/';
    int dd, mm, yy;
    //Zeller's algorithm produces an index specific to this order of weekdays. 
    const string weekday[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    //receiving and cleaning input (purging ' '):
    cout << "Enter a date (dd/mm/yy): ";
    getline (cin, date);
    date.erase(remove(date.begin(), date.end(), ' '));
    //splitting the string up into its individual components as integers from strings(dd/mm/yy):
    dd = stoi(date.substr(0, date.find(delimiter)));
    date.erase(0, date.find(delimiter) + 1);
    mm = stoi(date.substr(0, date.find(delimiter)));
    yy = stoi(date.substr(date.find(delimiter) + 1));
    //printing the final output, using the return value of algorithm() as an index for the array weekday[]:
    cout << "The day of the week on the given date is: " << weekday[algorithm(dd, mm, yy)] << endl;
}