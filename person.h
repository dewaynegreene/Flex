#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    private:
	std::string name;
	int age;
	char sex;
	std::string height;
	double weight;
	static int count;
	//Workout Workout;
	
    protected:

    public:
	std::string get_name();
	void set_name();
	int get_age();
	void set_age(int age);
	char get_sex();
	void set_sex(char sex);
	double get_weight();
	void set_weight(double weight);
	std::string get_height();
	void set_height(std::string height);
	static int getcount();
	double bmi();
	//Person operator+(const Person& b); //Overloading operator

	
};

#endif //PERSON_H