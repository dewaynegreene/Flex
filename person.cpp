#include "person.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int Person::count = 0;

Person::Person()
{
    count++;
}

string Person::get_name()
{
    return name;
}

void Person::set_name(string fn, string ln)
{
    name = fn + " " + ln;
}

int Person::get_age()
{
    return age;
}

void Person::set_age(int a)
{
    age = a;
}

char Person::get_sex()
{
    return sex;
}

void Person::set_sex(char s)
{
    sex = s;
}

double Person::get_weight()
{
    return weight;
}

void Person::set_weight(double w)
{
    weight = w;
}

int Person::get_height()
{
    return height;
}

void Person::set_height(int feet, int inch)
{
    int h = (feet*12)+inch;
    height = h;
}

void Person::getcount(void)
{
    cout << count << endl;
}

void Person::printbmi()
{
    cout << (703 * (weight/(pow(height, 2))));
}