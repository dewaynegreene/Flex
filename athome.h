#ifndef ATHOME_H
#define ATHOME_H
#include <string>
#include "workout.h"
#include "person.h"

class athome : public Workout
{
    private:
        char equip;
	
    protected:
        
    public:
        void equipment(char);
};

#endif //PERSON_H
