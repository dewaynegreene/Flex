#ifndef ATGYM_H
#define ATGYM_H
#include "workout.h"

class atgym : public Workout //inherits fromm workout
{
    private:

    protected:

    public:
           string bicep_workout();
           string tricep_workout();
           string quad_workout();
           string glutes_workout();
           string abdomen_workout();
           string back_workout();

};

#endif //ATGYM_H
