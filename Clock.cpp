/**
*This program displays a 12 hour and 24 hour clock.
*The hours, minutes, and seconds can be adjusted by the user through a displayed menu.
*
*Author: Clay Dodson
*Date: 05/22/2021
*/



#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int hours12, hours24, minutes, seconds;      //global variables
string ampm;

void addHour() {                             //function to add an hour to the clock

    hours12 = hours12 + 1;

    if (hours12 >= 12) {                     //after adding function, then set the clock
        hours12 = hours12 - 12;
        if (ampm == "AM")                    //AM/PM decision branch
            ampm = "PM";
        else
            ampm = "AM";
    }
}

void addMinute() {                           //function to add a minute to the clock
    minutes = minutes + 1;
    if (minutes > 59) {
        minutes = 0;
        addHour();

    }
}

void addSecond() {                           //function to add a second to the clock
    seconds = seconds + 1;
    if (seconds > 59) {
        seconds = 0;
        addMinute();
    }
}

int main() {                                 //main function
    
    int choice = 0;                          //local variables
   
    hours12 = 1;                             //set the initial clock time manually
    minutes = 30;
    seconds = 45;
    ampm = "PM";
    
    while (1) {                              //while loop until user chooses to exit
        
        if (ampm == "PM") {                  //calculating the 24 hour clock display
            hours24 = hours12 + 12;
            if (hours24 >= 24) {
                hours24 = hours24 - 24;
            }
        }
        else {
            hours24 = hours12;
        }
        
        cout << "****************************\t\t****************************\n";                //printing the clock
        cout << "*      12-Hour clock       *\t\t*      24-Hour clock       *\n";
        cout << "*       " << setw(2) << setfill('0') << hours12 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << ampm << "        *";
        cout << "\t\t*         " << setw(2) << setfill('0') << hours24 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << "        *\n";
        cout << "****************************\t\t****************************\n";
        
        cout << "\n\n****************************\n";                                            //printing the menu
        cout << "* 1-Add one hour           *\n";
        cout << "* 2-Add one minutes        *\n";
        cout << "* 3-Add one second         *\n";
        cout << "* 4-Exit program           *\n";
        cout << "****************************\n";
        cout << "Choose an option: ";
        cin >> choice;
                                                    //calling functions based on user input
        if (choice == 1) {                       
            
            addHour();                              //function to add an hour
        }
        else if (choice == 2) {
            
            addMinute();                            //function to add a minute
        }
        else if (choice == 3) {
            
            addSecond();                            //function to add second
        }
        else if (choice == 4) {
            
            cout << "Exiting program...";           //option for user to exit program
            break;
        }
        else {
            
            cout << "Invalid input. Try Again...";  //added error message for incorrect user inputs
        }
    }
    return 0;
}