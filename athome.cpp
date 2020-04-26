#include "athome.h"
#include <iostream>

void athome::equipment(char equip_param) {
    equip = equip_param;
}

string athome::bicep_workout() {
    if (equip == 'y') {
        bicep_exercise = "Dumbbell Curls: 5 sets of 10 reps";//polymorphism
    } if (equip == 'n') {
        bicep_exercise = "Inclined Push-ups: 5 sets of 10-20 reps";//polymorphism
    }
    return bicep_exercise;
}

string athome::tricep_workout() {
    if (equip == 'y') {
        tricep_exercise = "Bench Dips: 5 sets of 10 reps";//polymorphism
    } if (equip == 'n') {
        tricep_exercise = "Close Grip Push-ups: 5 sets of 10-20 reps";//polymorphism
    }
    return tricep_exercise;
}

string athome::quad_workout() {
    if (equip == 'y') {
        quad_exercise = "Weighed Lunges: 5 sets of 10 reps";//polymorphism
    } if (equip == 'n') {
        quad_exercise = "Squats: 5 sets of 10-20 reps";//polymorphism
    }
    return quad_exercise;
}

string athome::glutes_workout() {
    if (equip == 'y') {
        glutes_exercise = "Weighted Hip thrusts: 5 sets of 10 reps";//polymorphism
    } if (equip == 'n') {
        glutes_exercise = "Walking Lunges: 5 sets of 10-20 reps";//polymorphism
    }
    return glutes_exercise;
}

string athome::abdomen_workout() {
    if (equip == 'y') {
        abdomen_exercise = "Weighted Crunches: 5 sets of 10 reps";//polymorphism
    } if (equip == 'n') {
        abdomen_exercise = "Sit-ups: 5 sets of 10-20 reps";//polymorphism
    }
    return abdomen_exercise;
}

string athome::back_workout() {
    if (equip == 'y') {
        back_exercise = "Dumbbell Rows: 5 sets of 10 reps";//polymorphism
    } if (equip == 'n') {
        back_exercise = "Wide Grip Push-ups: 5 sets of 10-20 reps";//polymorphism
    }
    return back_exercise;
}

