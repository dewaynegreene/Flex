#include "atgym.h"
#include <iostream>


string atgym::bicep_workout() {
    bicep_exercise = "Dumbbell Curls: 5 sets of 10 reps";//polymorphism
    return bicep_exercise;
}

string atgym::tricep_workout() {
    tricep_exercise = "Seated Machine Dip: 3 sets of 10 reps";//polymorphism
    return tricep_exercise;
}

string atgym::quad_workout() {
    quad_exercise = "Leg Press: 3 sets of 10 reps";//polymorphism
    return quad_exercise;
}

string atgym::glutes_workout() {
    glutes_exercise = "Weighted Squats: 5 sets of 5 reps";//polymorphism
    return glutes_exercise;
}

string atgym::abdomen_workout() {
    abdomen_exercise = "Dumbbell Crunches: 3 sets of 10 reps";//polymorphism
    return abdomen_exercise;
}

string atgym::back_workout() {
    back_exercise = "Deadlift: 5 sets of 5 reps";//polymorphism
    return back_exercise;
}
