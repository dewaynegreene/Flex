#include "person.h"
#include "workout.h"
#include "athome.h"
#include "atgym.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

void print(ofstream&, int);
void print(ofstream&, string);
void print(ofstream&, int, int);
void print(ofstream&, double);
void print(ofstream&, double, int, int);


int main()
{
   
    int account;
    string firstname;
    string lastname;
	int age = '\0';
	char sex;
	int feetheight = '\0';
	int inchheight = '\0';
	double weight = '\0';
	char selection = '\0';
	int dotw;
	char gym;
	char equipment;
    int user;
    char choice = 'y';
    int pick;
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
    vector<Person>vec;
    Person p;
    
   cout << "Welcome to the Workout Planner\n\n";
   cout << "MAIN MENU\n" << "---------------------\n" << "1. Sign in\n2. Make an account\n\n";
    
   cout << "Choice: ";
   cin >> account;

//    if(account == 3)
//    {
//         while(choice == 'y')
//         {
//             //Here we use the overload operator to compare.
//             cout << "\nWhat would you like to see?\n";
//             cout << "---------------------------\n";
//             cout << "1. Age";
//             cout << "\n\nChoice: ";
//             cin >> pick;
//             if(pick == 1)
//             {
//                 for(int i=0; i < vec.size(); i++)
//                 {
//                     if
//                 }
//             }
//             cout << "Would you like to see anything else? (y/n): ";
//             cin >> choice;
//         }
//         return 0;
//    }

   
   if(account == 1)
    
   {
	Person f;
    cout << "Which one is you?\n";
	
    ifstream iprofile;
    iprofile.open("profiles.txt");
    string line;

    while(!iprofile.eof())
    {
        
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
       
    for(int i=1, l=0; l < Person::getcount(); i++, l++)
    {
        cout << i << ". ";
        cout << vec[l].get_name() << '\n';
    }

    cout << "\nChoice: ";
    cin >> user;
    
    cout <<"\n\nWelcome back " << vec[user-1].get_name() << "!\n" << "-----------------------" << "\n1. Age: " << vec[user-1].get_age() << "\n2. Sex: " << vec[user-1].get_sex();
    cout <<"\n3. Height: " << vec[user-1].get_height() << " inches" << "\n4. Weight: " << vec[user-1].get_weight() << "\n5. BMI: " << vec[user-1].printbmi() << "\n---------------------";
    
       cout << "\n\nWhat would you like to do?\n\n1. Update my information\n2. Compare your work\n\nChoice: ";
       cin >> up;
       if (up == 1) {
            do {
            cout << "\nEnter one item you would like to update (Scroll up for options): ";
            cin >> update;
  
               if(update == 1) {
                    cout << "What is your new age? ";
                    cin >> new_age;
                    vec[user-1].set_age(new_age);
               }
               if(update == 2) {
                    cout << "What is your new Sex? ";
                    cin >> new_sex;
                    vec[user-1].get_sex();
               }
               if(update == 3) {
                    cout << "What is your new height?(in inches) ";
                    cin >> new_height;
                    vec[user-1].set_height(new_height/12,new_height%12);
               }
               if(update == 4) {
                    cout << "What is your new weight? ";
                    cin >> new_weight;
                    vec[user-1].set_weight(new_weight);
               }
               if(update == 5) {
                    cout << "Sorry your BMI is calculated from your height and weight./n";
               }
               
               cout << "would you like to update another item? (y/n): ";
               cin >> enter;
            } while (enter != 'n');
       }
           firstname = vec[user-1].get_name();
           age = vec[user-1].get_age();
           sex = vec[user-1].get_sex();
           feetheight = vec[user-1].get_height() / 12;
           inchheight = vec[user-1].get_height() % 12;
           weight = vec[user-1].get_weight();

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

            cout << "\nWhat would you like to compare with " << vec[compare-1].get_name() << "?\n\n1. Age\n";
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
                
                cout << "\n\nWould you like to update your workout? (y/n): ";
                cin >> proceed;
                if(proceed == 'y'){}
                else
                {
                    cout << "Bye!";
                    return 0;
                }
            }

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
    
   }

      if(account == 3)
      {
        while(choice == 'y')
        {
            //Here we use the overload operator to compare.
            cout << "\nWhat would you like to see?\n";
            cout << "---------------------------\n";
            cout << "1. Age";
            cout << "\n\nChoice: ";
            cin >> pick;
            if(pick == 1)
            {
                /*for(int i=0; i < vec.size(); i++)
                {
                    for(int j = i + 1; j < vec.size(); j++)
                    {
                        if(vec[j] < vec[i])
                        {
                            Person temp = vec[i];
                            vec[i] = vec[j];
                            vec[j] = Person temp;
                        }
                    }
                }*/


            }
            cout << "Would you like to see anything else? (y/n): ";
            cin >> choice;
        }
        return 0;
      }
   
   
   
   
   
   if(account == 2)
   {
    
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

   }
	//All this is just information about the user.
	//We can push this person to the vector of people we have created.

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

	cout << "How many days of the week do you want to exercise?: ";
	cin >> dotw;
       while (dotw > 7 || dotw < 1) {
           cout << "You must enter a number between 1 and 7"<< endl;
           cout << "How many days of the week do you want to exercise?: ";
           cin >> dotw;
       }
	w.set_dotw(dotw);

    age_check(age, w);
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
               string g = w.glutes_workout();
                workouts.push_back(g);
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
        print(outfile, firstname);
        outfile << "'s Info\n";
        outfile << "-------------------------------\n";
        print(outfile, age);
        print(outfile, feetheight, inchheight);
        print(outfile, weight);
        print(outfile, weight, feetheight, inchheight);
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

void print(ofstream &outfile, string firstname) {
    outfile << firstname;
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
