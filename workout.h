#ifndef WORKOUT_H
#define WORKOUT_H
#include <string>
#include "person.h"

using namespace std;

class Workout : public Person
{
    private:
        int dotw;
        bool bicep;
        bool tricep;
        bool quad;
        bool glutes;
        bool abdomen;
        bool back;
    protected:

    public:
        void set_completion(int); //This will change the boolean variable of each data member depending if the user entered its value or not
        void set_dotw();
        void get_dotw();
        void read_file();
        virtual void write_file();
        string bicep_workout(); //These will return workout for each variable
        string tricep_workout();
        string quad_workout();
        string glutes_workout();
        string abdomen_workout();
        string back_workout();
        friend void set_sex();
        virtual string planner();

};

#endif //WORKOUT_H
