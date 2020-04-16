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
            cout << "You entered invalid choices! The valid choices have been saved.";
    }

}

void Workout::set_dotw(int dotw)
{
    dayoftheweek = dotw;
}

void Workout::get_dotw()
{
    cout << dayoftheweek;
}

void Workout::set_gym(char input)
{
    gym = input;
}

void Workout::set_equipment(char input)
{
    equipment = input;
}