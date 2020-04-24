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
    int user;
    int update;
    vector<Person>vec;

    
   cout << "Workout Planner\n\n";
   
    
   cout << "Do you have an account? (y/n): ";
   cin >> account;
   
   if(account == 'y')
   {
	cout << "Which one is you?\n";
	
    ifstream iprofile;
    iprofile.open("profiles.txt");
    string line;

    while(!iprofile.eof())
    {
        Person f;
        string filefname, filelname;
        char filesex;
        int filefeet, fileinch, fileage;
        double fileweight;
        iprofile >> filefname >> filelname >> fileage >> filesex >> filefeet >> fileinch >> fileweight;
        f.set_name(filefname, filelname);
        f.set_age(fileage);
        f.set_sex(filesex);
        f.set_height(filefeet, fileinch);
        f.set_weight(fileweight);


        vec.push_back(f);
    }

    for(int i=1, l=0; l < vec.size()-1; i++, l++)
    {
        cout << i << ". ";
        cout << vec[l].get_name() << '\n';
    }

    cout << "\nChoice: ";
    cin >> user;
    
    cout <<"\n\nWelcome back " << vec[user-1].get_name() << "!\n" << "-----------------------" << "\nAge: " << vec[user-1].get_age() << "\nSex: " << vec[user-1].get_sex();
    cout <<"\nHeight: " << vec[user-1].get_height() << " inches" << "\nWeight: " << vec[user-1].get_weight() << "\nBMI: " << vec[user-1].printbmi();

    cout << "\n\nWhat would you like to update? ";
    cin >> update;
   }
 /*  if(account == 'y' && vec.size() < 1)
   {
       char choice;
       cout << "There are no created accounts! Would you like to make one? (y/n): ";
       cin >> choice;
       if(choice == 'y')
       {
           account = 'n';
       }
       else if(choice == 'n')
       {
           cout << "Bye!";
       }

   }*/
    if(account == 'n')
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

    //Push person into vector of people
    //vec.push_back(p);

    //Here we create their account in the profiles file

    ofstream profile;
    profile.open("profiles.txt", ios::app);
    profile << firstname << '\t' << lastname << '\t' << age << '\t' << sex << '\t' << feetheight << '\t' << inchheight << '\t' << weight << '\n';
    profile.close();


	//All this is just information about the user.
	//We can push this person to the vector of people we have created.

	cout << "\nWelcome " << firstname << "! What body parts would you like to add to your plan? (Enter the corresponding numbers seperated by a space. Enter '0' when you are done) \n";
	cout << "1.Triceps\n2.Biceps\n3.Quads\n4.Glutes\n5.Abdomen\n6.Back\n\n(Enter 0 when complete)\nSelections: ";

	Workout w;
    atgym g;
    athome h;
	
	while(selection != '0') 
	{
		cin >> selection;
		w.set_completion(selection);
	}

	cout << "How many days of the week do you want to exercise?: ";
	cin >> dotw;
       while (dotw > 7 || dotw < 1) {
           cout << "Yout must enter a number between 1 and 7"<< endl;
           cout << "How many days of the week do you want to exercise?: ";
           cin >> dotw;
       }
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
               //string g = g.glutes_workout();
                //workouts.push_back(g);
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
        outfile << "Age: " << age << '\n';
        outfile << "Height: " << feetheight << "' " << inchheight << "''\n";
        outfile << "Weight: " << weight << '\n';
      //  outfile << "BMI: " << bmi << '\n';
        outfile << firstname << "'s Workout Planner\n";
        outfile << "-------------------------------\n";
       
        //breaks(w);
       for (int i = 1; i <= dotw; i++) {
           outfile << "\nDay "<< i << ": " << endl ;
           for (const auto &e : workouts)
               outfile << "\t" << e << "\n";
       }

    }//end of else if
        
    cout << "\n\nYour workout is available in the workout planner text file.\nEnjoy your workout!" << endl;

	return 0;


}
