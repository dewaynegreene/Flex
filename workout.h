#ifndef WORKOUT_H
#define WORKOUT_H
#include <string>
#include <fstream>
#include <iostream>
#include "person.h"

using namespace std;

class Workout
{
    private:
        int dayoftheweek;

        string bicep_exercise;
        string tricep_exercise;
        string quad_exercise;
        string glutes_exercise;
        string abdomen_exercise;
        string back_exercise;
        char gym;
    protected:

    public:
        bool bicep = false;
        bool tricep = false;
        bool quad = false;
        bool glutes = false;
        bool abdomen = false;
        bool back = false;
        Workout();
        virtual ~Workout();
        void set_completion(char choice); //This will change the boolean variable of each data member depending if the user entered its value or not
        void set_dotw(int dotw);
        int get_dotw();
        void set_gym(char input);
        string bicep_workout(); //These will return workout for each variable
        string tricep_workout();
        string quad_workout();
        string glutes_workout();
        string abdomen_workout();
        string back_workout();
        friend void age_check(int age, Workout w);
    

};

#endif //WORKOUT_H
