#include "person.h"
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

	cout << "\nWelcome " << firstname << "! What body parts would you like to add to your plan? (Enter the corresponding numbers seperated by a space) \n";
	cout << "1. Triceps\n2.Biceps\n3.Quads\n4.Glutes\n5.Abdomen\n6.Back";
	//cin << selection
   }
   

	return 0;


}
