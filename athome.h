#ifndef ATHOME_H
#define ATHOME_H
#include <string>
#include "workout.h"


class athome : public Workout
{
    private:
        char equip;
    protected:
        
    public:
        void equipment(char);
    
        string bicep_workout();
        string tricep_workout();
        string quad_workout();
        string glutes_workout();
        string abdomen_workout();
        string back_workout();
};

#endif //PERSON_H
