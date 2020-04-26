#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
    private:
	string name;
	int age;
	char sex;
	int height; // in inches
	double weight;
	static int count; //Static member variable
	//Workout Workout ;  not created yet
	
    protected:

    public:
	Person();
	string get_name();
	void set_name(string fn, string ln);
	int get_age();
	void set_age(int age);
	char get_sex();
	void set_sex(char sex);
	double get_weight();
	void set_weight(double weight);
	int get_height();
	void set_height(int feet, int inch);
	static int getcount();  //Static member function
	double printbmi();
	friend bool operator< (Person& p1, Person& p2); //friend function

	
};

#endif //PERSON_H
