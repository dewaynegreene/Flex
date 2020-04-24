#include "workout.h"
#include <iostream>

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

int Workout::get_dotw()
{
    return dayoftheweek;
}

void Workout::set_gym(char input)
{
    gym = input;
}

string breaks(Workout workout) {
    if (workout.get_dotw() > 5)
        return "With the amount of days you selected you will not have that many breaks between workouts. If you feel fatigued consider lowering the reps on the exercises";
    return 0;
}

void read_file() {
    ifstream infile;
    infile.open("profiles.txt");
    
    
}
