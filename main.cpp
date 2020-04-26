#include "person.h"
#include "workout.h"
#include "athome.h"
#include "atgym.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <limits>

using namespace std;

void print(ofstream&, int);
void print(ofstream&, string);
void print(ofstream&, int, int);
void print(ofstream&, double);
void print(ofstream&, double, int, int);
void int_check(int i);



int main()
{  
    int account;
    string firstname;
    string lastname;
	int age = '\0';
	char sex = '\0';
	int feetheight = '\0';
	int inchheight = '\0';
	double weight = '\0';
	char selection = '\0';
	int dotw;
	char gym;
	char equipment;
    int user;
    int update;
    char enter;
    int up;
    int new_age;
    char new_sex;
    int new_height;
    int new_weight;
    int compare;
    int compare1;
    char proceed;
    char ready;
    vector<Person>vec;
   
    
    cout << "Welcome to the Workout Planner\n\n";
    cout << "MAIN MENU\n" << "---------------------\n" << "1. Sign in\n2. Make an account\n\n";
    
    cout << "Choice: ";
    cin >> account;
    int_check(account);
    while (account > 2) 
    {
        cout << "Enter 1 or 2 to make a selection. \nChoice: ";
        cin >> account;
        int_check(account);
    }
       
    if(account == 1)
    {
        ifstream iprofile;
        iprofile.open("profiles.txt");
        string line;
        if (iprofile.eof())
        {
            cout << "There are no profiles registered. Exit the program and try again." << endl;
            return 1;
        }
        
        while(!iprofile.eof())
        {
            Person p;
            string filefname, filelname;
            char filesex;
            int filefeet, fileinch, fileage;
            double fileweight;
            iprofile >> filefname >> filelname >> fileage >> filesex >> filefeet >> fileinch >> fileweight;
            p.set_name(filefname, filelname);
            p.set_age(fileage);
            p.set_sex(filesex);
            p.set_height(filefeet, fileinch);
            p.set_weight(fileweight);


            vec.push_back(p);
        }
        iprofile.close();
        int num_users=0;
        
        for(int i=1, l=0; l < Person::getcount(); i++, l++)
        {
            cout << i << ". ";
            num_users++;
            cout << vec[l].get_name() << '\n';
        }
    
        cout << "\nEnter the number corresponding to your name.\n";
        cout << "Choice: ";
        cin>> user;
        int_check(user);
        if (user > num_users && user < 1) 
        {
            cin.clear();
            cout << "You must enter a number corresponding to a profile \nChoice: ";
            cin >> user;
        }
       
        cout <<"\n\nWelcome back " << vec[user-1].get_name() << "!\n" << "-----------------------" << "\n1. Age: " << vec[user-1].get_age() << "\n2. Sex: " << vec[user-1].get_sex();
        cout <<"\n3. Height: " << vec[user-1].get_height() << " inches" << "\n4. Weight: " << vec[user-1].get_weight() << "\n5. BMI: " << vec[user-1].printbmi() << "\n---------------------";
    
        cout << "\n\nWhat would you like to do?\n\n1. Update my information\n2. Compare your work\n3. Plan a new workout\n\nChoice: ";
        cin >> up;
        int_check(up);
       

       if (up == 1) 
       {

            do 
            {
                cout << "\nEnter one item you would like to update (Scroll up for options): ";
                cin >> update;
                int_check(update);
                if(update == 1) 
                {
                    cout << "What is your new age? ";
                    cin >> new_age;
                    int_check(new_age);
                    vec[user-1].set_age(new_age);
                }
               
                if(update == 2) 
                {
                    cout << "What is your new Sex? ";
                    cin >> new_sex;
                    vec[user-1].set_sex(new_sex);
                }
                if(update == 3) 
                {
                    cout << "What is your new height?(in inches) ";
                    cin >> new_height;
                    int_check(new_height);
                    vec[user-1].set_height(new_height/12,new_height%12);
                }
                if(update == 4) 
                {
                    cout << "What is your new weight? ";
                    cin >> new_weight;
                    int_check(new_weight);
                    vec[user-1].set_weight(new_weight);
                }
                if(update == 5) 
                {
                    cout << "Sorry your BMI is calculated from your height and weight.\n";
                }
               
                cout << "would you like to update another item? (y/n): ";
                cin >> enter;
            } while (enter != 'n');

            //update profiles
            ofstream profileupdate;
            profileupdate.open("update.txt");
            for(int t=0;t<Person::getcount();t++)
            {
                if(t==0)
                {
                    int inches = vec[t].get_height();
                    int feet1 = inches/12;
                    int inch1 = inches%12;
                    profileupdate << vec[t].get_name() << '\t' << vec[t].get_age() << '\t' << vec[t].get_sex() << '\t' << feet1 << '\t' << inch1 << '\t' << vec[t].get_weight();
                }
                else
                {
                    int inches = vec[t].get_height();
                    int feet1 = inches/12;
                    int inch1 = inches%12;
                    profileupdate << '\n' << vec[t].get_name() << '\t' << vec[t].get_age() << '\t' << vec[t].get_sex() << '\t' << feet1 << '\t' << inch1 << '\t' << vec[t].get_weight();
                }
            }
            profileupdate.close();
            remove("profiles.txt");
            rename("update.txt", "profiles.txt");
       
            firstname = vec[user-1].get_name();
            age = vec[user-1].get_age();
            sex = vec[user-1].get_sex();
            feetheight = vec[user-1].get_height() / 12;
            inchheight = vec[user-1].get_height() % 12;
            weight = vec[user-1].get_weight();
        
            cout << "\nWould you like to update your workout? (y/n): ";
            cin >> proceed;
            if(proceed == 'y'){}
            else
            {
                cout << "Bye!";
                return 0;
            }
        }
   


        if(up == 2)
        {
            cout << "Choose a profile to compare with:\n";
            for(int i=0; i < Person::getcount(); i++)
            {
                while(i != user-1)
                {
                    cout << i+1 << ". ";
                    cout << vec[i].get_name() << '\n';
                    break;
                }
            }
            cout << "\nChoice: ";
            cin >> compare;

            cout << "\nWhat would you like to compare with " << vec[compare-1].get_name() << "?\n\n1. Age\n2. Height\n";
            cout << "\nChoice: ";
            cin >> compare1;
            if(compare1 == 1)
            {
                if(vec[user-1] < vec[compare-1])
                {
                    cout << "\nYou are older than " << vec[compare-1].get_name();
                }
                else
                {
                    cout << "\nYou are younger than " << vec[compare-1].get_name();
                }
                cout << "\nYou are " << vec[user-1].get_age() << '\n';
                cout << vec[compare-1].get_name() << " is " << vec[compare-1].get_age();
            }

            if(compare1 == 2)
            {
                if(vec[compare-1] > vec[user-1])
                {
                    cout << "\nYou are taller than " << vec[compare-1].get_name();
                }
                else
                {
                    cout << "\nYou are shorter than " << vec[compare-1].get_name();
                }

                int inches = vec[user-1].get_height();
                int feet1 = inches/12;
                int inch1 = inches%12;
                int inchesc = vec[compare-1].get_height();
                int feet2 = inchesc/12;
                int inch2 = inchesc%12;



                cout << "\nYou are " << feet1 <<"' " << inch1 << "\"" << '\n';
                cout << vec[compare-1].get_name() << " is " << feet2 << "' " << inch2 << "\"";
            }
            
            cout << "\n\nWould you like to update your workout? (y/n): ";
            cin >> proceed;
            if(proceed == 'y'){}
            else
            {
                cout << "Bye!" << endl;
                return 0;
            }
        }
   }
   Person f;
   if(account == 2)
   {
        cout << "\nEnter your first name: ";
	    cin >> firstname;
	    cout << "Enter your last name: ";
	    cin >> lastname;
	    f.set_name(firstname, lastname);
	    cout << "Enter your age: ";
	    cin >> age;
        int_check(age);
	    f.set_age(age);
	    cout << "Enter your sex (m/f): ";
	    cin >> sex;
	    f.set_sex(sex);
	    cout << "Enter your height (feet inches): ";
	    cin >> feetheight;
        int_check(feetheight);
	    cin >> inchheight;
        int_check(inchheight);
	    f.set_height(feetheight, inchheight);
	    cout << "Enter your weight (lbs): ";
	    cin >> weight;
        int_check(weight);
	    f.set_weight(weight);

         //Here we create their account in the profiles file

        ofstream profile;
        profile.open("profiles.txt", ios::app);
        profile << '\n' << firstname << '\t' << lastname << '\t' << age << '\t' << sex << '\t' << feetheight << '\t' << inchheight << '\t' << weight;
        profile.close();

        cout << "Are you ready to make your first workout planner? (y/n): ";
        cin >> ready;
    
        if(proceed == 'n'){}
        else
        {
            cout << "Bye!";
            return 0;
        }
    }


	if(up ==3)
    {
        firstname = vec[user-1].get_name();
    }
    
    cout << "\n\nWelcome " << firstname << "! What body parts would you like to add to your plan? (Enter the corresponding numbers seperated by a space. Enter '0' when you are done) \n";
	cout << "1.Triceps\n2.Biceps\n3.Quads\n4.Glutes\n5.Abdomen\n6.Back\n\nSelections: ";

	Workout w;
    atgym g;
    athome h;
	
	while(selection != '0') 
	{
		cin >> selection;
		w.set_completion(selection);
	}

	cout << "\nHow many days of the week do you want to exercise?: ";
	cin >> dotw;
    int_check(dotw);
    
    while (dotw > 7 || dotw < 1) 
    {
        cout << "\nYou must enter a number between 1 and 7"<< endl;
        cout << "How many days of the week do you want to exercise?: ";
        cin >> dotw;
    }

	w.set_dotw(dotw);

    age_check(age, w);
	cout << "\nDo you have a gym membership? (y/n): ";
	cin >> gym;
	w.set_gym(gym);

    vector <string> workouts;
    switch (gym) 
    {
    
        case 'n':
		cout << "\nDo you have gym equipment at home? (y/n): ";
		cin >> equipment;
		h.equipment(equipment);
        
        if (w.bicep == true) 
        {
            string b = h.bicep_workout();
            workouts.push_back(b);
        }
        if (w.tricep == true) 
        {
            string t = h.tricep_workout();
            workouts.push_back(t);
        }
        if (w.quad == true) 
        {
            string q = h.quad_workout();
            workouts.push_back(q);
            }
        if (w.glutes == true) 
        {
            string g = h.glutes_workout();
            workouts.push_back(g);
        }
        if (w.abdomen == true)
        {
            string a = h.abdomen_workout();
            workouts.push_back(a);
        }
        if (w.back == true) 
        {
            string back = h.back_workout();
            workouts.push_back(back);
        }
            break;
        case 'y':
        if (w.bicep == true) 
        {
            string b = g.bicep_workout();
            workouts.push_back(b);
        }
        if (w.tricep == true) 
        {
            string t = g.tricep_workout();
            workouts.push_back(t);
        }
        if (w.quad == true) 
        {
            string q = g.quad_workout();
            workouts.push_back(q);
        }
        if (w.glutes == true) 
        {
            string glutes = g.glutes_workout();
            workouts.push_back(glutes);
        }
        if (w.abdomen == true) 
        {
            string a = g.abdomen_workout();
            workouts.push_back(a);
        }
        if (w.back == true) 
        {
            string back = g.back_workout();
            workouts.push_back(back);
        }
        break;
        default:
            cout << "\nYou must enter either y or n to continue.\nExit the program and try again." << endl;
            return 1;
    }

    ofstream outfile;                    //Write to workout_planner.txt
    outfile.open("workout_planner.txt");
    outfile << "-------------------------------\n";
    print(outfile, firstname);
    outfile << "'s Info\n";
    outfile << "-------------------------------\n";
    print(outfile, age);
    print(outfile, feetheight, inchheight);
    print(outfile, weight);
    print(outfile, weight, feetheight, inchheight);
    outfile << "-------------------------------\n";
    print(outfile, firstname);
        
    outfile << "'s Workout Planner\n";
    outfile << "-------------------------------\n";
       
    if (dotw > 5)
           outfile << "With the amount of days you selected you will not have that many breaks between workouts. If you feel fatigued consider lowering the reps on the exercises";
       for (int i = 1; i <= w.get_dotw(); i++) {
           outfile << "\nDay "<< i << ": " << endl ;
           for (const auto &e : workouts)
               outfile << "\t" << e << "\n";
       }

   
    cout << "\n\nYour workout is available in the workout planner text file.\nEnjoy your workout!" << endl;
    outfile.close();
       

	return 0;
} //end of main


//polymorphism/ overloading functions
void print(ofstream &outfile, string name) {
    outfile << name;
}
void print(ofstream &outfile, int age) {
    outfile << "Age: " << age << "\n";
}
void print(ofstream &outfile, int feetheight, int inchheight) {
    outfile << "Height: " << feetheight << "' " << inchheight << "\"\n";
}
void print(ofstream &outfile, double weight) {
    outfile << "Weight: " << weight << "\n";
}
void print(ofstream &outfile, double weight, int feetheight, int inchheight) {
    double bmi = 703 * (weight/(pow(((feetheight * 12) + inchheight), 2)));
    outfile << "BMI: " << bmi << "\n";
}

//checks if user input is an integer
void int_check(int i) {
    while(true) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You must enter a number \nChoice: ";
            cin >> i;
        }
        if (!cin.fail())
            break;
    }
}
