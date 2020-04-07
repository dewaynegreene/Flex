#ifndef PERSON_H
#define PERSON_H

class Person
{
    private:
	string name;
	int age;
	char sex;
	string height;
	double weight;
	int count;
	
    protected:

    public:
	string get_name();
	void set_name();
	
}
