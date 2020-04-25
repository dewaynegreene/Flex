#include "workout.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Workout::Workout() {}

Workout::~Workout() {}

void Workout::set_completion(char choice)
{
    switch(choice)
    {
        case '0':
            break;
        case '1':
            tricep = true;
            break;
        case '2':
            bicep = true;
            break;
        case '3':
            quad = true;
            break;
        case '4':
            glutes = true;
            break;
        case '5':
            abdomen = true;
            break;
        case '6':
            back = true;
            break;
        default:
            cout << "You entered invalid choices! The valid choices have been saved.\n";
    }

}

void Workout::set_dotw(int dotw)
{
    dayoftheweek = dotw;
}

void age_check(int age, Workout w) {
    if (age > 55) {
        if (w.get_dotw() >= 5) {
            w.set_dotw(4);
            cout << "\nIt is recommended that you only exercise a maximum of 4 days a week so you can have rest days in between.\n";
        }
    }
}

int Workout::get_dotw()
{
    return dayoftheweek;
}

void Workout::set_gym(char input)
{
    gym = input;
}



