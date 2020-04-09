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
	string height;
	double weight;


   cout << "Workout Planner\n\n";
   cout << "Do you have an account? (y/n): ";
   cin >> account;
   
   if(account == 'y')
   {
	cout << "What is your first name";
   }
   else
   {
    //  Person p;
	cout << "\nEnter your first name: ";
	cin >> firstname;
	cout << "Enter your last name: ";
	cin >> lastname;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter your sex (m/f): ";
	cin >> sex;
	cout << "Enter your height: ";
	cin >> height;
	cout << "Enter your weight: ";
	cin >> weight;
   }

	return 0;


}
