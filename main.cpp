#include "person.h"
#include "workout.h"
#include "athome.h"
#include "atgym.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
   
    char account;
    string firstname;
    string lastname;
	int age;
	char sex;
	int feetheight;
	int inchheight;
	double weight;
	char selection = '\0';
	int dotw;
	char gym;
	char equipment;


   cout << "Workout Planner\n\n";
   
   cout << "Do you have an account? (y/n): ";
   cin >> account;
   
   if(account == 'y')
   {
	cout << "Which one is you?";
	//Here we can use a for loop with the condition being i<count to loop through all the Person objects that exist.
   }
   else if(account == 'n')
   {
    Person p;
	cout << "\nEnter your first name: ";
	cin >> firstname;
	cout << "Enter your last name: ";
	cin >> lastname;
	p.set_name(firstname, lastname);
	cout << "Enter your age: ";
	cin >> age;
	p.set_age(age);
	cout << "Enter your sex (m/f): ";
	cin >> sex;
	p.set_age(sex);
	cout << "Enter your height (feet inches): ";
	cin >> feetheight;
	cin >> inchheight;
	p.set_height(feetheight, inchheight);
	cout << "Enter your weight (lbs): ";
	cin >> weight;
	p.set_weight(weight);

    
	//All this is just information about the user.
	//We can push this person to the vector of people we have created.

	cout << "\nWelcome " << firstname << "! What body parts would you like to add to your plan? (Enter the corresponding numbers seperated by a space. Enter '0' when you are done) \n";
	cout << "1.Triceps\n2.Biceps\n3.Quads\n4.Glutes\n5.Abdomen\n6.Back\n\nSelections: ";

	Workout w;
    atgym g;
    athome h;
	
	while(selection != '0') 
	{
		cin >> selection;
		w.set_completion(selection);
	}

	cout << "How many days of the week do you want to exercise?: "; //user validation 1-7
	cin >> dotw;
	w.set_dotw(dotw);

	cout << "Do you have a gym membership? (y/n): ";
	cin >> gym;
	w.set_gym(gym);

    vector <string> workouts;
       
	if(gym == 'n')
	{
		cout << "Do you have gym equipment at home? (y/n): ";
		cin >> equipment;
		h.equipment(equipment);
            if (w.bicep == true) {
                string b = h.bicep_workout();
                workouts.push_back(b);
            }
            if (w.tricep == true) {
                string t = h.tricep_workout();
                workouts.push_back(t);
            }
            if (w.quad == true) {
                string q = h.quad_workout();
                workouts.push_back(q);
            }
            if (w.glutes == true) {
                string g = h.glutes_workout();
                workouts.push_back(g);
            }
            if (w.abdomen == true) {
                string a = h.abdomen_workout();
                workouts.push_back(a);
            }
            if (w.back == true) {
                string back = h.back_workout();
                workouts.push_back(back);
            }
    } else if (gym == 'y') {
            if (w.bicep == true) {
                string b = g.bicep_workout();
                workouts.push_back(b);
            }
            if (w.tricep == true) {
                string t = g.tricep_workout();
                workouts.push_back(t);
            }
            if (w.quad == true) {
                string q = g.quad_workout();
                workouts.push_back(q);
            }
            if (w.glutes == true) {
               // string g = g.glutes_workout(); //not working
               // workouts.push_back(g);
            }
            if (w.abdomen == true) {
                string a = g.abdomen_workout();
                workouts.push_back(a);
            }
            if (w.back == true) {
                string back = g.back_workout();
                workouts.push_back(back);
            }
    }

        //double bmi = p.printbmi;

       ofstream outfile;                    //Write to workout_planner.txt
       outfile.open("workout_planner.txt"); 
        outfile << firstname << "'s Info\n";
        outfile << "-------------------------------\n";
        outfile << "Height: " << feetheight << "' " << inchheight << "''\n";
        outfile << "Weight: " << weight << '\n';
      //  outfile << "BMI: " << bmi << '\n';
        outfile << firstname << "'s Workout Planner\n";
        outfile << "-------------------------------\n";
        for (const auto &e : workouts)
            outfile << e << "\n";
       

    }//end of else if
   

	return 0;


}
