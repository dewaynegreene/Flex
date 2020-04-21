#include "person.h"
#include "workout.h"
#include "athome.h"
#include "atgym.h"
#include <iostream>
#include <string>

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

	if(gym == 'n')
	{
		cout << "Do you have gym equipment at home? (y/n): ";
		cin >> equipment;
		h.equipment(equipment);
            if (w.bicep == true) {
                h.bicep_workout();
            } else if (h.tricep == true) {
                h.tricep_workout();
            } else if (h.quad == true) {
                h.quad_workout();
            } else if (h.glutes == true) {
                h.glutes_workout();
            } else if (h.abdomen == true) {
                h.abdomen_workout();
            } else if (h.back == true) {
                h.back_workout();
            }
    } else if (gym == 'y') {
        if (w.bicep == true) {
            g.bicep_workout();
        } else if (h.tricep == true) {
            g.tricep_workout();
        } else if (h.quad == true) {
            g.quad_workout();
        } else if (h.glutes == true) {
            g.glutes_workout();
        } else if (h.abdomen == true) {
            g.abdomen_workout();
        } else if (h.back == true) {
            g.back_workout();
        }
    }

	
 	

    }//end of else if
   

	return 0;


}
